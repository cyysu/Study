#include <iostream>

using namespace std;

#define NUM 2

char buf[1024];

int main(void)
{
	string *p = NULL;
	string *tmp1 = NULL;
	string *tmp2 = NULL;
	int i;

	for (i = 0; i < NUM; i++)
	{
		p = new (buf) string ;

		cout << "please input a string :";
		getline(cin, p[i]);

		tmp1 = p;
		p += p->size();
		tmp2 = p;
	}

	for (i = 0; i < NUM; i++)
	{
		cout << p[i] << endl;
	}

}