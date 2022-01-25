#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date* operator&() // Date*
	{
		cout << " operator&()" << endl;

		//return this;
		return nullptr;//��Ҫд����������ô����ö���ȡ������ַ�����ؿ�ָ��
						//һ�㲻д����Ĭ�ϵ��㹻����
	}

	const Date* operator&() const // const Date*
	{
		cout << " operator&() const" << endl;

		//return this;
		return nullptr;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2;
	const Date d3;

	cout << &d1 << endl;
	cout << &d2 << endl;
	cout << &d3 << endl;

	return 0;
}