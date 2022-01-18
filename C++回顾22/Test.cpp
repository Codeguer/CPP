#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
	public:
		Date(int year = 1900, int month = 1, int day = 1)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		// bool operator==(Date* this, const Date& d2)
		// 这里需要注意的是，左操作数是this指向的调用函数的对象
		//d1==d2;//调用d1的运算符重载函数
		//d1.operator==(&d1,d2);
		bool operator==(const Date& d)//重载成成员函数。其实为
			//bool operator==(Date* this,const Date& d)
		{
			return this->_year == d._year
				&& _month == d._month
				&& _day == d._day;
		}
	private:
		int _year;
		int _month;
		int _day;
};


//自定义类型是不能用运算符的，要用就得实现重载运算符函数，自定义类型使用运算符得时候就等价于
//调用这个运算符重载函数
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
	cout << d1.operator==(d2) << endl;
	//d1.operator==(d2)与d1==d2是一样的，一般写成d1==d2,这样可读性要强
	//d1==d2编译器会将之转化为d1.operator==(d2)，不能写成d1.operator==(&d1,d2);因为
	//this是隐式指针，不允许显示传
}

int main()
{
	Test();
	return 0;
}