#include "fun.h"



static void sig_routine(int signo){
   switch(signo){
      case SIGCHLD:
         while(waitpid(-1,NULL,WNOHANG)>0);
         break;
   }

   return ;
}


static void daemon_init(){
   int i;
   pid_t pid;


   if ( (pid=fork()) < 0) {
      exit(-1);
   } else if (pid > 0){
      _exit(0);
   }

   if(setsid()<0){
      exit(-1);
   }

   signal(SIGHUP,SIG_IGN);
   signal(SIGCHLD,sig_routine);

   if( (pid=fork()) <0 ){
      exit(-1);
   }
   else if(pid>0){
      _exit(0);
   }
   chdir("/opt/chatpro/chat");
   umask(0);

}

struct user client;


//登录验证
int anybody_login(int newfd){

   struct user users[15];
   int i;

   int flag=0;
   FILE *fp;

   recv(newfd,&client,sizeof(client),0);

   if( (fp=fopen("user.dat","r")) == NULL ){
      perror("open");
      exit(-1);
   }

   for(i=0;i<15;i++){
      fscanf(fp,"%s %s",users[i].name,users[i].code);
      //printf("%s %s\n",users[i].name,users[i].code);
      if( strcmp(client.name,users[i].name)==0 && strcmp(client.code,users[i].code)==0 ){
         flag=1;
         //break;
      }
   }

   if(send(newfd,&flag,sizeof(flag),0)<0){
      printf("send1:\n");
   }

   return flag;
}


int main(int argc, char *argv[]){
   fd_set master;
   fd_set read_fds;

   struct sockaddr_in serveraddr;
   struct sockaddr_in clientaddr;

   FILE *logsfp;

   int fdmax;
   int listener;
   int newfd;
   int onlinefd;
   int flag;

   char buf[1024];
   int nbytes;

   char onlinename[1024];    //在线名单

   int opt = 1;
   int addrlen;
   int i, j;

   //截取名字
   int k;
   int m;
   char *getname[20];
   char *q;
#if 0
   for(k=0;k<20;k++){
      getname[k]=(char *)malloc(40);
   }
#endif
   getname[0]=(char*)malloc(40);
   getname[1]=(char*)malloc(40);
   getname[2]=(char*)malloc(40);
   getname[3]=(char*)malloc(40);
   getname[4]=(char*)malloc(40);
   getname[5]=(char*)malloc(40);
   getname[6]=(char*)malloc(40);
   getname[7]=(char*)malloc(40);

   struct msg msgs;

   struct msg *head;   //链表头
   struct msg *s,*p,*t;

   struct msg out;    //退出信息
   //char getname[40];

   p=head;

   FD_ZERO(&master);
   FD_ZERO(&read_fds);

   // 创建socket
   if((listener = socket(AF_INET, SOCK_STREAM, 0)) == -1){
      perror("Server-socket()-error:");
      exit(1);
   }

   //端口重复利用
   if(setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1){
      perror("Server-setsockopt()-error:");
      exit(1);
   }

   serveraddr.sin_family = AF_INET;
   serveraddr.sin_addr.s_addr = INADDR_ANY;
   serveraddr.sin_port = htons(PORT);
   memset(&(serveraddr.sin_zero), '\0', 8);

   //绑定
   if(bind(listener, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1){
      perror("Server-bind()-error:");
      exit(1);
   }


   daemon_init();     //守护进程


   // listening
   if(listen(listener, 20) == -1){
      perror("Server-listen() error lol!");
      exit(1);
   }

   FD_SET(listener, &master);
   fdmax = listener; // so far, it's this one

   //loop
   while(1){
      read_fds = master;
      //select
      if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
         perror("Server-select()-error:");
         exit(1);
      }

      //run through the existing connections looking for data to be read
      for(i = 0; i <= fdmax; i++){
         if(FD_ISSET(i, &read_fds)){
            // we got one...
            if(i == listener){
               addrlen = sizeof(clientaddr);
               if((newfd = accept(listener, (struct sockaddr *)&clientaddr, &addrlen)) == -1){
                  perror("Server-accept()-error:");
               }else{
                  //有人登录
                  flag=anybody_login(newfd);

                  if(flag==1){
                     FD_SET(newfd, &master);      // add to master set
                     if(newfd > fdmax){           // keep track of the maximum
                        fdmax = newfd;
                     }
                     //printf("%s: New connection from %s on socket %d\n",
                     //     argv[0], inet_ntoa(clientaddr.sin_addr), newfd);

                     onlinefd=newfd;
                     //printf("onlinefd:%d\n",onlinefd);   //发fd
                     if(send(newfd,&onlinefd,sizeof(onlinefd),0)<0){
                        printf("send2:\n");
                     }
                     //创建用户链表
                     s=(struct msg*)malloc(sizeof(struct msg));
                     strcpy(s->toname,client.name);
                     s->fd=onlinefd;

                     p->next=s;

                     p=s;
                     s->next=NULL;

#if 1                    //发送登入信息
                     for(j = 0; j <= fdmax; j++){
                        // send to everyone!
                        if(FD_ISSET(j, &master)){
                           // except the listener and ourselves
                           if(j != listener && j != onlinefd ){
                              sprintf(s->message,"%s 上线了,您可以和他/她聊天了\n",s->toname);
                              if(send(j, s, sizeof(struct msg), 0) == -1)
                                 perror("send() error lol!");
                           }
                        }
                     }
#endif
                     //打印链表
                     bzero(onlinename,sizeof(onlinename));
                     strcpy(onlinename,"在线的人:");
                     for(t=head->next;t!=NULL;t=t->next){
                        sprintf(onlinename,"%s %s",onlinename,t->toname);
                        //printf("%s\n",onlinename);
                     }
                     send(onlinefd,onlinename,sizeof(onlinename),0);
                  }
               }
            }else{
               // 接受客户端信息
               if((nbytes = recv(i, &msgs, sizeof(msgs), 0)) <= 0){
                  if(nbytes == 0){
                     //发送客户下线信息
                     for(j = 0; j <= fdmax; j++){
                        // send to everyone!
                        if(FD_ISSET(j, &master)){
                           // except the listener and ourselves
                           if(j != listener && j != msgs.fd ){
                              sprintf(out.message,"%s 下线了\n",msgs.fromname);
                              if(send(j, &out, sizeof(struct msg), 0) == -1)
                                 perror("send() error lol!");
                           }
                        }
                     }
                     //printf("%s: socket %d hung up\n", argv[0], i);


                  }
                  else
                     perror("recv() error:");
                  close(i);
                  FD_CLR(i, &master);
               }
               else{
                  //printf("msg1:%s\n",msgs.message);
                  //printf("recvfd:%d\n",msgs.fd);
#if 1

                  //截取聊天用户名和信息
                  k=1;
                  if( strrchr(msgs.message,':')!=0 ){         //有:号
                     strcpy(getname[k],strtok(msgs.message,":"));
                     //printf("name1:%s\n",getname[k]);
                  }
                  k++;
                  while( q=strtok(NULL,":") ){
                     strcpy(getname[k],q);
                     //printf("name%d :%s\n",k,getname[k]);
                     k++;
                  }
                  strcpy(msgs.message,getname[k-1]);

                  //printf("%d\n",k);
#if 1
                  for(m=1;m<k-1;m++){
                     //记录聊天信息
                     char logs[2048];
                     sprintf(logs,"\n%s to %s %s %s\n",msgs.fromname,getname[m],msgs.info,msgs.message);
                     if( (logsfp=fopen("chat_logs.txt","a")) == NULL ){
                        perror("open file:");
                     }

                     fprintf(logsfp,"%s",logs);

                     fclose(logsfp);

#endif
                     //发送单人信息
                     for(t=head->next;t!=NULL;t=t->next){
                        if(strcmp(t->toname,getname[m])==0){
                           //printf("t->fd:%d\n",t->fd);
                           //printf("send:%d\n",send(t->fd,&msgs, sizeof(struct msg), 0));
                           send(t->fd,&msgs, sizeof(struct msg), 0);
                        }
                     }
                     //发送所有人信息
                     if(strcmp(getname[1],"all")==0){
                        for(j = 0; j <= fdmax; j++){
                           // send to everyone!
                           if(FD_ISSET(j, &master)){
                              // except the listener and ourselves
                              if(j != listener && j != i){
                                 //printf("%d\n",j);
                                 if(send(j, &msgs, sizeof(msgs), 0) == -1)
                                    perror("send() error lol!");
                              }
                           }
                        }
                     }
                  }
#endif
               }
            }
         }
      }
   }
   return 0;
}


