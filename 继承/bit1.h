#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit1
{
	class A
	{
	public:
		void Print() { cout << "Print():" << endl; }
	protected:
		int _a = 1;
	};

	class B :public A
	{

	protected:
		int _b = 2;
	};

	void test_bit1()
	{
		
		B b;

		A a = b;
		A&c = b;
		A*d = &b;
	
		//基类的指针可以通过强制类型转换赋值给派生类的指针
		B *Bb = (B*)d;
		Bb->Print();//父类的指针指向子类的对象，这种情况是可以的

		A*Ab = &a;//父类的指针指向父类的对象，这种情况有时候会有问题
		B*Bb1 = (B*)Ab;
		Ab->Print();//可能存在越界访问
		//b=a;//父类对象不能直接赋值给子类对象
		b.Print();
		
	}
}


