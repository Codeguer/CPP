#include<iostream>
using namespace std;
class Date
{
public:
	//explicit Date(int year, int month, int day)
	Date(int year, int month, int day)
		:_year(year)
	{
		cout << "Date(int year)" << endl;
	}

	Date(const Date& d)
	{
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
	Date d2 = {1,2,3}; // 隐式类型转换，C++11才支持


	return 0;
}