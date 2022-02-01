#include <iostream>
using namespace std;
// 友元
class Date
{
	friend void f(Date& d); // 友元函数,可以突破访问限定符的限制进行访问
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

void f(Date& d)
{
	d._year = 10;//访问私有成员并进行修改
	cout << d._year << endl;
}

int main()
{
	Date d1;
	d1.Print();

	f(d1);

	return 0;
}