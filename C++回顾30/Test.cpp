//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public://��ʼ���б��Ƕ���ĳ�Ա�����Ķ���ĵط�
//	B(int a, int ref)
//		:_aobj(a)
//		
//		, _n(10)
//		, _ref(ref)
//	{//�������ڸ�ֵ//��B���ù��캯��������һ��ʱ_aobj _n _x�Ѿ������ֵ��
//		//����_aobj��_n _ref������г�ʼ������ᱨ��_ref��Ϊ�����������޷���ȡ�ڴ�
//		_x = 10;//��ֵ
//	}
//private://��Ա����������
//	A _aobj; // û��Ĭ�Ϲ��캯��(Aû�����Ǹ�����Ҫ���ε�Ĭ�Ϲ��캯��)
//	//�Զ����ҲΪĬ�Ϲ��캯��
//	int& _ref; // ����
//	const int _n; // const
//	int _x;
//};
//
//int main()
//{
//	B b(1, 2);//�����壬�����ڵĳ�Ա������Ҫ�������ˣ�ֻ����Щ����ͨ����ʼ���б��岢��ʼ��������_x��ֱ�ӱ����壬Ȼ��ͨ���ں������ڽ��и�ֵ
//	return 0;
//}
//

#include<iostream>
using namespace std;
class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)//����δʹ�ó�ʼ���б�
	{
		Time t(day);//����Time�ĳ�ʼ���б��t���г�ʼ��
		_t = t;//Ĭ�ϵĸ�ֵ�����
	}
private:
	int _day;
	Time _t;// �����Զ������ͳ�Ա������һ������ʹ�ó�ʼ���б��ʼ����

};

//class Date
//{
//	public:
//		Date(int day)
//			:_t(day)//����Time���вι��캯�����г�ʼ��
//		{}
//	private:
//		int _day;
//		Time _t;
//};
int main()
{
	Date d(1);//���ȵ���Date��Ĭ�Ϲ��캯��

	return 0;
}

