#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;//����Ϳ����ô�����_���������ĸ��ǳ�Ա����
		_month = month;
		this->_day = day;//����ֱ����thieָ�룬������������󶼻ᴦ���������
	}
	void Print()//���ǲ������Լ��ں��������thieָ����void Print(&d1)�����ǲ��е�
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//������thisָ��
	//�������Ὣ�䴦��Ϊ
	/*void Print(Date* this)��ָ������־�Ϊthis
	{
		cout <<this-> _year << "-" <<this-> _month << "-" <<this-> _day << endl;
	}*/
private:
	int _year;//��_˵���ǳ�Ա����
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Init(2021, 7, 13);//d1.Init(&d1,2021, 7, 13);Լ���õģ��ڵ�һ��λ�ô�����ĵ�ַ
	d1.Print();//�������Ὣ�䴦��Ϊd1.Print(&d1);
	return 0;
}