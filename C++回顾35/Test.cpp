#include <iostream>
using namespace std;

class Date
{
public:
	Date()
		:_year(10)
	{}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	// C++11��֧��
	// ����ʱ��ȱʡֵ�������Ϳ���ʵ�ּ�ʹ��û����������������Ҳ���Լ���ʼ���ˣ�
	int _year = 0;
	int _month = 1;
	int _day = 1;

	static int _n;//���ܸ���̬��Աȱʡֵ����̬��Ա���������ⶨ�岢��ʼ��
};

int Date::_n = 1;

int main()
{
	Date d1;
	d1.Print(); 

	return 0;
}