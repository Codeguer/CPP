#include <iostream>
using namespace std;

//�����const��Ա����
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// void Print() - ��void Print(Date* this)
	void Print() const // ->void Print(const Date* this)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		// �����޸ĳ�Ա�����ˣ���Ϊconst���α�����*this
		//this->_year = 10;
	}

	// const Date* p1  ->*p1 ָ��Ķ���
	// Date const * p2 ->*p2 ָ��Ķ���
	// Date* const p3  ->p3  ָ�뱾��
private:
	int _year;
	int _month;
	int _day;
};

void f(const Date& d)//��d��Ϊconst������˼��
{
	d.Print();//�������Ϊd.Print(&d);��Ϊ����ʽָ�룬��˶�dȡ��ַ����ȥ
			  //��ô�Ǳ߽���d��ָ��Ҳ������const
}

int main()
{
	Date d1(2020, 4, 18);
	f(d1);
	d1.Print(); // Date*

	return 0;
}