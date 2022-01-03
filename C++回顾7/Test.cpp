#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int& Add(int a, int b)
{
	int c = a + b;
	/*static int c = 0;
	 c = a + b;;*/
	return c;
}

int main()
{
	int& ret = Add(1, 2);//ret指向了c的空间，此时c已经被销毁了
	Add(3, 4);//返回的c和第一次调用的c的空间恰好是同一个内存空间，因此ret的值变了
	//在release下会被优化，第二次调用创建的c和第一次的c不是同一个内存空间，因此ret的值未被修改
	//这样引用局部变量是不安全的，因为别人可以通过其它途径修改ret的值
	cout << "Add(1, 2) is :" << ret << endl;//ret为7
	return 0;
}
