#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fun_return(void)
{
	printf ("fun_return\n");

	return 0;

	while (1);
}

void fun_exit(void)
{
	printf ("fun_exit\n");

	exit (0);

	while (1);
}

int main(void)
{

	// fun_return ();

	fun_exit ();
	while (1);

	return 0;
}
