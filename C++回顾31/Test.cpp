//#include<iostream>
//using namespace std;
//class Date
//{
//	public:
//		//explicit Date(int year)用explicit修饰构造函数，将会禁止单参构造函数的隐式转换。
//		 Date(int year)
//			:_year(year)
//		{
//			cout << "Date(int year)" << endl;
//		}
//
//		 Date(const Date& d)
//		{
//			cout << "Date(const Date& d)" << endl;
//		}
//
//	private:
//		int _year;
//		int _month;
//		int _day;
//};
//
//int main()
//{
//	Date d1(1);   // 构造
//	Date d2 = 2;  // 隐式类型的转换  先构造出tmp(2)+再用tmp拷贝构造d2(tmp)+（前面的步骤可能会被优化成直接使用构造来初始化d2）
//	//const Date& d2 = 2;  // 通过这个例子可以证明引用的就是中间产生的临时对象，因为临时对象具有常性
//	//必须使用const修饰才能引用
//	Date d3 = d1; // 拷贝构造
//
//	//和const Date&d2=2;进行对比，可见const Date&d2=2引用的额确实是临时对象
//	int i = 1;
//	const double& d = i;  // 隐式类型转换，会产生中间的临时变量
//
//	return 0;
//}

#include<iostream>
using namespace std;
class Date
{
public:
	//explicit Date(int year, int month, int day)
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date(int year)" << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1, 2, 3);

	// C++11
	Date d2 = { 1,2,3 }; // 隐式类型转换，多参数的C++11才支持

	return 0;
}
