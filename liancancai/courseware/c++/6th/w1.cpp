#include <iostream>
#include <fstream>

using namespace std;

struct cls_t{
	char name[128];
	int age;
	char sex;
	double result;
};

int main(void)
{
	cls_t cls = {"jim", 18, 'M', 88.88}, stu;
	
	fstream fout;
	fstream fin;

	#if 0
	fout.open("./test", ios_base::out | ios_base::trunc | ios_base::binary);
	fout << cls.name << ":" << cls.age << ":" << cls.sex << ":" << cls.result;
	//fout.write((char *)&cls,sizeof(cls));

	
	fout.close();
	#else
	fin.open("./test", ios_base::in);
	//fin.read((char *)&stu, sizeof(stu));
	//fin >> stu.name >> ":" >> stu.age >> ":" >> stu.sex >> ":" >> stu.result;
	fin >> stu.name >> stu.age >> stu.sex >> stu.result;
	cout << "name : " << stu.name << "  age : " << stu.age
		<< "  sex : " << stu.sex << "  result : " << stu.result << endl;

	fin.close();
	#endif
	return 0;
}
