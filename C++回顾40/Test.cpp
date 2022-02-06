#include <iostream>
using namespace std;
// ΪʲôC�������Ѿ���malloc/free��C++Ҳ�����ã����ǻ���Ҫnew/delete
// 1���������������new����malloc����һ����
// 2������Զ�������,new��Ҫ���ù��캯����ɳ�ʼ����delete��Ҫ�������������������
// ���ۣ�C++�н���ʹ��new/delete
// C
typedef struct ListNode_C
{
	int _val;
	struct ListNode_C* _next;
	struct ListNode_C* _prev;
}ListNode_C;
//typedef struct ListNode_C ListNode_C;
ListNode_C* BuyListNode_C(int val)
{
	ListNode_C* node_c = (ListNode_C*)malloc(sizeof(ListNode_C));
	node_c->_val = 1;
	node_c->_next = NULL;
	node_c->_prev = NULL;

	return node_c;
}

void DestoryListNode_C(ListNode_C* node);
//C++
struct ListNode_CPP
{
	int _val;
	struct ListNode_CPP* _next; // ����C struct���÷�
	ListNode_CPP* _prev;        // ��CPP�У�struct�Ѿ�������Ϊ���࣬��classһ����������Ĭ�Ϸ����޶���

	ListNode_CPP(int val = 0)
		:_val(val)
		, _next(nullptr)
		, _prev(nullptr)
	{
		cout << "ListNode_CPP(int val = 0)" << endl;
	}

	~ListNode_CPP()
	{
		cout << "~ListNode_CPP()" << endl;
	}
};

int main()
{
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;

	ListNode_C* node1 = BuyListNode_C(1);
	ListNode_C* node2 = BuyListNode_C(2);
	ListNode_C* node3 = BuyListNode_C(3);

	ListNode_CPP* node4 = new ListNode_CPP;
	ListNode_CPP* node5 = new ListNode_CPP(5);


	ListNode_CPP a[10];
	ListNode_CPP* p = new ListNode_CPP[10];
	delete[] p;

	free(node1);
	free(node2);
	free(node3);
	delete node4;
	delete node5;

	return 0;
}