//#include<iostream>
//using namespace std;
//class Date
//{
//	public:
//		//explicit Date(int year)��explicit���ι��캯���������ֹ���ι��캯������ʽת����
//		 Date(int year)
//			:_year(year)
//		{
//			cout << "Date(int year)" << endl;
//		}
//
//		 Date(const Date& d)
//		{
//			cout << "Date(const Date& d)" << endl;
//		}
//
//	private:
//		int _year;
//		int _month;
//		int _day;
//};
//
//int main()
//{
//	Date d1(1);   // ����
//	Date d2 = 2;  // ��ʽ���͵�ת��  �ȹ����tmp(2)+����tmp��������d2(tmp)+��ǰ��Ĳ�����ܻᱻ�Ż���ֱ��ʹ�ù�������ʼ��d2��
//	//const Date& d2 = 2;  // ͨ��������ӿ���֤�����õľ����м��������ʱ������Ϊ��ʱ������г���
//	//����ʹ��const���β�������
//	Date d3 = d1; // ��������
//
//	//��const Date&d2=2;���жԱȣ��ɼ�const Date&d2=2���õĶ�ȷʵ����ʱ����
//	int i = 1;
//	const double& d = i;  // ��ʽ����ת����������м����ʱ����
//
//	return 0;
//}

#include<iostream>
using namespace std;
class Date
{
public:
	//explicit Date(int year, int month, int day)
	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date(int year)" << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date& d)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1, 2, 3);

	// C++11
	Date d2 = { 1,2,3 }; // ��ʽ����ת�����������C++11��֧��

	return 0;
}
