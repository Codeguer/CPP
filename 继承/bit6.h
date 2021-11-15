#include <iostream>
#include <string>
using namespace std;

namespace bit6
{
	class A
	{
	public:
		 A() {};
		 A(const A&p)
		{
			//_a = p._a;
			 _a = 50;
			cout << "A&operator=(const A&p)" << endl;
		}

		void Print() { cout << "Print():" << endl; }

		int _a = 1;
	};

	class B :public A
	{
	public:
		void Print() { cout << "A::_a=" << A::_a << endl; }//重定义与显示访问
		int _b = 2;
	};

	void test_bit6()
	{
		A a;
		B b;
		b._a = 10;
		b._b = 20;
		B c = b;
		//子类并没有写拷贝构造函数，编译系统在必要的时候自动生成了
		//一个隐含的拷贝构造函数，会自动调用父类的拷贝构造函数，完成继承的成员的拷贝
		//然后该隐含的拷贝构造函数完成子类新增成员的拷贝

		b.Print();
	}
}