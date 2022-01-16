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
		Date(const Date& d)//Date( Date d),这样写会陷入死递归
			//使用引用是为了防止将d1传进来的时候调用拷贝函数将d1进行拷贝从而出现死递归
		{
			
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	private:
		int _year;
		int _month;
		int _day;
};
int main()
{
	Date d1(2021,7,14);
	//Date d2(2021,7,14);
	Date d2(d1);//拷贝d1
	//Date d2=d1;这一句与上面得Date d2(d1);效果十一月得，都是进行拷贝
	Date d3;
	//Date(const Date& d)加const是为了防止误写如Date d1(d3);从而将d1的值进行修改
	return 0;
}