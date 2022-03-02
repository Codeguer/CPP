#include <iostream>
#include <string>
using namespace std;

//1、修饰类，表明类不可被继承，这是C++11的做法
//类不可被继承的方法还可以用private将构造函数变为私有这是C++98的做法
//2、修饰虚函数，表明该虚函数不可被继承
//3、修饰普通函数，表明该函数不可被继承

class A //final
{
public:
	//virtual void func(int val = 1) final{ std::cout << "A->" << val << std::endl; }
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};
class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
void test_bit5()
{
	B*p = new B;
	p->test();
}