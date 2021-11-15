#include <iostream>
#include <string>
using namespace std;

namespace bit4
{
	class A
	{
	public:
		A(){ cout << "A()" << endl; }

		int _a=1 ;
	};

	class B :public A
	{
	public:
		B(){ cout << "B()" << endl; }

		int _b = 2;
	};

	class C :public A
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

	void test_bit4()
	{
		D d;
		//d._a;//d��������_a���������ò���ȷ

		//��ʾ���ý��������ԣ���������û�취���
		printf("%p\n", &d.B::_a);//00DFFB14
		printf("%p\n", &d.C::_a);//00DFFB1C

	}
}