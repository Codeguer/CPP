#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>	
#define MAX(a,b) (a+b)
inline int Add(int a, int b)
{
	return a + b;
}

int ADD(int a, int b)
{
	return a + b;
}


int main()
{
	int ret = 0;
	//展开为ret=(a+b);
	ret = MAX(5, 3);

	ret=Add(5, 3);//Add函数会在这里展开，不会再去调用Add函数了
	
	ret = ADD(5, 3);
	
	return 0;
}