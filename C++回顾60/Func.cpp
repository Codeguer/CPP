#include"Func.h"
void F1(){
	cout << "void F1()" << endl;
}
template<class T>
void F2(const T&x)
{
	cout << "void F2(T&x)" << endl;
}
//解决方法2
//显示实例化(不常用，不同的类型需要进行各自的实例化）
template
void F2<int>(const int&x);

template
void F2<double>(const double&x);

