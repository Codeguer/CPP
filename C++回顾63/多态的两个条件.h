#include <iostream>
using namespace std;

//virtual�ؼ��֣�1����������̳�
			   //2�������麯��
//��̳����麯��û��һ���ϵ

//��̬������������
//1���麯������д�����������Ի�����麯��������д��
//2����������ָ���������ȥ�����麯��

//�����̬�������ö���������޹أ���ָ������йأ�ָ���ĸ�������þ��������麯��
//�������̬�������ö���������йأ�������ʲô���õľ���˭���麯��,ֻ��Ҫ����̬������
			//����ȥ��һ���Ϳ�����

namespace bit1
{
	class Person {
	public:
		virtual void BuyTicket() { cout << "Person:��Ʊ-ȫ��" << endl; }
		// void BuyTicket() { cout << "Person:��Ʊ-ȫ��" << endl; }
	};
	class Student : public Person {
	public:
		virtual void BuyTicket() { cout << "Student:��Ʊ-���" << endl; }
		/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��Ϊ��
	�к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶������������ʹ��
	*/
	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
	};

	//���õ�������Ķ�����Դ�������Ķ���/ָ��/����
	void Func(Person& p)//��Ʊ����
		//void Func(Person* p)//����Ҳ���Թ��ɶ�̬
		//void Func(Person p)//����͹��ɲ��˶�̬��
	{
		p.BuyTicket();//�麯���ĵ��ù�ϵ��this -> vptr -> vtable ->virtual function
	}
	void test()
	{
		Person ps;
		Student st;
		//st.BuyTicket();ֱ��ͨ����������Ҳ���ԣ����ⲻ�Ƕ�̬
		Func(ps);//��ps������а�ȫ����Ʊ�ķ�ʽ����
		Func(st);//��st������а������Ʊ�ķ�ʽ����
	}
}
//��̬���������+���õ��˶�̬�����ԣ�+���Զ�������֮�䡢������֮�䡢�������в�ͬ��ʽ������