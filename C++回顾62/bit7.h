#include <iostream>
#include <string>
using namespace std;

//内存对象模型（对象在内存中是怎么存的？）
//通过内存窗口进行调试
namespace bit7
{
	class A
	{
	public:
		//int _a[10000];
		int _a;
	};

	class B :virtual public A
	{
	public:
		int _b;
	};

	class C :virtual public A
	{
	public:
		int _c;
	};

	class D : public B, public C
	{
	public:
		int _d;
	};

	void test_bit7()
	{
		D d;
		cout << sizeof(d) << endl; // 24

		d.B::_a = 1;
		d.C::_a = 2;
		d._b = 3;
		d._c = 4;
		d._d = 5;
		d._a = 6;

		B b;
		b._a = 10;
		b._b = 11;
		C c;
		c._a = 11;
		c._c = 12;

		b = d;
		c = d;
	}
}