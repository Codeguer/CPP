#include"bit1.h"
#include"bit2.h"
#include"bit3.h"
#include"bit4.h"
#include"bit5.h"
#include"bit6.h"
#include"bit7.h"
int main()
{
	//bit1::test_bit1();
	//bit2::test_bit2();
	//bit3::test_bit3();
	//bit4::test_bit4();
	//bit5::test_bit5();
	bit6::test_bit6();
	//bit7::test_bit7();
	return 0;
}






//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//
//private:
//	int _a;
//	char _ch;
//};
//int main()
//{
//	//cout << sizeof(Person) << endl;
//
//	return 0;
//}

//class Person {
//public:
//	void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//
//	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��Ϊ�̳к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶������������ʹ��*/
//	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//};
//
//void Func(Person* p)
//{
//	p->BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(&ps);
//	Func(&st);
//
//	return 0;
//}