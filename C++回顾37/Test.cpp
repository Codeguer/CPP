#include <iostream>
using namespace std;//cout是标准库std命名里面一个ostream类型的全局对象
//必须用友元的场景
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	//void operator<<(ostream& out)//d1.operator<<(cout);或d1<<cout;但无法这样写cout<<d1;
	//因此不能写到类中
	//{
	//	out << _year << "/" << _month << "/" << _day << endl;
	//}

private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

ostream& operator<<(ostream& out, const Date& d)//这样就可以写成cout<<d1;
{
	out << d._year << "/" << d._month << "/" << d._day << endl;

	return out;//给返回值是为了cout << d1 << d2 << i << endl;可以连续输出
}

// cout -> ostream类型的
// cin  -> istream类型的
//写一下
istream& operator>>(istream& in, Date& d)//istream& in不能加const，in要流出数据，上面的out要接收数据
{
	in >> d._year >> d._month >> d._day;//空格或者换行进行输入分割，最后换行结束
	return in;
}

int main()
{
	int i = 0, j = 1;
	//cout << i << j << endl;

	Date d1(2020,4,20);
	Date d2(2020, 4, 21);
	cin >> d1 >> d2;
	cout << d1 << d2 << i << endl;


	// cout << d1;   // operator> << (cout, d1);
	//d1 << cout; // d1.operator<<(cout);

	int x = 1;
	double y = 1.11;
	// 为什么能自动识别类型，因为函数重载
	cout << x; // cout.operator<<(&cout, x)
	cout << y; // cout.operator<<(&cout, y)


	return 0;
}