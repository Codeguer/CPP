#include <iostream>
using namespace std;
//协变(基类与派生类虚函数返回值类型不同)
//派生类重写基类虚函数时，与基类虚函数返回值类型不同。
//即基类虚函数返回基类对象的指针或者引用，
//派生类虚函数返回派生类对象的指针或者引用时，称为协变。
namespace bit2
{
	class Person {
	public:
		//virtual void BuyTicket() { cout << "Person:买票-全价" << endl; }
		virtual Person* BuyTicket() { cout << "Person:买票-全价" << endl; return nullptr; }
		//基类对象的指针或者引用不一定就是Person，派生类也不一定就是Student
	};
	class Student : public Person {
	public:
		//virtual void BuyTicket() { cout << "Student:买票-半价" << endl; }
		virtual Student* BuyTicket() { cout << "Student:买票-半价" << endl; return nullptr; }
	};
	void Func(Person& p)
	{
		p.BuyTicket();
	}
	void test()
	{
		Person ps;
		Student st;
		Func(ps);
		Func(st);
	}
}

namespace bit3
{
	class A {};
	class B : public A {};//如果不是继承关系下面就会报错

	class Person {
	public:
		virtual A* f() { cout << "Person:买票-全价" << endl; return nullptr; }
	};

	class Student : public Person {
	public:
		virtual B* f() { cout << "Student:买票-半价" << endl; return nullptr; }
	//B* f() { cout << "Student:买票-半价" << endl; return nullptr; }
		//注意了：派生类里面去掉了virtual，也勉强认可为多态，但不规范
		//父类的绝对不能去掉
	};

	void Func(Person& p)
	{
		p.f();
	}
	void test()
	{
		Person ps;
		Student st;
		Func(ps);
		Func(st);
	}
}