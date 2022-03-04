#include <iostream>
#include <string>
using namespace std;

namespace bit2
{
	//���̳�
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

	//void(*p)(); // ����һ������ָ�������C����ѧ���Ķ�������ȥ�úø�ϰһЩ����Ķ���
	typedef void(*VF_PTR)(); // ����ָ������void(*)()������ΪVF_PTR

	void PrintVFTable1(VF_PTR *pTable)
	{
		for (size_t i = 0; pTable[i] != 0; ++i)//�жϽ���������pTable[i] != 0
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

	//��ӡ���->�������һ���麯��ָ������
   //void PrintVFTable(VF_PTR* pTable)
	void PrintVFTable(int *pTable)//VF_PTR *pTable��ͬ��VF_PTR pTable[]
	{
		for (size_t i = 0; pTable[i] != 0; ++i)//�жϽ���������pTable[i] != 0
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
		//*(int*)&a����vfptr,ע�⣺vfptr��ʵ����int���͵ı���������������ĵ�ַ
		//PrintVFTable((VF_PTR*)(*(int*)&a));//VF_PTR vptr[0]
		PrintVFTable((int*)(*(int*)&b));

		printf("%p\n", *((int*)&b));
		cout << *((int*)&b+1) << endl;//*((int*)&b + 1)����_a
		cout << *((int*)&b + 2) << endl;
		//*((int*)&b + 2)����_b
	}

	
}
