#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

// 全局的operator==
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//private:将其公开，实际不能公开
	int _year;
	int _month;
	int _day;
};
// 这里会发现运算符重载成全局的就需要成员变量是共有的，那么问题来了，封装性如何保证？
// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
bool operator==(const Date& d1, const Date& d2)//运算符重载，本质是一个函数
{
	return d1._year	 == d2._year
		&& d1._month == d2._month
		&& d1._day	 == d2._day;
}
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}

//自定义类型是不能用运算符的，要用就得实现重载运算符函数，自定义类型使用运算符得时候就等价于
//调用这个运算符重载函数
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
	cout << operator==(d1,d2) << endl;
	//operator==(d1,d2)与d1==d2是一样的，一般写成d1==d2,这样可读性要强
	//d1==d2编译器会将之转化为operator==(d1,d2)
}

int main()
{
	Test();
	return 0;
}