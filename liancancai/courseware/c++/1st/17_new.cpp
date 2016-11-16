#include <iostream>

using namespace std;

int main(void)
{
	char *ch  = NULL;
	char *s = NULL;
	int i;
	//申请空间
	ch =  new char;

	s = new char [128];

	//ch = (char *)malloc(sizeof(char));
	
	cout << "please input string : ";
	//cin >> *ch;

    /*
	 *cout << "ch = " << *ch << endl;
     */
	cin.getline(s, 128);

	cout << "s = " << s << endl;
	for (i = 0; i < 10; i++)
	{
		printf("s[%d] = %p\n", i, &s[i]);
		//cout << "s[" << i << "] = " << &s[i] << endl; 
	}

	//释放空间
	delete [] s;
	delete ch;
	return 0;
}
