#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//�����Լ���ʵ��ʱ�����������ɿ���������opereator=,����ɰ��ֽڵ�ֵ������ǳ������
//Ҳ����˵��Щ�࣬�����ǲ���Ҫȥʵ�ֿ��������operator=�ģ���Ϊ������Ĭ�����ɾͿ�����
//���磺Date��������

//һ���ࣺ���캯������Ҫд��������������û��Ҫ�ͷŵĿռ䣬���������븳ֵ����������������
//������Ͳ���Ҫд

class Date//���������븳ֵ�������ûд
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

	//	if (this != &d)  // ����Լ����Լ���ֵ���жϼ��d3 = d3
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}

	//	return *this; // this����d3�ĵ�ַ��*this����d3
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

	//// d1 == d2; // ���ǲ�д�����������Զ������𣿲��ᣬ��Ϊ������Ĭ�ϳ�Ա����

	Date d3(d1);
	Date d4 = d1;
	d3.Print();//2020-4-15
	d4.Print();//2020-4-15

	// ǳ�������⣿//������Щ����������������
	/*Stack st1(10);
	Stack st2(st1);

	Stack st3(30);
	st1 = st3;*/

	return  0;
}
