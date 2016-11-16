#include "fun.h"

#define MAXBUFF 1024

void client_login(int sockfd,int *onlinefd,char *username,char *onlinename){
   //登录验证
   struct user me;     //用户密码的结构体
   struct user ret;
   int flag=0;        //1为成功，0为失败

   printf("============欢迎使用＊＊聊天系统==============\n");
   printf("\t请输入用户名:");
   fgets(me.name, sizeof(me.name), stdin);
   me.name[strlen(me.name) - 1] = '\0';
   printf("\t请输入密码:");
   fgets(me.code, sizeof(me.code), stdin);
   me.code[strlen(me.code) - 1] = '\0';
   printf("正在登录,请稍等...\n");

   send(sockfd,&me,sizeof(struct user),0);
   recv(sockfd,&flag,sizeof(int),0);

   if(flag==1){
      strcpy(username,me.name);

      recv(sockfd,&onlinefd,sizeof(onlinefd),0);    //接fd

      sleep(1);
      system("reset");
      printf("登录成功\n");
      printf("%s 你好!欢迎您的加入!使用前请认真阅读使用说明!\n",username);

   }
   else if(flag==0){
      printf("您的用户名或密码有误,请重新登录!\n");
      printf("如果还不行,请联系管理员!\n");
      exit(0);
   }

   printf("===================使用说明=============================\n");
   printf("单人聊天模式->格式为  聊天对象名:聊天内容\n");
   printf("多人聊天模式->格式为 聊天对象名:聊天对象名:...聊天对象名:聊天内容\n");
   printf("所有在线人聊天模式－>格式为  all:聊天内容\n");
   printf("退出聊天－>  quit\n");
   printf("开始你的聊天吧，祝您聊的愉快...\n\n");

   recv(sockfd,onlinename,1024,0);

}

int main(int argc,char *argv[]){

   int sockfd;
   int onlinefd;

   int retval,y,maxfd =-1;
   char username[20];
   char buffer[MAXBUFF];
   char tim[50];
   char onlinename[MAXBUFF];

   socklen_t len;
   struct tm *ptm;
   time_t ts;
   fd_set rfds,listen_rfds;

   struct sockaddr_in server_addr;
   struct hostent *host;
   struct timeval tv,tv_listen;
   int portnumber,nbytes;
   tv.tv_sec = 1;
   tv.tv_usec = 0;

   struct msg msgs;       //信息结构体

   if(argc!=2){                              //客户端运行说明
      printf("用法：<命令> <IP地址>\n");
      exit(0);
   }

   if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1){
      printf("creat socket error!\n");
      exit(1);
   }

   bzero(&server_addr,sizeof(struct sockaddr_in));
   server_addr.sin_family = AF_INET;
   inet_aton(argv[1],&server_addr.sin_addr);
   server_addr.sin_port = htons(PORT);

   if((connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr)))==-1){
      printf("Connected Error:%s\n",strerror(errno));
      exit(1);
   }

   //调用客户端登录
   client_login(sockfd,&onlinefd,username,onlinename);
   printf("%s\n",onlinename);

   while(1){
      FD_ZERO(&rfds);
      // 添加标准输入
      FD_SET(0,&rfds);
      maxfd=0;
      //添加sockfd
      FD_SET(sockfd,&rfds);
      if(sockfd>maxfd)
         maxfd=sockfd;
      // set the max wait time

      retval = select(maxfd+1,&rfds,NULL,NULL,&tv);
      if(retval==-1){
         printf("select error:%s\n",strerror(errno));
         exit(1);
      }
      else if(retval == 0){
         continue;
      }
      else{
         if(FD_ISSET(sockfd,&rfds)){
#if 1
            bzero(&msgs,sizeof(msgs));
            len = recv(sockfd,&msgs,sizeof(struct msg),0);
            if(len > 0){
               //printf("\nuser %s :%s at %d\n",inet_ntoa(server_addr.sin_addr),buffer,ntohs(server_addr.sin_port));
               printf("%s",msgs.info);
               printf("%s\n",msgs.message);

#if 0
               //ftp
               if(strstr(msgs.message,"ftp get")==0){



               }
#endif
            }
            else{
               if(len < 0) printf("receive error %s",strerror(errno));
               else{
                  printf("对不起，服务器出问题了\n");
                  printf("我们正在抢修，很抱歉给您造成麻烦了\n");
               }
               break;
            }
#endif
         }

         //标准输入
         if(FD_ISSET(0,&rfds)){
            //user input message
            bzero(buffer,MAXBUFF);
            bzero(&msgs,sizeof(struct msg));
            fgets(buffer,MAXBUFF,stdin);
            msgs.fd=onlinefd;
            strcpy(msgs.fromname,username);       //拷贝发送者

            //客户下线
            if(!strncasecmp(buffer,"quit",4)){
               send(sockfd,&msgs,sizeof(struct msg),0);
               printf("谢谢使用...\n");
               break;
            }
#if 1
            ts=time(NULL);
            ptm = localtime(&ts);

            //格式化时间 信息
            sprintf(tim,"(%d-%d-%d %02d:%02d:%02d):",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
            sprintf(msgs.info,"\n%s %s\n",username,tim);
            strcpy(msgs.message,buffer);

            printf("%s",msgs.info);
            printf("%s\n",msgs.message);
            len = send(sockfd,&msgs,sizeof(msgs),0);
            //printf("sendfd:%d",msgs.fd);   //重点

            if(len>0) ;//发送成功
            else{
               printf("send error!%s",strerror(errno));
               break;
            }
#endif
         }
      }
   }

   close(sockfd);
   exit(0);
}

