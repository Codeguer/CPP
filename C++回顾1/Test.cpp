//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>//����������ĺ�������������
//////using namespace std;//C++���пⶼʵ����std�������ռ���
////int main()
////{
////	int a = 10;
////	double b = 10.99;
////	std::cout << a << std::endl;//cout�����endl����
////	return 0;
////}
//
////using namespace std;//����д�Ļ������ռ��û�������ˣ�����������ͻ
////int main()
////{
////	int a = 10;
////	double b = 10.99;
////	cout << a << endl;
////	return 0;
////}
//
//
////�Դ󹤳̾���������
//using std::cout;//ֻҪ��������cout��ͬ���ֵ����Ϳ����ˣ��������Ա�֤std�����ռ����������������������ͻ
//using std::endl;
//using std::cin;
//int main()
//{
//	int a = 10;
//	double b = 10.99;
//	cout << a << endl;
//	cout << b << "\n";
//	cout << "\n";
//	cout << a <<" "<< b << endl;
//	cin >> a;//���뺯��
//	cout << a << endl;
//	printf("%d\n", a);//Ҳ��������ʹ��,C++����C����
//	scanf("%d", &a);
//	cout << a << endl;
//	return 0;
//}
//

#include<stdio.h>//C++����C����˻��ǿ���ʹ��C���Ե�
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
using N::b;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	return 0;
}

