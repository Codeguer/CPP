#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;//这里就可以用带不带_进行区分哪个是成员变量
		_month = month;
		this->_day = day;//可以直接用thie指针，反正编译器最后都会处理成这样子
	}
	void Print()//我们不可以自己在函数里面加thie指针如void Print(&d1)这样是不行的
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//隐含的this指针
	//编译器会将其处理为
	/*void Print(Date* this)该指针的名字就为this
	{
		cout <<this-> _year << "-" <<this-> _month << "-" <<this-> _day << endl;
	}*/
private:
	int _year;//带_说明是成员变量
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Init(2021, 7, 13);//d1.Init(&d1,2021, 7, 13);约定好的，在第一个位置传对象的地址
	d1.Print();//编译器会将其处理为d1.Print(&d1);
	return 0;
}