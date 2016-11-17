#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	//   isalnum()   :表示字符如果是字母或者数组，则为真(true)
 // 67     isalpha()   :判断字符是不是字母
 // 68     isdigit()   :判断是否是数字字符
 // 69     islower()   :判断是否是小写
 // 70     isupper()   :判断是否是大写
 // 71     ispunct()   :判断是否是标点符号
 // 72     isspace()   :判断是否是空白字符(空格 换行符 制表符 回车)
 // 73     tolower()   :表示大写转换成小写
 // 74     toupper()   :表示小写转换成大写
	string str;
	int i;
	int digit = 0, alpha = 0, punct = 0, space = 0, other = 0;

	cout << "please input a string: ";
	getline(cin, str);

	for (i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			digit ++;
		}
		else if (isalpha(str[i]))
		{
			alpha ++;
		}
		else if (ispunct(str[i]))
		{
			punct ++;
		}
		else if (isspace(str[i]))
		{
			space ++;
		}
		else
		{
			other ++;
		}
	} 

	cout << "digit = " << digit << endl;
	cout << "alpha = " << alpha << endl;
	cout << "punct = " << punct << endl;
	cout << "space = " << space << endl;
	cout << "other = " << other << endl;


	return 0;
}