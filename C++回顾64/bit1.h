#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace bit1
{
	class Base
	{
	public:
		virtual void Func1()
		{
			cout << "Func1()" << endl;
		}

		virtual void Func2()
		{
			cout << "Func2()" << endl;
		}

		void Func3()//��ͨ���������˴����
		{
			cout << "Func3()" << endl;
		}
	private:
		int _b = 1;
	};


	int test_bit1()
	{
		cout << sizeof(Base) << endl;//8,����һ��ָ�룬��ָ��Ϊ_vftptr,ָ��һ���麯����
		//ָ��ȫ��Ϊ�麯����ָ�룬������ָ��
		//�麯�������麯���ĵ�ַ���麯�����ʾ���һ������ָ������

//Ϊʲô�����麯��ֱ�ӷŵ�������ȥ�أ���Ϊ����һ�㲻�����ͨ�������麯����
//Ϊ��ʵ�ֶ�̬�����������麯���Ļ����ܲ�ֹһ���麯�����ͻ�ʹ������󣬴Ӷ�Ч�ʽ���
		//Ϊ�˷�ֹ������󣬾�����ָ��ָ��һ���麯����
		Base b;

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		return 0;
	}
}
