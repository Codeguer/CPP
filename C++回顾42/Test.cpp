#include<iostream>
using namespace std;
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	void* operator new(size_t n)//专属
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1); // 内存池
		cout << "memory pool allocate" << endl;

		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
	public:
		List()
		{
			_head = new ListNode; // 全局operator new + 构造函数
			_head->_next = _head;
			_head->_prev = _head;
		}

		// void PushBack(int val);

		~List()
		{
			ListNode* cur = _head->_next;
			while (cur != _head)
			{
				ListNode* next = cur->_next;
				delete cur;
				cur = next;
			}

			delete _head;
			_head = nullptr;
		}

	private:
		ListNode* _head;
};

int main()
{
	List l;

	return 0;
}