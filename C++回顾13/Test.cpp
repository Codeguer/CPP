#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//定义一个类
//封装
//1.将数据和方法定义在一起
//2.把想给你看到的数据给你看，不想给你看的封装起来->使用访问限定符
class Stack
{
public:
	//1、成员函数(的声明）
	void Push(int x);//在类里面声明，在类外面定义
	void Pop()//在类里面定义
	{
		;
	}
	void Empty();
private:
	//2、成员变量（的声明）
	int* _a;
	int _size;
	int _capacity;
};
//1、C语言中struct是用来定义结构体的
//2、C++中，兼容C的struct定义结构体的用法，但是同时struct也可以用来定义类
//3、C++中使用class和struct定义类的区别：默认的访问限定符

//C中这样定义结构体的
struct ListNod_C
{
	int _val;
	struct ListNode_C *_next;
	struct ListNode_C *_prev;
};

//C++中
struct ListNode_CPP
{
	int _val;
	struct ListNode_C *_next;//C++兼容C，这里看成用C语言定义结构体指针
	ListNode_C *_prev;//C++更喜欢这样定义类的属性或方法

	//还可以定义函数->成员函数
	ListNode_CPP* CreateNode(int val);
};

void Stack::Push(int x)//类外面定义
{
	;
}

class A//只定义了成员函数
{
	int Add(int x, int y)
	{
		return x + y;
	}
};

class B//只声明了成员变量
{
	int BVal;
};

class C//空类
{};
int main()
{
	//类实例化对象，相当于定义出了类的成员属性与成员方法
	Stack s1;
	Stack s2;
	Stack s3;
	s1.Push(1);

	//对象中只存储了成员变量，不存储成员函数
	cout << sizeof(s1) << endl;//12
	//一个类实例化出N个对象，每个对象的成员变量都可以存储不同的值，但是调用的函数是同一个
	//如果每个对象都放成员函数，而这些成员函数却是一样的，浪费空间

	//一个类实例化对象的大小，就是计数成员变量之和，并且考虑内存对齐
	//没有成员变量的类的对象大小为1，开一个字节不是为了存储数据，而是占位表示该对象存在
	A a;
	A aa;
	A aaa;
	return 0;
}