#include <iostream>
#include <string>
using namespace std;

namespace bit2
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
	public:
		void Print() { cout << "A::_a="<<A::_a << endl; }//重定义与显示访问
	protected:
		int _a = 2;
	};

	void test_bit2()
	{
		A a;
		B b;
		b.Print();
	}
}