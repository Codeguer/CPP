#pragma once
#include<iostream>
using namespace std;
void F1();

//解决方法1
//模板定义与声明不要进行分离
template<class T>
void F2(const T&x){
	cout << "void F2(T&x)" << endl;
}

