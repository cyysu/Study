#ifndef __SHARE_H__
#define __SHARE_H__

#define GETLINES(string, buf, size) do{							\
						printf(string);						\
						fgets(buf, size, stdin);		\
						if (buf[strlen(buf) - 1] == '\n')	\
							buf[strlen(buf) - 1] = '\0';	\
					}while(0) 
	
#define ERRP(con, func, ret) do{					\
							if (con)				\
							{						\
								printf(func" failed\n");		\
								ret;				\
							}						\
						}while(0)

#endif /*SHARE_H*/
