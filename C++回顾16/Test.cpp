#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
	public:
		Date(int year, int month, int day)//构造函数无返回值，不需写void，名字和类名相同
		{
			_year = year;
			_month = month;
			_day = day;
		}

		Date()//重载
		{
			_year = 1998;
			_month = 6;
			_day = 1;
		}
		void SetDate(int year, int month, int day)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		void Display()
		{
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	private:
		int _year;
		int _month;
		int _day;
};

int main()
{
	
	//Date d1;
	//d1.Display();//如果在初始化之前就调用那么就会出现随机值-858993460--858993460--858993460
	//d1.SetDate(2018, 5, 1);//2018 - 5 - 1
	//d1.Display();
	//Date d2;
	//d2.SetDate(2018, 7, 1); //2018 - 7 - 1
	//d2.Display();

	//构造函数若设有参数，那么对象定义时就需要带参创建，因为在对象创建的同时就会调用构造函数了
	Date d1(2021, 7, 13);
	d1.Display();//2021-7-13
	
	//构造函数的主要任务并不是开空间创建对象，而是初始化对象,因为Date d1，d1就开辟在栈上了
	//构造函数可以重载
	Date d2;//调无参的构造函数那么这里不能加括号，否则就成了函数声明,那么下面d2.Display()就
	//要屏蔽掉，不然会报错
	d2.Display();//1998-6-1
	return 0;
}