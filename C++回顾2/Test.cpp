#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>	
//#include"Test.h"
using namespace std;

//ȫȱʡ����
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//��ȱʡ����
//������������������ȱʡ
void TestFunc2(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
void TestFunc3(int c);
//void TestFunc3(int c=100){......}�������У��ᵼ��c�ض���
//void TestFunc3(int c=1000){......}���������У�����֪�����Ǹ�ֵ��
//void TestFunc3(){......}����Ҳ���У�����Ҫ�в�������Ϊ�����Ǵ��˲�����
void TestFunc3(int c = 100)
{
	cout << "c = " << c << endl;
}

int main()
{
	//����ʱ������������δ���
	cout << "TestFunc1() : " << endl;
	TestFunc1();

	cout << "TestFunc1(1) : " << endl;
	TestFunc1(1);

	cout << "TestFunc1(1,2) : " << endl;
	TestFunc1(1, 2);

	cout << "TestFunc1(1,2,3) : " << endl;
	TestFunc1(1, 2, 3);
	//TestFunc1(, , 3);//�����ǲ��е�

	//����ȱʡ������a�����ֵ
	cout << "TestFunc2(1) : " << endl;
	TestFunc2(1);

	cout << "TestFunc2(1,2) : " << endl;
	TestFunc2(1, 2);

	cout << "TestFunc2(1,2,3) : " << endl;
	TestFunc2(1, 2, 3);

	cout << "TestFunc3() : " << endl;
	TestFunc3();
}