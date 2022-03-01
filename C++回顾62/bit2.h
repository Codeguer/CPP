#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit2
{

	//如何设计一个不能被继承的类？
	class A//A无法被继承
	{
	private:
		A()
		{}
	};

	class B : public A//因为需要先调用基类的构造函数，但是基类的构造函数又不可见因此B类生成不了对象
	{};

	void test_bit2()
	{
		//B b;
	}

}