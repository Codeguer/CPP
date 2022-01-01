#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

int Count1()
{
	static int n = 0;
	n++;
	return n;//返回的是临时变量tmp，其中int tmp=n，会多创一个空间给tmp	
}

int& Count2()
{
	static int n = 0;
	n++;
	return n;//返回的是临时变量tmp，其中int& tmp=n 	
}

int main()
{
	const int&r1 = Count1();//Count1()返回的tmp是临时变量，具有常属性，r1引用的是该临时变量
	int&r2 = Count2();//Count2()返回的是tmp，tmp是n的引用，因此r2也是n的引用，没有开辟空间给tmp,tmp是n的引用
	return 0;
}