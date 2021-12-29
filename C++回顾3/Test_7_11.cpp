#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//函数重载：函数名相同，参数不同（类型/个数/顺序）
//对返回值没有要求,因为考虑这个的话，某一类型的变量接收函数调用的返回值
//具体调用哪个函数还需要看这个变量是什么类型的，这样函数调用就需要依赖上下文，效率就低了
//类型不同
int Add(int left, int right)
{return left + right;}

long Add(long left, long right)
{return left + right;}

double Add(double left, double right)
{return left + right;}
//顺序不同
void TestFunc1(int i, char ch){;}

void TestFunc1(char ch, int i){;}
//个数不同
void TestFunc2(int i, char ch){;}

void TestFunc2(int i){;}

void TestFunc2(){;}
//只是返回值不同无法构成重载
void TestFunc3() { ; }
//int TestFunc3() { ; }//会被报错
int main()
{
	//根据参数去识别相应的函数
	Add(10, 20);
	Add(10L, 20L);
	Add(10.0, 20.0); 
	
	return 0;
}