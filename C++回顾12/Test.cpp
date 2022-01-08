#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//结构体里面可以定义：1.成员变量  2.成员函数

class Student
{
	public:
		void SetStudentInfo(const char* name, const char* gender, int age)
		{
			strcpy(_name, name);
			strcpy(_gender, gender);
			_age = age;
		}
		void PrintStudentInfo()
		{
			cout << _name << " " << _gender << " " << _age << endl;
		}
	private:
		char _name[20];
		char _gender[3];
		int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 18);
	s.PrintStudentInfo();
	//s._age=20;私有的不可访问，不写public默认私有
	return 0;
}