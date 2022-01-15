#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class String
{
	public:
		String(const char* str = "jack")//构造函数
		{
			_str = (char*)malloc(strlen(str) + 1);
			strcpy(_str, str);
		}
		~String()//析构函数
		{
			cout << "~String()" << endl;
			free(_str);
		}
	private:
		char* _str;
};

class Person
{
	private:
		String _name;//默认生成析构函数会调用该自定义类型的析构函数
		int _age;//默认生成析构函数不会对该类型做任何处理
};

int main()
{
	//我们不写，编译器便会默认生成析构函数
	//默认生成的析构函数对内置类型（基本类型）如int/char不会处理
	//而是会对自定义类型，调用它的析构函数完成清理工作
	Person p;
	return 0;
}