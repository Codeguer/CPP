#include<iostream>
using namespace std;
//��Ա��������const��Ա����
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 
	void f1()  // void f1(Date* this)
	{
		f2();  // this->f2(this); // ���ԣ�����Ȩ�޵���С
	}

	void f2() const //void f2(const Date* this)
	{}

	////////////////////////////////////////////////
	void f3() // void f3(Date* this)
	{}

	void f4() const // void f4(const Date* this)
	{
		//f3(); // this->f(this); // ���У�����Ȩ�޷Ŵ�
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	return 0;
}