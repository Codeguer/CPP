#include<iostream>
using namespace std;

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

		//static int GetN() // û��thisָ��,�����в��ܷ��ʷǾ�̬�ĳ�Ա��ֻ�ܷ��ʾ�̬��
		//{
		//	//_a = 10;��仰���У���Ϊû��thisָ����
		//	return n;
		//}
		 int GetN()//int &GetN()-��a1.GetN() = 10;���þͿ��Ը���
				//	static int GetN()->cout << A::GetN() << endl;��ΪGetN()�ǹ��е���
		{
			return n;
		}
	private:
		int _a;
		static int n;  // �˴�Ϊ����,��static�����ó�Ա��������ĳ������
		//������������ж������������n���ڶ����У�n�ھ�̬��
};

int A::n = 0;//����
//��̬��Ա�ھ�̬����ֻ�����������������������,�������������
//A& f1(A& a)
A f1(A a)
{
	return a;
}

int main()
{
	A a1;
	A a2;

	f1(a1);
	f1(a2);

	//a1.GetN() = 10;
	cout << a1.GetN() << endl;
	cout << a2.GetN() << endl;
	//cout << A::GetN() << endl;//�Ǿ�̬��Ա��Ҫ�ö������



	// ��nΪpublic
	/*cout << a1.n << endl;
	cout << a2.n << endl;
	cout << A::n << endl;
	a1.n = 10;*/

	//cout << n << endl;

	return 0;
}