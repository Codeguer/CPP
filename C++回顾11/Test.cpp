#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);//f(int)
	f(NULL);//f(int)
	f((int*)NULL);//f(int*)
	f(nullptr);//f(int*)
	//int a = 111;
	//int *p = &a;
	//p = (int*)0;
	return 0;
}

