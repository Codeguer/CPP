#include <iostream>
using namespace std;
// ��Ԫ
class Date
{
	friend void f(Date& d); // ��Ԫ����,����ͻ�Ʒ����޶��������ƽ��з���
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

void f(Date& d)
{
	d._year = 10;//����˽�г�Ա�������޸�
	cout << d._year << endl;
}

int main()
{
	Date d1;
	d1.Print();

	f(d1);

	return 0;
}