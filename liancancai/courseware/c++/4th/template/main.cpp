#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
	int i, num;
	Stack<int> st;
	Stack<string> se;
	string str;
	char ch;
	char *p;


/*
 *    memset(str, 0, sizeof(str));
 *
 *    printf("hello");
 */


	//cout << "str.size() = " << str.size() << endl;
	for (i = 0; i < 10 + 3; i++)
	{
		num = rand() % 100;
		st.push(num);
	}

	st.show();

	printf("num = %d\n", num);
	st.pop(num);
	printf("num = %d\n", num);


	while(1)
	{
		cout << "================" << endl
				<< "push : A or a " << endl
				<< "pop : B or b " << endl
				<< "exit : C or c " << endl;
		cin.get(ch).get();
		//cout << "ch = " << ch << endl;;
		switch (ch)
		{
			case 'A':
			case 'a':
				if (se.is_full())
				{
					cout << "stack is full" << endl;
					continue;
				}
				cout << "please input string : ";
				getline(cin, str);
				cout << "str = " << str << endl;
				//cin.get();
				
					se.push(str);
				break;
			case 'B':
			case 'b':
				if (se.is_empty())
				{
					cout << "stack is empty! " << endl;
					continue;
				}
				else
				{
					se.pop(str);
					cout << "pop : " << str << endl;
				}
				break;
			case 'C':
			case 'c':
				cout << "exit" << endl;
				goto loop;
		}
		se.show();
	}

loop:
	return 0;
}
