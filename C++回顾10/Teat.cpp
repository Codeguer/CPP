#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a;//bΪint
	auto c = 'a';//cΪchar
	auto d = TestAuto();//dΪint
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
	return 0;
}