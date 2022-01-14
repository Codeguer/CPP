#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
	public:
		Date(int year=1, int month=1, int day=1)
		{
			_year = year;
			_month = month;
			_day = day;
			cout << "Date()" << endl;
		}
		void Print()
		{
			cout << _year << "-" << _month << "-" << _day << endl;
		}
		~Date()//析构函数
		{
			cout << "~Date()" << endl;
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
		cout << "Stack" << _a << endl;
		_size = 0;
		_capacity = n;
	}
	~Stack()
	{
		free(_a);
		cout <<"~Stack"<< _a << endl;
		_a = nullptr;
		_size = _capacity = 0;

	}
private:
	int *_a;
	int _size;
	int _capacity;
};
int main()
{
	
	Date d1;//对象生命周期到了以后，自动调用析构函数，完成清理工作，不是完成对象的销毁，
	//这是编译器做的事，析构函数完成的是对象被销毁后的清理工作
	Date d2;

	Stack s1;
	Stack s2;
	return 0;
}
//当main函数执行完时，就要完成对象的销毁，因为d1、d2、s1、s2先后入栈，栈后入先出，因此
//先s2被销毁，接着是s1、d2、d1
