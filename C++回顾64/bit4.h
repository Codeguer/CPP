#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bit4
{
	class Base
	{
	public:
		virtual void Func1()
		{
			cout << "Base::Func1()" << endl;
		}

		virtual void Func2()
		{
			cout << "Base::Func2()" << endl;
		}

		void Func3()
		{
			cout << "Base::Func3()" << endl;
		}

	private:
		int _b = 1;
	};

	class Derive : public Base
	{
	public:
		virtual void Func1()
		{
			cout << "Derive::Func1()" << endl;
		}
	private:
		int _d = 2;
	};
	
	void func()
	{
		// ȡ�������ǰ4���ֽ�
		Base b1;
		printf("vftptr����ַ:%p\n", *(int*)&b1);
		//printf("vftptr:%p\n", (int)b1); //ֱ��ת�﷨�����ܣ�������ָ��ת���ٽ�����


		int i = 0;
		int* p1 = &i;
		int* p2 = new int;
		const char* p3 = "hello";
		printf("ջ����:%p\n", p1);
		printf("�ѱ���:%p\n", p2);
		printf("����γ���:%p\n", p3);
		printf("�麯����ַ:%p\n", &Base::Func1);// &Base::Func1���ǹ涨Ҫ��������ȡ��������ַ
		//����ͨ�����ĺ��������ǵ�ַ
		printf("��ͨ������ַ:%p\n", func);
		printf("��ͨ������ַ:%p\n", &Base::Func3);//������ǰ����::ָ���˷�Χ��ô����Ҫ��&����ȡ��������ַ
	}

	void f1(int i)
	{}

	void f1(double d)
	{}

	

	int test_bit4()
	{
		func();

		//����ʱ�ǰ����������м�����﷨��ָ�����ɵȵȣ����ɵ���һ����ִ�е��ļ�
		//����ʱ�Ǵ���һ���ӽ��̣���ͨ��esgc�����ķ�ʽ�����Ķθ��滻����
		//��Ҫ���滻���ݶ������Σ���Ȼ��������һЩ�������������ͽ�����̬��̬
		//ƽʱ��ָ�Ķ�̬�Ƕ�̬�Ķ�̬

		int i = 0;
		double d = 1.1;
		// ��̬�� ��̬�Ķ�̬   (��̬������ʱȷ��������ַ)  
		f1(i);
		f1(d);

		// ��̬��  ��̬�Ķ�̬  ����̬������ʱ����������麯����ַ��
		//һ������ָ�Ķ�̬���Ƕ�̬��̬
		Base* p = new Base;
		p->Func1();
		p = new Derive;
		p->Func1();

		return 0;
	}
}