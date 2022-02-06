#include <iostream>
using namespace std;
// 为什么C语言中已经有malloc/free，C++也可以用，但是还需要new/delete
// 1、针对内置类型用new还是malloc都是一样的
// 2、针对自定义类型,new还要调用构造函数完成初始化，delete还要调用析构函数完成清理
// 结论：C++中建议使用new/delete
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
	struct ListNode_CPP* _next; // 兼容C struct的用法
	ListNode_CPP* _prev;        // 在CPP中，struct已经可以认为是类，和class一样，区别是默认访问限定符

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