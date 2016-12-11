#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
	int i, num;
	Stack st;
	char ch;

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
				if (st.is_full())
				{
					cout << "stack is full" << endl;
					continue;
				}
				cout << "please input number : ";
				cin >> num;
				cin.get();
				
					st.push(num);
				break;
			case 'B':
			case 'b':
				if (st.is_empty())
				{
					cout << "stack is empty! " << endl;
					continue;
				}
				else
				{
					st.pop(num);
					cout << "pop : " << num << endl;
				}
				break;
			case 'C':
			case 'c':
				cout << "exit" << endl;
				goto loop;
		}
	}
loop:
	return 0;
}
