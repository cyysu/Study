#include <iostream>

using namespace std;

int main(void)
{
	bool ok = true;
	bool no = false;

	cout << "ok = " << ok << endl;
	cout << "no = " << no << endl;
	cout.setf(ios_base::boolalpha);//设置
	cout << "ok = " << ok << endl;
	cout << "no = " << no << endl;


	cout.unsetf(ios_base::boolalpha);//取消：wq
	cout << "ok = " << ok << endl;
	cout << "no = " << no << endl;
	return 0;
}
