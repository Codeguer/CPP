#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//÷∏’Î
void swap_c(int*p, int*q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
//“˝”√
void swap_cpp(int &r1, int&r2)
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

int main()
{
	int a = 10;
	int b = 23;
	swap_c(&a, &b);
	swap_cpp(a, b);
	return 0;
}

