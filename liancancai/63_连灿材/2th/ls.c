#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)


char *int_to_char(int num)
{
	int count = 0;
	int temp1 = 1;
	int temp2 = num;
	int i;
	char *p = NULL;
	char buf[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	while(temp1)
	{
		temp1 = temp2 / 10;
		count ++;
		temp2 = temp1;
	}
	
	p = (char *)malloc(sizeof(char) * count);

	temp2 = num;
	for(i = 0; i < count; i++)
	{
		p[count - i - 1] = buf[temp2 % 10];
		temp2 /= 10;
	}

	return p;
}

//获取文件类型
char file_type(struct stat s)
{
	mode_t m;
	m = s.st_mode;

	if(S_ISREG(m))
	{
		return '-';
	}

	if(S_ISDIR(m))
	{
		return 'd';
	}

	if(S_ISCHR(m))
	{
		return 'c';
	}

	if(S_ISBLK(m))
	{
		return 'b';
	}	

	if(S_ISFIFO(m))
	{
		return 'p';
	}

	if(S_ISLNK(m))
	{
		return 'l';
	}

	if(S_ISSOCK(m))
	{
		return 's';
	}

}

//获取文件权限
void file_permission(struct stat s)
{
	char *buf[] = { "---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
	mode_t m;
	m = s.st_mode;

	printf("%s", buf[(S_IRWXU & m) >> 6]); //uer 权限
	printf("%s", buf[(S_IRWXG & m) >> 3]); //group 权限
	printf("%s", buf[(S_IRWXO & m) ]);     //other 权限
}

//获取文件hard link数
int file_hardware_link(struct stat s)
{
	return (int)(s.st_nlink);
}

//获取uid
int file_uid(struct stat s)
{
	return (int)(s.st_uid);
}

//获取gid
int file_gid(struct stat s)
{
	return (int)(s.st_gid);
}

//将字符串按	符号分割开来
int cut_word(char *s, char *buf[7], char c)
{
	int count = 0;
	buf[count++] = s;

	while(*s != '\0')
	{
		if(*s == c)
		{
			buf[count++] = s + 1;
			*s = '\0';
		}

		s++;
	}

	return count;
}

//获取uid name
char *file_uid_name(char * path, struct stat s)
{
	char *information[7];
	FILE *fp = NULL;
	char buf[128];
	char *p = NULL;
	int count = 1;
	char *name = NULL;

	fp = fopen(path, "r");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	p = fgets(buf, sizeof(buf), fp);
	while (p != NULL)
	{
		cut_word(buf, information, ':');

		if ( atoi(information[2]) ==  file_uid(s))
		{
			name = (char *)malloc(sizeof(char) * strlen(information[0] + 1));
			strcpy(name, information[0]);
			return name;
		}
		p = fgets(buf, sizeof(buf), fp);
	}
	
	return int_to_char(file_uid(s));

ERR1:
	return ;
}

//获取gid name
char *file_gid_name(char * path, struct stat s)
{
	char *information[7];
	FILE *fp = NULL;
	char buf[128];
	char *p = NULL;
	int count = 1;
	char *name = NULL;

	fp = fopen(path, "r");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	p = fgets(buf, sizeof(buf), fp);
	while (p != NULL)
	{
		cut_word(buf, information, ':');

		if ( atoi(information[2]) ==  file_gid(s))
		{
			name = (char *)malloc(sizeof(char) * strlen(information[0] + 1));
			strcpy(name, information[0]);
			return name;
		}

		p = fgets(buf, sizeof(buf), fp);
	}
	
	return int_to_char(file_gid(s));

ERR1:
	return ;
}

//获取文件大小
int file_size(struct stat s)
{
	return (s.st_size);
}

//测试stat
int main(int argc, char const *argv[])
{
	struct stat s;
	int ret;
	mode_t m;
	FILE *fp = NULL;
	char buf[128];
	char *p = NULL;
	char *information[7];
	int count, i;

	fp = fopen("/etc/passwd", "r");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	ret = lstat(argv[1], &s);

	printf("%c", file_type(s));
	file_permission(s);
	
	printf(" %d", file_hardware_link(s));

	printf(" %s", file_uid_name("/etc/passwd", s));
	printf(" %s", file_gid_name("/etc/group", s));

	if (file_size(s) >= (1024 * 1024 * 1024))
	{
		printf(" %.2lfG", (double)file_size(s) / (1024 * 1024 * 1024));
	}
	else if (file_size(s) >= (1024 * 1024))
	{
		printf(" %.2lfM", (double)file_size(s) / (1024 * 1024));
	}
	else if (file_size(s) >= 1024)
	{
		printf(" %.2lfK", (double)file_size(s) / 1024 );
	}
	else
	{
		printf(" %d", file_size(s));
	}

	putchar(10);
	       
	fclose(fp);
	
	return 0;
ERR1:
	return -1;
}
