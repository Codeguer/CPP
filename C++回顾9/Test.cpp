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
	//չ��Ϊret=(a+b);
	ret = MAX(5, 3);

	ret=Add(5, 3);//Add������������չ����������ȥ����Add������
	
	ret = ADD(5, 3);
	
	return 0;
}