#include <iostream>
#include <string>
using namespace std;

//内存对象模型（对象在内存中是怎么存的？）
//通过内存窗口进行调试
namespace bit6
{
	class A
	{
	public:
		//int _a[10000];//假如基类中的成员很大，那么虚继承就能节省很多空间
		int _a;
	};

	class B : virtual public A
	{
	public:
		int _b;
	};

	class C : virtual public A
	{
	public:
		int _c;
	};

	class E
	{
	public:
		int _a;
	};

	class D : public B, public C,public E
	{
	public:
		int _d;
	};

	/*class D : public B, public C
	{
	public:
		int _d;
	};*/

	void test_bit6()
	{
		D d;
		cout << sizeof(d) << endl;   

		d.B::_a = 1;
		d.C::_a = 2;
		d.E::_a = 3;
		d._b = 4;
		d._c = 5;
		d._d = 6;
		

		B b;
		C c;
		E e;
		//因为没有虚拟菱形继承那么可以直接找到对应的_a然后切过去
		b = d;//将从B继承来的_a切给了b
		c = d;//将从C继承来的_a切给了c
		e = d;//将从E继承来的_a切给了c
		//用了虚拟菱形继承那么在d对象中_a只有两份，这两份究竟是从谁哪里继承来的
		//通过虚基表便能找到
	}
}