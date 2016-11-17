#include <iostream>

using namespace std;

void refer(const double & a)
{
	printf("refer : &a = %p\n", &a);
}

int main(void)
{
	double d = 3.44;
	double *p = &d;
	double dr[5] = {1,2,3,4,5};
	long l = 5L;

    /*
	 *printf("=============\n");
	 *printf("main : &d = %p\n", &d);
	 *refer(d + 4.32);
     */
	printf("=============\n");
	printf("main : &l = %p\n", &l);
	refer(double (l));
	


/*
 *    printf("=============\n");
 *    printf("main : &d = %p\n", &d);
 *    refer(d);
 *    printf("=============\n");
 *    printf("main : &d = %p\n", &d);
 *    refer(*p);
 *    printf("=============\n");
 *    printf("main : &dr = %p\n", &dr[1]);
 *    refer(dr[1]);
 *
 *    printf("=============\n");
 *    printf("main : &d = %p\n", &d);
 *    refer(3.44);
 */
	return 0;
}
