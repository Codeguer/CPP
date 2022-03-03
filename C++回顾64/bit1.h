#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace bit1
{
	class Base
	{
	public:
		virtual void Func1()
		{
			cout << "Func1()" << endl;
		}

		virtual void Func2()
		{
			cout << "Func2()" << endl;
		}

		void Func3()//普通函数放在了代码段
		{
			cout << "Func3()" << endl;
		}
	private:
		int _b = 1;
	};


	int test_bit1()
	{
		cout << sizeof(Base) << endl;//8,多了一个指针，该指针为_vftptr,指向一个虚函数表
		//指针全称为虚函数表指针，简称虚表指针
		//虚函数表存放虚函数的地址，虚函数表本质就是一个函数指针数组

//为什么不把虚函数直接放到对象里去呢？因为对象一般不存放普通函数与虚函数，
//为了实现多态往对象里塞虚函数的话可能不止一个虚函数，就会使对象过大，从而效率降低
		//为了防止对象过大，就用了指针指向一个虚函数表
		Base b;

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		return 0;
	}
}
