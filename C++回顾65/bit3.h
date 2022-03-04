#include <iostream>
#include <string>
using namespace std;

//��̳�
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

	//void(*p)(); // ����һ������ָ�������C����ѧ���Ķ�������ȥ�úø�ϰһЩ����Ķ���
	typedef void(*VF_PTR)(); // ����ָ������void(*)()������ΪVF_PTR

	// ��ӡ���->�������һ���麯��ָ������
	//void PrintVFTable(VF_PTR* pTable)
	void PrintVFTable(int* pTable)
	{
		for (size_t i = 0; pTable[i] != 0; ++i)//�жϽ���������pTable[i] != 0
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
		//d�̳����������
		PrintVFTable((int*)(*(int*)&d));//��һ�����
		PrintVFTable((int*)(*(int*)((char*)&d + sizeof(Base1))));//�ڶ������
		
	}
}
