#include <iostream>
#include <string>
using namespace std;

//1�������࣬�����಻�ɱ��̳У�����C++11������
//�಻�ɱ��̳еķ�����������private�����캯����Ϊ˽������C++98������
//2�������麯�����������麯�����ɱ��̳�
//3��������ͨ�����������ú������ɱ��̳�

class A //final
{
public:
	//virtual void func(int val = 1) final{ std::cout << "A->" << val << std::endl; }
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};
class B : public A
{
public:
	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
void test_bit5()
{
	B*p = new B;
	p->test();
}