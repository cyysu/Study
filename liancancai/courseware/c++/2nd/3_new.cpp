#include <iostream>

using namespace std;

struct cls_t{
	char name[128];
	int age;
	char sex;
};
char buf[1024];

int main(void)
{
	struct cls_t *p = NULL;

    /*
	 *p = new struct cls_t;//heap
	 *if (p == NULL)
	 *{
	 *    printf("new failed!\n");
	 *    return -1;
	 *}
     */

	p = new (buf) struct cls_t;
	strcpy(p->name, "jim");
	p->age = 20;
	p->sex = 'M';

	printf("buf = %p\n", buf);
	printf("p = %p\n", p);
	strcpy(buf, "mary");
	cout << "buf = " << buf << endl;
	printf("name = %s age = %d sex = %c\n", p->name, p->age, p->sex);

	delete p;
	return 0;
}
