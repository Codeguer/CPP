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
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
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
//	void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议这样使用*/
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
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