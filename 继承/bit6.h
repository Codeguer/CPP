#include <iostream>
#include <string>
using namespace std;

namespace bit6
{
	class A
	{
	public:
		 A() {};
		 A(const A&p)
		{
			//_a = p._a;
			 _a = 50;
			cout << "A&operator=(const A&p)" << endl;
		}

		void Print() { cout << "Print():" << endl; }

		int _a = 1;
	};

	class B :public A
	{
	public:
		void Print() { cout << "A::_a=" << A::_a << endl; }//�ض�������ʾ����
		int _b = 2;
	};

	void test_bit6()
	{
		A a;
		B b;
		b._a = 10;
		b._b = 20;
		B c = b;
		//���ಢû��д�������캯��������ϵͳ�ڱ�Ҫ��ʱ���Զ�������
		//һ�������Ŀ������캯�������Զ����ø���Ŀ������캯������ɼ̳еĳ�Ա�Ŀ���
		//Ȼ��������Ŀ������캯���������������Ա�Ŀ���

		b.Print();
	}
}