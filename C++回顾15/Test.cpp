#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
//问：this指针存在进程地址空间的哪个区域
//答：this指针存在栈上的，因为它是一个形参
//this一般是存在栈上的，VS进行了优化，对象是直接通过寄存器ecx进行传递的，linux可能是存在栈上
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
	int Add(int x, int y)
	{
		return x + y;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	//p->PrintA();这里崩溃了，因为传进去后this->_a;进行了空指针的访问
	//p->PrintA(p);
	p->Show();//这里没问题
	//仅仅用p去调用PrintA()与Show()是没有问题的，因为这两个函数是存放在类中的，没有去访问
	//空指针p,调用成员变量才会对对象进行访问
	p->Add(3, 5);
	return 0;
}
