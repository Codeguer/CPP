#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date* operator&() // Date*
	{
		cout << " operator&()" << endl;

		//return this;
		return nullptr;//需要写这个函数的用处：让对象取不到地址，返回空指针
						//一般不写它，默认的足够用了
	}

	const Date* operator&() const // const Date*
	{
		cout << " operator&() const" << endl;

		//return this;
		return nullptr;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2;
	const Date d3;

	cout << &d1 << endl;
	cout << &d2 << endl;
	cout << &d3 << endl;

	return 0;
}