#include <iostream>
#include <string>
using namespace std;

//���麯�������ã�
//1��ǿ������ȥ�����д
//2����ʾ���������
namespace bit6
{
	//�������麯�������Ϊ������
	class Car
	{
	public:
		virtual void Drive() = 0;//���麯��
	};

	class Benz :public Car
	{
	public:
		virtual void Drive()
		{
			cout << "Benz-����" << endl;
		}
	};

	class BMW :public Car
	{
	public:
		virtual void Drive()
		{
			cout << "BMW-�ٿ�" << endl;
		}
	};
	void Test()
	{
		//Car car;�����������ʵ��������
		Benz bz;//��д���麯������ʵ�������󣬲�ȻBenzҲ�Ǹ�������
		Car* pBenz = new Benz;
		pBenz->Drive();
		Car* pBMW = new BMW;
		pBMW->Drive();
	}
}