#include <iostream>
using namespace std;
//Э��(�������������麯������ֵ���Ͳ�ͬ)
//��������д�����麯��ʱ��������麯������ֵ���Ͳ�ͬ��
//�������麯�����ػ�������ָ��������ã�
//�������麯����������������ָ���������ʱ����ΪЭ�䡣
namespace bit2
{
	class Person {
	public:
		//virtual void BuyTicket() { cout << "Person:��Ʊ-ȫ��" << endl; }
		virtual Person* BuyTicket() { cout << "Person:��Ʊ-ȫ��" << endl; return nullptr; }
		//��������ָ��������ò�һ������Person��������Ҳ��һ������Student
	};
	class Student : public Person {
	public:
		//virtual void BuyTicket() { cout << "Student:��Ʊ-���" << endl; }
		virtual Student* BuyTicket() { cout << "Student:��Ʊ-���" << endl; return nullptr; }
	};
	void Func(Person& p)
	{
		p.BuyTicket();
	}
	void test()
	{
		Person ps;
		Student st;
		Func(ps);
		Func(st);
	}
}

namespace bit3
{
	class A {};
	class B : public A {};//������Ǽ̳й�ϵ����ͻᱨ��

	class Person {
	public:
		virtual A* f() { cout << "Person:��Ʊ-ȫ��" << endl; return nullptr; }
	};

	class Student : public Person {
	public:
		virtual B* f() { cout << "Student:��Ʊ-���" << endl; return nullptr; }
	//B* f() { cout << "Student:��Ʊ-���" << endl; return nullptr; }
		//ע���ˣ�����������ȥ����virtual��Ҳ��ǿ�Ͽ�Ϊ��̬�������淶
		//����ľ��Բ���ȥ��
	};

	void Func(Person& p)
	{
		p.f();
	}
	void test()
	{
		Person ps;
		Student st;
		Func(ps);
		Func(st);
	}
}