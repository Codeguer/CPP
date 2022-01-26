//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public://初始化列表是对象的成员变量的定义的地方
//	B(int a, int ref)
//		:_aobj(a)
//		
//		, _n(10)
//		, _ref(ref)
//	{//函数体内赋值//当B调用构造函数来到这一行时_aobj _n _x已经有随机值了
//		//但是_aobj与_n _ref必须进行初始化否则会报错，_ref因为是引用所以无法读取内存
//		_x = 10;//赋值
//	}
//private://成员变量的声明
//	A _aobj; // 没有默认构造函数(A没有了那个不需要传参的默认构造函数)
//	//自定义的也为默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//	int _x;
//};
//
//int main()
//{
//	B b(1, 2);//对象定义，对象内的成员变量就要被定义了，只是有些变量通过初始化列表定义并初始化，而像_x就直接被定义，然后通过在函数体内进行赋值
//	return 0;
//}
//

#include<iostream>
using namespace std;
class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)//这里未使用初始化列表
	{
		Time t(day);//进入Time的初始化列表对t进行初始化
		_t = t;//默认的赋值运算符
	}
private:
	int _day;
	Time _t;// 对于自定义类型成员变量，一定会先使用初始化列表初始化。

};

//class Date
//{
//	public:
//		Date(int day)
//			:_t(day)//进入Time的有参构造函数进行初始化
//		{}
//	private:
//		int _day;
//		Time _t;
//};
int main()
{
	Date d(1);//首先调用Date的默认构造函数

	return 0;
}

