#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Student {
private:
	char name[128];
	int age;
	char sex;
	double result;
	static int num;
public:
	Student (void){};
	Student(const char *name, int age, char sex = 'N', double result = 0.0);
	~Student(void){};
	void show(void) const;
	int set_student(const char *name, int age, char sex, double result = 0.0);
	void write_student(ostream & fout);
};

// int Student::num = 0;

#define MAX 100

#endif
