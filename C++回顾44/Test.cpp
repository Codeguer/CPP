#include<iostream>
using namespace std;
//泛型编程
 //模板 -> 写跟类型无关的代码
 //函数模板
//template<class T>
template<typename T>    // 模板参数-》类型
void Swap(T& x1, T& x2)
{
	T x = x1;
	x1 = x2;
	x2 = x;
	//x2=x当该模板未实例化，这句少了分号也没报错，因为编译器不编译这个函数，该函数是一个模板
	//对函数里的内容不作检查
}

 //下面调用的是否是同一个函数？
 //不是
 //这里我们不能调用函数模板，调用的是函数模板实例化生成的对应类型的函数
int main()
{
	int a = 0, b = 1;
	Swap(a, b);

	double c = 1.11, d = 2.22;
	Swap(c, d);

	char e = 'a', f = 'b';
	Swap(e, f);

	return 0;
}