#include<iostream>
using namespace std;
//staic��Ա
 //��Ƴ�һ����A�����Լ���������ܼƲ����˶��ٶ���?
int n = 0;
class A
{
	public:
		A()
		{
			++n;
		}

		A(const A& a)
		{
			++n;
		}
};

//A& f1(A& a)
A f1(A a)//������һ������
{
	return a;
}

int main()
{
	A a1;
	A a2;

	f1(a1);//a1������a,a��������ʱ�����������ظ���ʱ����
	//n = 1; //ȱ��˭�����Զ�n�����޸�
	f1(a2);

	cout << n << endl;//���Ϊ6

	return 0;
}