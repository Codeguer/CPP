#include <iostream>
#include <string>
using namespace std;

//多继承
namespace bit3
{
	class Base1 {
	public:
		virtual void func1() { cout << "Base1::func1" << endl; }
		virtual void func2() { cout << "Base1::func2" << endl; }
	private:
		int b1;
	};

	class Base2 {
	public:
		virtual void func1() { cout << "Base2::func1" << endl; }
		virtual void func2() { cout << "Base2::func2" << endl; }
	private:
		int b2;
	};

	class Derive : public Base1, public Base2 {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
	private:
		int d1;
	};

	//void(*p)(); // 定义一个函数指针变量，C语言学过的东西，回去好好复习一些这里的东西
	typedef void(*VF_PTR)(); // 函数指针类型void(*)()重命名为VF_PTR

	// 打印虚表->虚表本质是一个虚函数指针数组
	//void PrintVFTable(VF_PTR* pTable)
	void PrintVFTable(int* pTable)
	{
		for (size_t i = 0; pTable[i] != 0; ++i)//判断结束条件：pTable[i] != 0
		{
			printf("vfTable[%d]:%p->", i, pTable[i]);
			VF_PTR f =(VF_PTR) pTable[i];
			f();
		}
		cout << endl;
	}

	void test_bit3()
	{
		Derive d;
		cout << sizeof(Derive) << endl;//20
		//d继承了两张虚表
		PrintVFTable((int*)(*(int*)&d));//第一个虚表
		PrintVFTable((int*)(*(int*)((char*)&d + sizeof(Base1))));//第二个虚表
		
	}
}
