#include <iostream>
#include <string>
using namespace std;

//使用虚继承
namespace bit5
{
	class A
	{
	public:
		A() { cout << "A()" << endl; }

		int _a = 1;
	};

	class B :virtual public A
	{
	public:
		B() { cout << "B()" << endl; }

		int _b = 2;
	};

	class C :virtual public A
	{
	public:
		C() { cout << "C()" << endl; }

		int _c = 3;
	};

	class D :public B, public C
	{
	public:
		D() { cout << "D()" << endl; }

		int _d = 4;
	};

	void test_bit5()
	{
		D d;
		//显示调用看看分别从B与C继承的_a是不是同一个
		printf("%p\n", &d.B::_a);//00BCFC60
		printf("%p\n", &d.C::_a);//00BCFC60

		//现在已经没有二义性的问题了，因此可以调用
		d._a;

		cout << endl;
		printf("&d._b=%p\n", &d._b);
		printf("&d._c=%p\n", &d._c);
		printf("&d._d=%p\n", &d._d);
		printf("&d._a=%p\n", &d._a);

		//虚基表的使用是为了保证切片，公有的成员_a无法直接进行切片
		//采用了虚基表的方法来保证切片，比如将B b=d,那么公有的成员给过去
		//要保证是从B继承来的_a才能给过去，而不是从C继承来的_a，即使两者的_a
		//是同一个
	}
}