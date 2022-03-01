#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit3
{
	//��Ԫ��ϵ���ܱ��̳У�Ҳ����˵Person����Ԫ��Display����Student����Ԫ����
	class Student;
	class Person
	{
	public:
		friend void Display(const Person& p, const Student& s);
	protected:
		string _name; // ����
	};

	class Student : public Person
	{
		friend void Display(const Person& p, const Student& s);//�������
	protected:
		int _stuNum; // ѧ��
	};

	void Display(const Person& p, const Student& s)
	{
		cout << p._name << endl;
		cout << s._stuNum << endl;
	}

	void test_bit3()
	{
		Person p;
		Student s;
		Display(p, s);
	}
}