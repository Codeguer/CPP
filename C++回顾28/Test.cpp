#include<iostream>
using namespace std;
//成员函数调用const成员函数
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 
	void f1()  // void f1(Date* this)
	{
		f2();  // this->f2(this); // 可以，属于权限的缩小
	}

	void f2() const //void f2(const Date* this)
	{}

	////////////////////////////////////////////////
	void f3() // void f3(Date* this)
	{}

	void f4() const // void f4(const Date* this)
	{
		//f3(); // this->f(this); // 不行，属于权限放大
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	return 0;
}