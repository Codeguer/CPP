#include <iostream>
#include <string>
using namespace std;

//�ڴ����ģ�ͣ��������ڴ�������ô��ģ���
//ͨ���ڴ洰�ڽ��е���
namespace bit6
{
	class A
	{
	public:
		//int _a[10000];//��������еĳ�Ա�ܴ���ô��̳о��ܽ�ʡ�ܶ�ռ�
		int _a;
	};

	class B : virtual public A
	{
	public:
		int _b;
	};

	class C : virtual public A
	{
	public:
		int _c;
	};

	class E
	{
	public:
		int _a;
	};

	class D : public B, public C,public E
	{
	public:
		int _d;
	};

	/*class D : public B, public C
	{
	public:
		int _d;
	};*/

	void test_bit6()
	{
		D d;
		cout << sizeof(d) << endl;   

		d.B::_a = 1;
		d.C::_a = 2;
		d.E::_a = 3;
		d._b = 4;
		d._c = 5;
		d._d = 6;
		

		B b;
		C c;
		E e;
		//��Ϊû���������μ̳���ô����ֱ���ҵ���Ӧ��_aȻ���й�ȥ
		b = d;//����B�̳�����_a�и���b
		c = d;//����C�̳�����_a�и���c
		e = d;//����E�̳�����_a�и���c
		//�����������μ̳���ô��d������_aֻ�����ݣ������ݾ����Ǵ�˭����̳�����
		//ͨ�����������ҵ�
	}
}