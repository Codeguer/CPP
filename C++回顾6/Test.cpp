#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

int Count1()
{
	static int n = 0;
	n++;
	return n;//���ص�����ʱ����tmp������int tmp=n����ഴһ���ռ��tmp	
}

int& Count2()
{
	static int n = 0;
	n++;
	return n;//���ص�����ʱ����tmp������int& tmp=n 	
}

int main()
{
	const int&r1 = Count1();//Count1()���ص�tmp����ʱ���������г����ԣ�r1���õ��Ǹ���ʱ����
	int&r2 = Count2();//Count2()���ص���tmp��tmp��n�����ã����r2Ҳ��n�����ã�û�п��ٿռ��tmp,tmp��n������
	return 0;
}