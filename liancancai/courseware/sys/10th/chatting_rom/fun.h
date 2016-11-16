#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<error.h>
#include<errno.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<time.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<syslog.h>

#define MAXFILE 65535
#define PORT 8080

struct user{
   char name[20];
   char code[32];
};


struct msg{
   int fd;
   char toname[20];
   char fromname[20];
   char info[1024];
   char message[1024];
   struct msg *next;
};
