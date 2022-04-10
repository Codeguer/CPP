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
		bool operator>(const Date& d)//重载成成员函数。其实为
			//bool operator==(Date* this,const Date& d)
		{
			if (_year > d._year)
				return true;
			else if (_year == d._year&&_month > d._month)
				return true;
			else if (_year == d._year&&_month == d._month&&_day > d._day)
				return true;
			return false;
		}
	private:
		int _year;
		int _month;
		int _day;
};


void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 > d2) << endl;
	cout << d1.operator>(d2) << endl;
	
}

int main()
{
	Test();
	return 0;
}