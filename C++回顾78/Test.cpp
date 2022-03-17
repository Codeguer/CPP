#include <iostream>
#include <string>
using namespace std;
void test1()
{
	int i = 1;
	double d = 8.88;
	i = d;//类型转换 c语言支持相近类型的隐式类型转换(相近类型，也就是意义相似的类型）
	cout << i << endl;//比如整型与浮点型都是表示数据的大小，不过是带不带精度的问题

	int *p = nullptr;
	p = (int*)i;//c语言支持不相近类型的强制类型转换（不相近类型，也就是意义差别很大的类型）
	cout << p << endl;//指针是一个地址，而整型表示数据的大小

	//C++兼容C语言的隐式转换和显示转换，但是C++觉得C语言做的不规范，C++想规范一下
	/*标准C++为了加强类型转换的可视性，引入了四种命名的强制类型转换操作符：
	static_cast、reinterpret_cast、const_cast、dynamic_cast*/
	d = static_cast<double>(i);//对应C语言的隐式类型转换（相近类型）
	p = reinterpret_cast<int*>(i);//对应C语言大部分强制类型转换（不相近类型）
	//  [riːɪnˈtəːprɪt]重新解释; 给…以新的说明
	const int ci = 10;
	//volatile const int ci = 10;//加了volatile便可以防止编译器优化，每次到内存中去取
	int*pi = const_cast<int *>(&ci);// 对应C语言强制类型转换（不相近类型），去掉const属性
	//当然，依然可以用int* p1=(int*)&ci;
	*pi = 20;
	cout << *pi << endl;//20
	cout << ci << endl;//10,这里打印是10是因为ci存储的内容被改了，但是ci被放进了
//寄存器，这里去寄存器去取，还是10，本质这是由于编译器对const对象存取优化机制导致
	//想要禁止编译器做这个优化，每次都到内存中去取值，就把volatile加上

}
class A
{
public:
	virtual void f()
	{}

	int _a;
};

class B :public A
{
public:
	int _b;
};

void f_cast(A* pa)
{
	// 如果想区分pa是指向父类，还是子类对象？
	// 如果pa是指向子类对象，则转换成功，
	// 如果pa指向父类对象则转换失败返回nullptr 
	B* pb = dynamic_cast<B*>(pa);//转化失败返回nullptr
	//B* pb = (B*)pa;//用C语言的这个不行，因为若是pa是指向父类的，那么父类是没有_b的
	if (pb != nullptr)
	{
		cout << "转换成功：pa指向子类对象" << endl;
		pb->_a = 1;
		pb->_b = 2;
	}
	else
	{
		cout << "转换失败：pa指向父类对象" << endl;
	}
}

void test2()
{
	A a;
	B b;
	//C++中子类对象可以赋值给父类的对象、指针、引用，这个过程中会发生切片，这个过程
	//是语法天然支持的，这个叫向上转换

	//如果是父类的指针或者引用，传给子类的指针，这个过程叫向下转换，这个过程
	//有可能成功要看具体情况。
	//最后需要注意的是：dynamic_cast向下转换只能针对继承中的多态类型（父类必须
	//包含虚函数）
	// 因为dynamic_cast如何识别父类的指针是指向父类对象还是子类对象的呢？
	//dynamic_cast的原理
	// dynamic_cast通过去虚表的上方存储的标识信息，来判断指向父类对象还是子类对象。

	A* pa = &a;
	f_cast(pa);

	pa = &b;
	f_cast(pa);
}

class AA
{
public:
	//AA(int a)
	 AA(int a)//explicit AA(int a)
	{
		cout << "AA(int a)" << endl;
	}

	//AA(int a1, int a2)
	 AA(int a1, int a2)//explicit AA(int a1, int a2)
	{
		cout << "AA(int a1, int a2)" << endl;
	}

	AA(const AA& a)
	{
		cout << "AA(const AA& a)" << endl;
	}
private:
	int _a1;
	int _a2;
};


int main()
{
	//test1();
	//test2();
	AA aa1(1);

	// 隐式转换-> AA tmp(1); AA aa2(tmp)，有些编译器会优化成直接构造
	AA aa2 = 1;//先构造再拷贝构造
	AA aa3 = { 1, 2 }; // C++11支持的列表初始化，多个参数的隐式转换
	return 0;
}