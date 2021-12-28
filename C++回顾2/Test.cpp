#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>	
//#include"Test.h"
using namespace std;

//全缺省参数
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//半缺省参数
//这里必须从右往左依次缺省
void TestFunc2(int a, int b = 10, int c = 20)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
void TestFunc3(int c);
//void TestFunc3(int c=100){......}这样不行，会导致c重定义
//void TestFunc3(int c=1000){......}这样更不行，都不知道用那个值了
//void TestFunc3(){......}这样也不行，必须要有参数，因为声明是带了参数的
void TestFunc3(int c = 100)
{
	cout << "c = " << c << endl;
}

int main()
{
	//调用时必须从左到右依次传参
	cout << "TestFunc1() : " << endl;
	TestFunc1();

	cout << "TestFunc1(1) : " << endl;
	TestFunc1(1);

	cout << "TestFunc1(1,2) : " << endl;
	TestFunc1(1, 2);

	cout << "TestFunc1(1,2,3) : " << endl;
	TestFunc1(1, 2, 3);
	//TestFunc1(, , 3);//这样是不行的

	//不是缺省参数的a必须给值
	cout << "TestFunc2(1) : " << endl;
	TestFunc2(1);

	cout << "TestFunc2(1,2) : " << endl;
	TestFunc2(1, 2);

	cout << "TestFunc2(1,2,3) : " << endl;
	TestFunc2(1, 2, 3);

	cout << "TestFunc3() : " << endl;
	TestFunc3();
}