#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit3
{
	//友元关系不能被继承，也就是说Person的友元类Display不是Student的友元函数
	class Student;
	class Person
	{
	public:
		friend void Display(const Person& p, const Student& s);
	protected:
		string _name; // 姓名
	};

	class Student : public Person
	{
		friend void Display(const Person& p, const Student& s);//加上这句
	protected:
		int _stuNum; // 学号
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