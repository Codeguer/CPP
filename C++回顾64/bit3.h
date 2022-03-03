#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit3
{
	 class Base
	{
	public:
		virtual void Func1()
		{
			cout << "Base::Func1()" << endl;
		}

		virtual void Func2()
		{
			cout << "Base::Func2()" << endl;
		}

		void Func3()
		{
			cout << "Base::Func3()" << endl;
		}

	private:
		int _b = 1;
	};

	class Derive : public Base
	{
	public:
		virtual void Func1()
		{
			cout << "Derive::Func1()" << endl;
		}
	private:
		int _d = 2;
	};

	void test1_bit3()
	{
		Base b1;
		Base b2;
		Derive d1;
	}

	void test2_bit3()
	{
		Base b2;
		Derive d2;
	}
}