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
	void print()
	{
		cout << _year << '-' << _month << '-' << _day <<  endl;
	}
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	// ����d2���õ�Ĭ�Ͽ���������ɿ�����d2��d1��ֵҲ��һ���ġ�
	Date d2(d1);
	d1.print();
	d2.print();
	d1._year = 2021;
	d1.print();
	d2.print();
	const Date&a = Date();
	
	return 0;
}





