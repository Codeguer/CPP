#include <iostream>
#include <string>
using namespace std;

namespace bit3
{
	class A
	{
	public:
		A(int a = 1) :_a(a) { cout << "A()" << endl; }
		A(const A&p) :_a(p._a) { cout << "A(const A&p)" << endl; }
		A operator=(const A&p) { cout << "A operator=" << endl; return *this; }
		void Print() { cout << "Print():" << endl; }
		~A() { cout << "~A" << endl; }
	protected:
		int _a;
	};

	class B :public A
	{
	public://当父类有构造函数时子类可以不用调用，系统会自动调用父类的
//当父类没有对应的构造函数子类的构造函数一定要调用父类的构造函数
		//且优先调用父类的构造函数，这是要在初始化列表中进行的
		B(int b = 4) :A(3), _b(b) { cout << "B()" << endl; }

		//子类的拷贝构造函数必须调用父类的拷贝构造函数
		B(const B&p) :_b(p._b),A(p) { cout << "B(const B&p)" << endl; }

		B operator=(const B&p) { A::operator=(p); _b = p._b; cout << "B operator=" << endl; return *this; }
		//子类的析构函数先调用，调用完成后然后自动调用父类的析构函数
		~B() { cout << "~B()"<< endl; }
	protected:
		int _b = 2;
	};

	void test_bit3()
	{
		B b;
		B Bb = b;
		b = Bb;
	}
}