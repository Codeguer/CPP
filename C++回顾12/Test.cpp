#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//�ṹ��������Զ��壺1.��Ա����  2.��Ա����

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
	s.SetStudentInfo("Peter", "��", 18);
	s.PrintStudentInfo();
	//s._age=20;˽�еĲ��ɷ��ʣ���дpublicĬ��˽��
	return 0;
}