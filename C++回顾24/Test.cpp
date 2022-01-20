#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//ʵ��һ�����Ƶ�������
//һ�����߰�ʮ������ʮһ������������Ŷ���ʮ����ƽ����¶�ʮ�ˣ�������°�һ��
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
			cout << "�Ƿ�����" << endl;
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
	//��������ᳫ����          ���ھ�                      �����
	//���ڶ���        ���ڲ���Ա��Ĺ�ϵԽ����Խ��    �����֮��Ĺ�ϵ��Խ��ԶԽ�ã�
	//������ͺ���һ�����ţ��������ÿ����ԱԽ������ս����Խǿ��
	//�����벿�ŵ���ϵ����������ŵ��˲�Ӱ����������
	//�Ժ�������ָģ���Ĺ�ϵ

	Date& operator=(const Date&d)//��ֵ������Ƕ��Ѿ����ڵ��ҳ�ʼ���Ķ�����в���
		//Date d3(d1);d3�������ڣ�����d3ʱ��d1ȥ��ʼ��
		//Date d4=d1;ע�������ǿ������죬����operator����Ϊd4֮ǰ����������δ��ʼ��
	{
		if (this != &d)//��ֹ����d3=d3;��������֣��ȵ�ַ�ȱȶ���Ҫ�죬�ȶ�����Ҫ���������
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//�������d1=d2=d3�з���ֵ����������ֵ
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
	//	return ret;//���������������ã���Ϊ���ᱻ����
	//}

	Date operator+(int day)
	{
		Date ret(*this);
		ret+=day;//ret.operator+=(day
		
		return ret;//���������������ã���Ϊ���ᱻ����
	}


	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= (-day);//������d1+=-100��֮ת��Ϊd1-=100;
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
			return *this += -day;//�������d1-=-100,��֮ת��Ϊd1+=100;
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
		return *this;//thisָ����Ǹ���������������ᱻ���٣���˿��Խ������÷���
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
	Date& operator++()//ǰ��++
	{
		return *this += 1;
	}

	//����++
	//d1++ => d1.operator++(&d1,0)//0�����ģ�Ϊ��ƥ�������Ҳ���Ը�����ֵ
	Date operator++(int)//Ϊ�˹���������˷���һ���ò�����int
	{
		Date tmp(*this);
		*this += 1;
		return tmp ;
	}

	//ǰ��--
	Date& operator--()
	{
		return *this -= 1;
	}

	//����--
	Date operator--(int)
	{
		Date tmp(*this);
		*this-= 1;
		return tmp;
	}
	//�������������
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
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}
private://�����ⲿ���Ե�
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
	// �Ƿ�Ҫ����һ������������������������Ƿ�������Ķ���������
	cout << "d2 == d3:"<<(d2 == d3) << endl;
	cout << "d2 >= d3:" << (d2 >= d3) << endl;
	cout << "d2 != d3:" << (d2 != d3) << endl;
	cout << "d2 < d3:" << (d2 <  d3) << endl;
	cout << "d2 <= d3:" << (d2 <= d3) << endl;
	cout << "d2 > d3:" << (d2 >  d3) << endl;
	return 0;
}