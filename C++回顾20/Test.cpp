#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
	public:
		Date(int year = 1900, int month = 1, int day = 1)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		Date(const Date& d)//Date( Date d),����д���������ݹ�
			//ʹ��������Ϊ�˷�ֹ��d1��������ʱ����ÿ���������d1���п����Ӷ��������ݹ�
		{
			
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	private:
		int _year;
		int _month;
		int _day;
};
int main()
{
	Date d1(2021,7,14);
	//Date d2(2021,7,14);
	Date d2(d1);//����d1
	//Date d2=d1;��һ���������Date d2(d1);Ч��ʮһ�µã����ǽ��п���
	Date d3;
	//Date(const Date& d)��const��Ϊ�˷�ֹ��д��Date d1(d3);�Ӷ���d1��ֵ�����޸�
	return 0;
}