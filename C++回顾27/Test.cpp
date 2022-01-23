#include <iostream>
using namespace std;

//对象调const成员函数
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// void Print() - 》void Print(Date* this)
	void Print() const // ->void Print(const Date* this)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		// 不能修改成员变量了，因为const修饰保护了*this
		//this->_year = 10;
	}

	// const Date* p1  ->*p1 指向的对象
	// Date const * p2 ->*p2 指向的对象
	// Date* const p3  ->p3  指针本身
private:
	int _year;
	int _month;
	int _day;
};

void f(const Date& d)//给d改为const引发的思考
{
	d.Print();//可以理解为d.Print(&d);因为有隐式指针，因此对d取地址传过去
			  //那么那边接收d的指针也必须是const
}

int main()
{
	Date d1(2020, 4, 18);
	f(d1);
	d1.Print(); // Date*

	return 0;
}