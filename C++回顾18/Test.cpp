#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
	public:
		Date(int year=1, int month=1, int day=1)
		{
			_year = year;
			_month = month;
			_day = day;
			cout << "Date()" << endl;
		}
		void Print()
		{
			cout << _year << "-" << _month << "-" << _day << endl;
		}
		~Date()//��������
		{
			cout << "~Date()" << endl;
		}
	private:
		int _year;
		int _month;
		int _day;

};

class Stack
{
public:
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)*n);
		cout << "Stack" << _a << endl;
		_size = 0;
		_capacity = n;
	}
	~Stack()
	{
		free(_a);
		cout <<"~Stack"<< _a << endl;
		_a = nullptr;
		_size = _capacity = 0;

	}
private:
	int *_a;
	int _size;
	int _capacity;
};
int main()
{
	
	Date d1;//�����������ڵ����Ժ��Զ��������������������������������ɶ�������٣�
	//���Ǳ����������£�����������ɵ��Ƕ������ٺ��������
	Date d2;

	Stack s1;
	Stack s2;
	return 0;
}
//��main����ִ����ʱ����Ҫ��ɶ�������٣���Ϊd1��d2��s1��s2�Ⱥ���ջ��ջ�����ȳ������
//��s2�����٣�������s1��d2��d1
