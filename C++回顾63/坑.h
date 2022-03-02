#include <iostream>
#include <string>
using namespace std;

namespace bit5
{
	class A
	{
	public:
		virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
		virtual void test() { func(); }
	};
	class B : public A
	{
	public:
		void func(int val = 0) { std::cout << "B->" << val << std::endl; }
		//这里对虚函数进行了重写，但是要注意的是仅仅是对函数体中的内容进行了重写
		//其它不变，因此这里的val给什么缺省值都是没有用的
	};
	void test_bit5()
	{
		B*p = new B;
		p->test();//第一步：因为test()没有被重写，所以直接继承，然后调用自己的func()
		
	}
}



