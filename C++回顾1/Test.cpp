//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>//输入输出语句的函数声明在这里
//////using namespace std;//C++所有库都实现在std的命名空间下
////int main()
////{
////	int a = 10;
////	double b = 10.99;
////	std::cout << a << std::endl;//cout输出，endl换行
////	return 0;
////}
//
////using namespace std;//这样写的话命名空间就没有作用了，会有命名冲突
////int main()
////{
////	int a = 10;
////	double b = 10.99;
////	cout << a << endl;
////	return 0;
////}
//
//
////对大工程经常这样做
//using std::cout;//只要不命名和cout相同名字的量就可以了，这样可以保证std命名空间里的其它量不会有命名冲突
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
//	cin >> a;//输入函数
//	cout << a << endl;
//	printf("%d\n", a);//也可以正常使用,C++兼容C语言
//	scanf("%d", &a);
//	cout << a << endl;
//	return 0;
//}
//

#include<stdio.h>//C++兼容C，因此还是可以使用C语言的
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

