#include <iostream>
#include <string>
using namespace std;

namespace bit5
{
	class A
	{
	public:
		virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
		virtual void test() { func(); }
	};
	class B : public A
	{
	public:
		void func(int val = 0) { std::cout << "B->" << val << std::endl; }
		//������麯����������д������Ҫע����ǽ����ǶԺ������е����ݽ�������д
		//�������䣬��������val��ʲôȱʡֵ����û���õ�
	};
	void test_bit5()
	{
		B*p = new B;
		p->test();//��һ������Ϊtest()û�б���д������ֱ�Ӽ̳У�Ȼ������Լ���func()
		
	}
}



