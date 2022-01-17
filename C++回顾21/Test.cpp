#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

// ȫ�ֵ�operator==
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//private:���乫����ʵ�ʲ��ܹ���
	int _year;
	int _month;
	int _day;
};
// ����ᷢ����������س�ȫ�ֵľ���Ҫ��Ա�����ǹ��еģ���ô�������ˣ���װ����α�֤��
// ������ʵ���������Ǻ���ѧϰ����Ԫ��������߸ɴ����سɳ�Ա������
bool operator==(const Date& d1, const Date& d2)//��������أ�������һ������
{
	return d1._year	 == d2._year
		&& d1._month == d2._month
		&& d1._day	 == d2._day;
}
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}

//�Զ��������ǲ�����������ģ�Ҫ�þ͵�ʵ������������������Զ�������ʹ���������ʱ��͵ȼ���
//���������������غ���
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
	cout << operator==(d1,d2) << endl;
	//operator==(d1,d2)��d1==d2��һ���ģ�һ��д��d1==d2,�����ɶ���Ҫǿ
	//d1==d2�������Ὣ֮ת��Ϊoperator==(d1,d2)
}

int main()
{
	Test();
	return 0;
}