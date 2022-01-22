#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//我们自己不实现时，编译器生成拷贝函数与opereator=,会完成按字节的值拷贝（浅拷贝）
//也就是说有些类，我们是不需要去实现拷贝构造和operator=的，因为编译器默认生成就可以用
//比如：Date就是这样

//一个类：构造函数必须要写，析构函数看有没有要释放的空间，拷贝函数与赋值运算符重载则看情况，
//日期类就不需要写

class Date//拷贝构造与赋值运算符都没写
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//Date& operator=(const Date& d)
	//{
	//	cout << "Date& operator=(const Date& d)" << endl;

	//	if (this != &d)  // 针对自己给自己赋值的判断检查d3 = d3
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}

	//	return *this; // this就是d3的地址，*this就是d3
	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)*n);
		_size = 0;
		_capacity = n;
	}

	~Stack()
	{
		if (_a != nullptr)
		{
			free(_a);
			_a = nullptr;
			_size = _capacity = 0;
		}
	}

private:
	int* _a;
	size_t _size;
	size_t _capacity;
};

int main()
{
	Date d1(2020, 4, 11);
	Date d2(2020, 4, 15);
	d1 = d2;
	d1.Print();//2020-4-15
	d2.Print();//2020-4-15

	//// d1 == d2; // 我们不写，编译器会自动生成吗？不会，因为他不是默认成员函数

	Date d3(d1);
	Date d4 = d1;
	d3.Print();//2020-4-15
	d4.Print();//2020-4-15

	// 浅拷贝问题？//下面这些代码会引发程序崩溃
	/*Stack st1(10);
	Stack st2(st1);

	Stack st3(30);
	st1 = st3;*/

	return  0;
}
