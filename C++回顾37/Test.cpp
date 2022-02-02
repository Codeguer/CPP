#include <iostream>
using namespace std;//cout�Ǳ�׼��std��������һ��ostream���͵�ȫ�ֶ���
//��������Ԫ�ĳ���
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	//void operator<<(ostream& out)//d1.operator<<(cout);��d1<<cout;���޷�����дcout<<d1;
	//��˲���д������
	//{
	//	out << _year << "/" << _month << "/" << _day << endl;
	//}

private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

ostream& operator<<(ostream& out, const Date& d)//�����Ϳ���д��cout<<d1;
{
	out << d._year << "/" << d._month << "/" << d._day << endl;

	return out;//������ֵ��Ϊ��cout << d1 << d2 << i << endl;�����������
}

// cout -> ostream���͵�
// cin  -> istream���͵�
//дһ��
istream& operator>>(istream& in, Date& d)//istream& in���ܼ�const��inҪ�������ݣ������outҪ��������
{
	in >> d._year >> d._month >> d._day;//�ո���߻��н�������ָ����н���
	return in;
}

int main()
{
	int i = 0, j = 1;
	//cout << i << j << endl;

	Date d1(2020,4,20);
	Date d2(2020, 4, 21);
	cin >> d1 >> d2;
	cout << d1 << d2 << i << endl;


	// cout << d1;   // operator> << (cout, d1);
	//d1 << cout; // d1.operator<<(cout);

	int x = 1;
	double y = 1.11;
	// Ϊʲô���Զ�ʶ�����ͣ���Ϊ��������
	cout << x; // cout.operator<<(&cout, x)
	cout << y; // cout.operator<<(&cout, y)


	return 0;
}