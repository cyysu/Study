#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERRP(con, func, ret) do{					\
							if (con)				\
							{						\
								printf(func);		\
								ret;				\
							}						\
						}while(0)
int main(void)
{
	int ***p = NULL;

	p = (int ***)malloc(sizeof(int **));
	ERRP(NULL == p, "malloc p failed!\n", goto ERR1);
    /*
	 *if (p == NULL)
	 *{
	 *    printf("malloc p failed!\n");
	 *    return -1;
	 *}
     */

	*p = (int **)malloc(sizeof(int *));
	ERRP(*p == NULL, "malloc *p failed!\n", goto ERR2);
    /*
	 *if (*p == NULL)
	 *{
	 *    printf("malloc *p failed!\n");
	 *    free(p);
	 *    return -1;
	 *}
     */

	**p = (int *)malloc(sizeof(int));
	**p = NULL;
	ERRP(**p == NULL, "malloc **p failed!\n", goto ERR3);
    /*
	 *if (**p == NULL)
	 *{
	 *    printf("malloc **p failed!\n");
	 *    free(*p);
	 *    free(p);
	 *    return -1;
	 *}
     */
	return 0;
ERR3:
	free(*p);
	printf("free *p\n");
ERR2:
	free(p);
	printf("free p\n");
ERR1:
	printf("return !\n");
	return -1;
}
