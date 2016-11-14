#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int ret;
	char buf[8];

	system("stty -echo");
	system("stty -icanon");

	system("clear");
	while(1)
	{
		ret = read(0, buf, sizeof(buf));
		if (ret == -1)
		{
			return -1;
		}
		else if (buf[0] == 27 && ret == 1)
		{
			break;
		}
		else if (buf[0] == 'w' || buf[2] == 65)
		{
			printf("\033[A");
		}
		else if (buf[0] == 115 || buf[2] == 66)
		{
			printf("\033[B");
		}
		else if (buf[0] == 100 || buf[2] == 67)
		{
			printf("\033[C");
		}
		else if (buf[0] == 97 || buf[0] == 65 || buf[2] == 68)
		{
			printf("\033[D");
		}
		else
		{
			putchar(buf[0]);
		}
		fflush(NULL);
		memset(buf, 0, sizeof(buf));
	}
	system("stty echo");
	system("stty icanon");
	return 0;
}
