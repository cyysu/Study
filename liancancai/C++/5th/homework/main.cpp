#include "file.h"

int main(int agrc, char * argv[])
{
	Student stu[10];
	int i;
	char buf[10] = {};
	ofstream fout;

	fout.open("./test", ios::binary);

	if(!fout)
	{
		cout << "open failed " << endl;
		return 0;
	}

	for (i = 0; i < 10; i++)
	{
		snprintf(buf, sizeof(buf), "Stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		stu[i].set_student(buf, rand() % 5 + 18 , "MF"[rand() % 2], rand() % 30 + 60.5);
	}

	for (i = 0; i < 10; i++)
	{
		stu[i].show();
		stu[i].write_student(fout);
	}

	return 0;
}
