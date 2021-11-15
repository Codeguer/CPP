#include <iostream>
#include <string>
using namespace std;

namespace bit3
{
	class A
	{
	public:
		A(int a = 1) :_a(a) { cout << "A()" << endl; }
		A(const A&p) :_a(p._a) { cout << "A(const A&p)" << endl; }
		A operator=(const A&p) { cout << "A operator=" << endl; return *this; }
		void Print() { cout << "Print():" << endl; }
		~A() { cout << "~A" << endl; }
	protected:
		int _a;
	};

	class B :public A
	{
	public://�������й��캯��ʱ������Բ��õ��ã�ϵͳ���Զ����ø����
//������û�ж�Ӧ�Ĺ��캯������Ĺ��캯��һ��Ҫ���ø���Ĺ��캯��
		//�����ȵ��ø���Ĺ��캯��������Ҫ�ڳ�ʼ���б��н��е�
		B(int b = 4) :A(3), _b(b) { cout << "B()" << endl; }

		//����Ŀ������캯��������ø���Ŀ������캯��
		B(const B&p) :_b(p._b),A(p) { cout << "B(const B&p)" << endl; }

		B operator=(const B&p) { A::operator=(p); _b = p._b; cout << "B operator=" << endl; return *this; }
		//��������������ȵ��ã�������ɺ�Ȼ���Զ����ø������������
		~B() { cout << "~B()"<< endl; }
	protected:
		int _b = 2;
	};

	void test_bit3()
	{
		B b;
		B Bb = b;
		b = Bb;
	}
}