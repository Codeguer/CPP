#pragma once
#include <iostream>
#include <string>
using namespace std;
//********************************
//����������������һ����̬��Ա
//********************************

namespace bit4
{
	class Person
	{
	public:
		Person() { ++_count; }
	public:
		string _name; // ����
		static int _count; // ͳ���˵ĸ�����
	};

	int Person::_count = 0;

	class Student : public Person
	{
	protected:
		int _stuNum; // ѧ��
	};

	void test_bit4()
	{
		Person p;//_count = 1
		Person p1;//_count = 2
		Student s;//_count = 3
		p._name = "jack";
		s._name = "rose";

		p._count = 1;//_count = 1
		s._count = 2;//_count = 2

		Person::_count++;//_count = 3
		cout << Person::_count << endl;//3
		cout << Student::_count << endl;//3
		cout << p1._count << endl;//3
	}
}