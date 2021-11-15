#include <iostream>
#include <string>
using namespace std;

//ʹ����̳�
namespace bit5
{
	class A
	{
	public:
		A() { cout << "A()" << endl; }

		int _a = 1;
	};

	class B :virtual public A
	{
	public:
		B() { cout << "B()" << endl; }

		int _b = 2;
	};

	class C :virtual public A
	{
	public:
		C() { cout << "C()" << endl; }

		int _c = 3;
	};

	class D :public B, public C
	{
	public:
		D() { cout << "D()" << endl; }

		int _d = 4;
	};

	void test_bit5()
	{
		D d;
		//��ʾ���ÿ����ֱ��B��C�̳е�_a�ǲ���ͬһ��
		printf("%p\n", &d.B::_a);//00BCFC60
		printf("%p\n", &d.C::_a);//00BCFC60

		//�����Ѿ�û�ж����Ե������ˣ���˿��Ե���
		d._a;

		cout << endl;
		printf("&d._b=%p\n", &d._b);
		printf("&d._c=%p\n", &d._c);
		printf("&d._d=%p\n", &d._d);
		printf("&d._a=%p\n", &d._a);

		//������ʹ����Ϊ�˱�֤��Ƭ�����еĳ�Ա_a�޷�ֱ�ӽ�����Ƭ
		//�����������ķ�������֤��Ƭ�����罫B b=d,��ô���еĳ�Ա����ȥ
		//Ҫ��֤�Ǵ�B�̳�����_a���ܸ���ȥ�������Ǵ�C�̳�����_a����ʹ���ߵ�_a
		//��ͬһ��
	}
}