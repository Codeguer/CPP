#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
	public:
		Date(int year, int month, int day)//���캯���޷���ֵ������дvoid�����ֺ�������ͬ
		{
			_year = year;
			_month = month;
			_day = day;
		}

		Date()//����
		{
			_year = 1998;
			_month = 6;
			_day = 1;
		}
		void SetDate(int year, int month, int day)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		void Display()
		{
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	private:
		int _year;
		int _month;
		int _day;
};

int main()
{
	
	//Date d1;
	//d1.Display();//����ڳ�ʼ��֮ǰ�͵�����ô�ͻ�������ֵ-858993460--858993460--858993460
	//d1.SetDate(2018, 5, 1);//2018 - 5 - 1
	//d1.Display();
	//Date d2;
	//d2.SetDate(2018, 7, 1); //2018 - 7 - 1
	//d2.Display();

	//���캯�������в�������ô������ʱ����Ҫ���δ�������Ϊ�ڶ��󴴽���ͬʱ�ͻ���ù��캯����
	Date d1(2021, 7, 13);
	d1.Display();//2021-7-13
	
	//���캯������Ҫ���񲢲��ǿ��ռ䴴�����󣬶��ǳ�ʼ������,��ΪDate d1��d1�Ϳ�����ջ����
	//���캯����������
	Date d2;//���޲εĹ��캯����ô���ﲻ�ܼ����ţ�����ͳ��˺�������,��ô����d2.Display()��
	//Ҫ���ε�����Ȼ�ᱨ��
	d2.Display();//1998-6-1
	return 0;
}