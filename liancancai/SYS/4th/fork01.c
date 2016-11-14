#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <crypt.h>
#include <time.h>
#include <dirent.h>


int main(int argc, char **argv)
{
	int i=0;  
    printf("i son/pa ppid pid  fpid\n");  
    //ppid指当前进程的父进程pid  
    //pid指当前进程的pid,  
    //fpid指fork返回给当前进程的值  	
    for(i=0;i<2;i++)
    {  
       pid_t fpid=fork();  
       if(fpid==0)  
           printf("%d child  %4d %4d %4d\n",i,getppid(),getpid(),fpid);  
       else  
           printf("%d parent %4d %4d %4d\n",i,getppid(),getpid(),fpid);  
    }   
    sleep(1);
    return 0;

}
