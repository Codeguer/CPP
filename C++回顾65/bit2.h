#include <iostream>
#include <string>
using namespace std;

namespace bit2
{
	//单继承
	class Base {
	public:
		virtual void func1() { cout << "Base::func1" << endl; }
		virtual void func2() { cout << "Base::func2" << endl; }
	private:
		int _a=1;
	};

	class Derive :public Base {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
		virtual void func4() { cout << "Derive::func4" << endl; }
	private:
		int _b=2;
	};

	//void(*p)(); // 定义一个函数指针变量，C语言学过的东西，回去好好复习一些这里的东西
	typedef void(*VF_PTR)(); // 函数指针类型void(*)()重命名为VF_PTR

	void PrintVFTable1(VF_PTR *pTable)
	{
		for (size_t i = 0; pTable[i] != 0; ++i)//判断结束条件：pTable[i] != 0
		{
			printf("vfTable[%d]:%p->", i, pTable[i]);
			VF_PTR f = pTable[i];
			f();
		}
		cout << endl;
	}

	void test1_bit2() {
		Base b;
		Derive d;

		PrintVFTable1((VF_PTR*)(*(int*)&b));
		PrintVFTable1((VF_PTR*)(*(int*)&d));

	}

	//打印虚表->虚表本质是一个虚函数指针数组
   //void PrintVFTable(VF_PTR* pTable)
	void PrintVFTable(int *pTable)//VF_PTR *pTable等同于VF_PTR pTable[]
	{
		for (size_t i = 0; pTable[i] != 0; ++i)//判断结束条件：pTable[i] != 0
		{
			printf("vfTable[%d]:%p->", i, pTable[i]);
			VF_PTR f = (VF_PTR)pTable[i];
			f();
		}
		cout << endl;
	}

	void test_bit2() {
		Base a;
		Derive b;
		//*(int*)&a就是vfptr,注意：vfptr其实就是int类型的变量存放了虚表数组的地址
		//PrintVFTable((VF_PTR*)(*(int*)&a));//VF_PTR vptr[0]
		PrintVFTable((int*)(*(int*)&b));

		printf("%p\n", *((int*)&b));
		cout << *((int*)&b+1) << endl;//*((int*)&b + 1)就是_a
		cout << *((int*)&b + 2) << endl;
		//*((int*)&b + 2)就是_b
	}

	
}
