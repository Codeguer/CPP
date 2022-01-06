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
	auto b = a;//b为int
	auto c = 'a';//c为char
	auto d = TestAuto();//d为int
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
	return 0;
}