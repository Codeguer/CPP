#include"Func.h"
void F1(){
	cout << "void F1()" << endl;
}
template<class T>
void F2(const T&x)
{
	cout << "void F2(T&x)" << endl;
}
//�������2
//��ʾʵ����(�����ã���ͬ��������Ҫ���и��Ե�ʵ������
template
void F2<int>(const int&x);

template
void F2<double>(const double&x);

