#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit4
{
	class Base
	{
	public:
		virtual void Func1()
		{
			cout << "Base::Func1()" << endl;
		}

		virtual void Func2()
		{
			cout << "Base::Func2()" << endl;
		}

		void Func3()
		{
			cout << "Base::Func3()" << endl;
		}

	private:
		int _b = 1;
	};

	class Derive : public Base
	{
	public:
		virtual void Func1()
		{
			cout << "Derive::Func1()" << endl;
		}
	private:
		int _d = 2;
	};
	
	void func()
	{
		// 取出对象的前4个字节
		Base b1;
		printf("vftptr虚表地址:%p\n", *(int*)&b1);
		//printf("vftptr:%p\n", (int)b1); //直接转语法不接受，这里用指针转，再解引用


		int i = 0;
		int* p1 = &i;
		int* p2 = new int;
		const char* p3 = "hello";
		printf("栈变量:%p\n", p1);
		printf("堆变量:%p\n", p2);
		printf("代码段常量:%p\n", p3);
		printf("虚函数地址:%p\n", &Base::Func1);// &Base::Func1这是规定要这样才能取到函数地址
		//而普通函数的函数名就是地址
		printf("普通函数地址:%p\n", func);
		printf("普通函数地址:%p\n", &Base::Func3);//即函数前面用::指明了范围那么就需要加&才能取到函数地址
	}

	void f1(int i)
	{}

	void f1(double d)
	{}

	

	int test_bit4()
	{
		func();

		//编译时是把这个程序进行检查如语法，指令生成等等，生成的是一个可执行的文件
		//运行时是创建一个子进程，再通过esgc这样的方式把它的段给替换掉，
		//主要是替换数据段与代码段，当然还有其它一些区域，运行起来就叫做动态多态
		//平时所指的多态是动态的多态

		int i = 0;
		double d = 1.1;
		// 静态绑定 静态的多态   (静态：编译时确定函数地址)  
		f1(i);
		f1(d);

		// 动态绑定  动态的多态  （动态：运行时到虚表中找虚函数地址）
		//一般我们指的多态就是动态多态
		Base* p = new Base;
		p->Func1();
		p = new Derive;
		p->Func1();

		return 0;
	}
}