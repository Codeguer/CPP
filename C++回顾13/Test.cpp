#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//����һ����
//��װ
//1.�����ݺͷ���������һ��
//2.������㿴�������ݸ��㿴��������㿴�ķ�װ����->ʹ�÷����޶���
class Stack
{
public:
	//1����Ա����(��������
	void Push(int x);//���������������������涨��
	void Pop()//�������涨��
	{
		;
	}
	void Empty();
private:
	//2����Ա��������������
	int* _a;
	int _size;
	int _capacity;
};
//1��C������struct����������ṹ���
//2��C++�У�����C��struct����ṹ����÷�������ͬʱstructҲ��������������
//3��C++��ʹ��class��struct�����������Ĭ�ϵķ����޶���

//C����������ṹ���
struct ListNod_C
{
	int _val;
	struct ListNode_C *_next;
	struct ListNode_C *_prev;
};

//C++��
struct ListNode_CPP
{
	int _val;
	struct ListNode_C *_next;//C++����C�����￴����C���Զ���ṹ��ָ��
	ListNode_C *_prev;//C++��ϲ����������������Ի򷽷�

	//�����Զ��庯��->��Ա����
	ListNode_CPP* CreateNode(int val);
};

void Stack::Push(int x)//�����涨��
{
	;
}

class A//ֻ�����˳�Ա����
{
	int Add(int x, int y)
	{
		return x + y;
	}
};

class B//ֻ�����˳�Ա����
{
	int BVal;
};

class C//����
{};
int main()
{
	//��ʵ���������൱�ڶ��������ĳ�Ա�������Ա����
	Stack s1;
	Stack s2;
	Stack s3;
	s1.Push(1);

	//������ֻ�洢�˳�Ա���������洢��Ա����
	cout << sizeof(s1) << endl;//12
	//һ����ʵ������N������ÿ������ĳ�Ա���������Դ洢��ͬ��ֵ�����ǵ��õĺ�����ͬһ��
	//���ÿ�����󶼷ų�Ա����������Щ��Ա����ȴ��һ���ģ��˷ѿռ�

	//һ����ʵ��������Ĵ�С�����Ǽ�����Ա����֮�ͣ����ҿ����ڴ����
	//û�г�Ա��������Ķ����СΪ1����һ���ֽڲ���Ϊ�˴洢���ݣ�����ռλ��ʾ�ö������
	A a;
	A aa;
	A aaa;
	return 0;
}