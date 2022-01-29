#include<iostream>
using namespace std;
//staic成员
 //设计出一个类A，可以计算这个类总计产生了多少对象?
int n = 0;
class A
{
	public:
		A()
		{
			++n;
		}

		A(const A& a)
		{
			++n;
		}
};

//A& f1(A& a)
A f1(A a)//定义了一个函数
{
	return a;
}

int main()
{
	A a1;
	A a2;

	f1(a1);//a1拷贝给a,a拷贝给临时变量，并返回该临时变量
	//n = 1; //缺点谁都可以对n进行修改
	f1(a2);

	cout << n << endl;//输出为6

	return 0;
}