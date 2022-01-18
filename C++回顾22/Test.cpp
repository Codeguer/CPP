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
		// bool operator==(Date* this, const Date& d2)
		// ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
		//d1==d2;//����d1����������غ���
		//d1.operator==(&d1,d2);
		bool operator==(const Date& d)//���سɳ�Ա��������ʵΪ
			//bool operator==(Date* this,const Date& d)
		{
			return this->_year == d._year
				&& _month == d._month
				&& _day == d._day;
		}
	private:
		int _year;
		int _month;
		int _day;
};


//�Զ��������ǲ�����������ģ�Ҫ�þ͵�ʵ������������������Զ�������ʹ���������ʱ��͵ȼ���
//���������������غ���
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
	cout << d1.operator==(d2) << endl;
	//d1.operator==(d2)��d1==d2��һ���ģ�һ��д��d1==d2,�����ɶ���Ҫǿ
	//d1==d2�������Ὣ֮ת��Ϊd1.operator==(d2)������д��d1.operator==(&d1,d2);��Ϊ
	//this����ʽָ�룬��������ʾ��
}

int main()
{
	Test();
	return 0;
}