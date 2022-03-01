#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit1{
	class Person{
	public:
		Person(const char* name = "peter")
			: _name(name)
		{
			cout << "Person()" << endl;
		}

		Person(const Person& p)
			: _name(p._name)
		{
			cout << "Person(const Person& p)" << endl;
		}

		Person& operator=(const Person& p)
		{
			cout << "Person operator=(const Person& p)" << endl;
			if (this != &p)
				_name = p._name;

			return *this;
		}

		~Person()
		{
			cout << "~Person()" << endl;
		}
	protected:
		string _name; // 姓名
	};


	class Student : public Person
	{
	public:
		Student(const char* name = "坏蛋", int stuid = 520)
			:_name(name)//不允许这样初始化从父类继承的成员，会报错
			//_name(name)这样的话就是在初始化自己的_name（即子类自己写了一个_name与父类的_name构成隐藏了）
			//而不是初始化从父类继承下来的_name
			//但是必须要先调用父类的构造函数初始化父类的那一部分成员
			//:Person(name)//当父类有对应的默认构造函数时可以不写，系统会自动调用父类的构造函数进行初始化
			:Person(name)//在初始化列表中，该语句不论放在哪个位置都是先被调用
			, _stuid(stuid)
			//, Person(name)//如果显示调用的话一定要写在初始化列表中
		{
			cout << "Student()" << endl;
		}

		Student(const Student& s)//拷贝构造
			//:_name(s._name)//这样是不行的,必须调用基类的拷贝构造完成基类的拷贝初始化
			:Person(s)//子类对象可以传给父类
			, _stuid(s._stuid)
		{
			cout << "Student(const Student& s)" << endl;
		}

		//s1=s3
		Student& operator=(const Student& s)
		{
			if (this != &s)
			{
				//operator=(s);//这里调用了自己的operator=，形成了递归
				Person::operator=(s);
				_stuid = s._stuid;
				cout << "Student& operator=(const Student& s)" << endl;

			}

			return *this;
		}

		~Student()//子类的析构函数和父类的析构函数构成隐藏，因为他们的名字会被编译器统一处理成destructor（跟多态有关）
		{
			//~Person()://不能这样写，这里调用的是自己的析构
			Person::~Person(); //这一步是多余的，正确的用法是这里不需要你显示调用，结束后自动调用父类，不然就多调用了一次父类的析构函数

			cout << "~Student()" << endl;
		}
	protected:
		int _stuid;//内置类型不做处理
		const char* _name;
	};

	void test_bit1()
	{
		Student s;
		//Student s1("jack", 1);
		//Student s2(s1);

		//Student s3("rose", 2);

		//s1 = s3;
	}
}

