#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//实现一个完善的日期类
//一三五七八十腊，三十一天永不差，四六九冬三十整，平年二月二十八，闰年二月把一加
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 29;
		}
		return monthDays[month];
	}
	Date(int year = 2021, int month = 7, int day = 14)
	{
		if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
			cout << "非法日期" << endl;
		}

	}
	inline bool operator==(const Date &d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}

	inline bool operator>(const Date &d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year&&_month > d._month)
			return true;
		else if (_year == d._year&&_month == d._month&&_day > d._day)
			return true;
		return false;

	}
	//软件工程提倡的是          高内聚                      低耦合
	//现在对类        类内部成员间的关系越紧密越好    类和类之间的关系（越疏远越好）
	//比如类就好像一个部门，部门里的每个成员越紧密作战能力越强，
	//部门与部门的联系不大，这个部门倒了不影响其它部门
	//以后更多的是指模块间的关系

	Date& operator=(const Date&d)//赋值运算符是对已经存在的且初始化的对象进行操作
		//Date d3(d1);d3还不存在，构造d3时用d1去初始化
		//Date d4=d1;注意这里是拷贝构造，不是operator，因为d4之前并不存在且未初始化
	{
		if (this != &d)//防止出现d3=d3;的情况出现，比地址比比对象要快，比对象需要重载运算符
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//如果出现d1=d2=d3有返回值就能连续赋值
	}


	bool operator>=(const Date &d)
	{
		return *this > d || *this == d;
	}

	bool operator<(const Date&d)
	{
		return !(*this >= d);
	}

	bool operator<=(const Date&d)
	{
		return !(*this > d);
	}

	bool operator!=(const Date&d)
	{
		return !(*this == d);
	}
	Date(const Date&d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//Date operator+(int day)
	//{
	//	Date ret(*this);
	//	ret._day += day;
	//	while (ret._day > GetMonthDay(ret._year, ret._month))
	//	{
	//		ret._day -= GetMonthDay(ret._year, ret._month);
	//		ret._month++;
	//		if (ret._month == 13)
	//		{
	//			ret._year++;
	//			ret._month = 1;
	//		}
	//			
	//	}
	//	return ret;//返回它不能用引用，因为它会被销毁
	//}

	Date operator+(int day)
	{
		Date ret(*this);
		ret+=day;//ret.operator+=(day
		
		return ret;//返回它不能用引用，因为它会被销毁
	}


	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= (-day);//若出现d1+=-100将之转换为d1-=100;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}

		}
		return *this;
	}
	
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;//如果出现d1-=-100,将之转化为d1+=100;
		}
		_day -= day;
		while (_day<=0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;//this指向的那个出了这个函数不会被销毁，因此可以进行引用返回
	}

	Date operator-(int day)
	{
		Date ret = *this;
		ret._day -= day;
		while (ret._day <= 0)
		{
			ret._month--;
			if (ret._month == 0)
			{
				ret._year--;
				ret._month = 12;
			}
			ret._day += GetMonthDay(ret._year,ret. _month);
		}
		return ret;
	}

	//++d1 => d1.operator++(&d1)
	Date& operator++()//前置++
	{
		return *this += 1;
	}

	//后置++
	//d1++ => d1.operator++(&d1,0)//0随便给的，为了匹配参数，也可以给其它值
	Date operator++(int)//为了构成重载因此放了一个用不到的int
	{
		Date tmp(*this);
		*this += 1;
		return tmp ;
	}

	//前置--
	Date& operator--()
	{
		return *this -= 1;
	}

	//后置--
	Date operator--(int)
	{
		Date tmp(*this);
		*this-= 1;
		return tmp;
	}
	//日期于日期相减
	int operator-( const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}
		return n*flag;
	}

	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
private://对类外部而言的
	int _year;
	int _month;
	int _day;

};

int main()
{
	Date d1;
	cout << "Date d1:" << endl;
	d1.Print();
	cout << endl;

	Date d2(2020, 4, 31);
	cout << "Date d2:" << endl;
	d2.Print();
	cout <<endl;

	cout << "d1-d2:" << (d1 - d2) << endl;
	cout << "d2-d1:" << (d2 - d1) << endl;
	cout << endl;

	Date d3(2021, 4, 31);
	cout << "Date d3(2021, 4, 31):" << endl;
	d3.Print();
	cout << endl;
	
	d3 += 365;
	cout << "d3 += 365:" << endl;
	d3.Print();
	cout << endl;

	cout << "d3 -= 365:" << endl;
	d3 -= 365;
	d3.Print();
	cout << endl;

	cout << "d3 --:"<< endl;
	d3--.Print();
	cout << "d3:" << endl;
	d3.Print();
	cout << endl;

	cout << "--d3 :" << endl;
	(--d3).Print();
	cout << "d3:" << endl;
	d3.Print();
	cout << endl;

	cout << "d3 ++:" << endl;
	(d3++).Print();
	cout << "d3:" << endl;
	d3.Print();
	cout << endl;

	cout << "++d3 :" << endl;
	(++d3).Print();
	cout << "d3:" << endl;
	d3.Print();
	cout << endl;

	Date d4 = (d1 + 365);
	cout << "Date d4 = (d1 + 365):" << endl;
	d4.Print();
	cout << endl;

	Date d5 = (d1 - 365);
	cout << "	Date d5 = (d1 - 365):" << endl;
	d5.Print();
	cout << endl;

	d5 = d4;
	cout << "d5 = d4:" << endl;
	d5.Print();
	cout << endl;
	// 是否要重载一个运算符，看的是这个运算符是否对这个类的对象有意义
	cout << "d2 == d3:"<<(d2 == d3) << endl;
	cout << "d2 >= d3:" << (d2 >= d3) << endl;
	cout << "d2 != d3:" << (d2 != d3) << endl;
	cout << "d2 < d3:" << (d2 <  d3) << endl;
	cout << "d2 <= d3:" << (d2 <= d3) << endl;
	cout << "d2 > d3:" << (d2 >  d3) << endl;
	return 0;
}