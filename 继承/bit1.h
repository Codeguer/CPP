#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit1
{
	class A
	{
	public:
		void Print() { cout << "Print():" << endl; }
	protected:
		int _a = 1;
	};

	class B :public A
	{

	protected:
		int _b = 2;
	};

	void test_bit1()
	{
		
		B b;

		A a = b;
		A&c = b;
		A*d = &b;
	
		//�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
		B *Bb = (B*)d;
		Bb->Print();//�����ָ��ָ������Ķ�����������ǿ��Ե�

		A*Ab = &a;//�����ָ��ָ����Ķ������������ʱ���������
		B*Bb1 = (B*)Ab;
		Ab->Print();//���ܴ���Խ�����
		//b=a;//���������ֱ�Ӹ�ֵ���������
		b.Print();
		
	}
}


