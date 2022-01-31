#include <iostream>
using namespace std;

class Date
{
public:
	Date()
		:_year(10)
	{}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	// C++11才支持
	// 声明时给缺省值（这样就可以实现即使你没给内置类型做处理也能自己初始化了）
	int _year = 0;
	int _month = 1;
	int _day = 1;

	static int _n;//不能给静态成员缺省值，静态成员必须在类外定义并初始化
};

int Date::_n = 1;

int main()
{
	Date d1;
	d1.Print(); 

	return 0;
}