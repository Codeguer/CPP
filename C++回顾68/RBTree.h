#pragma once
#include<utility>//�๦�ܵ�
using std::pair;
using std::make_pair;
enum Colour
{
	BLACK
	, RED
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K,V>*_left;
	RBTreeNode<K,V>*_right;
	RBTreeNode<K,V>*_parent;

	pair<K,V> _kv;

	Colour _col;

	RBTreeNode(const pair<K,V>&kv)
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _col(RED)
		, _kv(kv)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	bool Insert(const pair<K,V>& kv)
	{
		//1�����������Ĺ�����в���
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent =nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first<kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}

			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first<cur->_kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//�����Ľڵ�Ĭ�ϸ���Ļ��Ǻڵģ�
		//�����ƻ�������
		//�����ƻ�������

		//��3�����򣺲����������ĺ�ڵ㣬�����ƻ���ֻ��Ӱ��һ��·���ϵ�
		//��4������4.����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ�
		//��������ͬ��Ŀ�ĺ�ɫ�������������ƻ�������Ӱ�쵽ÿ��·��

		cur->_col = RED;//Ĭ�ϸ���

		while (parent&&parent->_col == RED)
		{
			//������ĵ��ڹؼ�������
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node*uncle = grandfather->_right;
				//���1��uncle���ڣ���Ϊ��
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}

				else//���岻���ڻ������������Ϊ��
				{
					//�������˫��-����Ϊ����
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//�ڶ�����������п����ǵ����ֱ�����ģ�
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}

			else 
			{
				Node*uncle = grandfather->_left;
				//uncle���ڣ���Ϊ��
				
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}

				else//uncle������ or uncle����,��Ϊ��
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}

					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
		}
		
		_root->_col = BLACK;

		return true;
	}

	//void RotateL(Node*parent)
	//{
	//	Node*subR = parent->_right;
	//	Node*subRL = subR->_left;

	//	parent->_right = subRL;
	//	Node*ppNode = parent->_parent;
	//	parent->_parent = subR;

	//	if (subRL)
	//		subRL->_parent = parent;

	//	subR->_left = parent;
	//	//1.parent��������ĸ�������subR�Ǹ�
	//	if (_root == parent)
	//	{
	//		_root = subR;
	//		subR->_parent = nullptr;
	//	}

	//	else//2��parentΪ������ֻ���������е��������ı����ӹ�ϵ��
	//		//��ôsubRҪ��������λ��
	//	{
	//		if (ppNode->_left == parent)
	//		{
	//			ppNode->_left = subR;
	//		}

	//		else
	//		{
	//			ppNode->_right = subR;
	//		}

	//		subR->_parent == ppNode;
	//	}

	//}

	//void RotateR(Node*parent)
	//{
	//	Node*subL = parent->_left;
	//	Node*subLR = subL->_right;

	//	parent->_left = subLR;
	//	if (subLR)
	//	{
	//		subLR->_parent = parent;
	//	}

	//	subL->_right = parent;
	//	Node*ppNode = parent->_parent;
	//	parent->_parent = subL;

	//	if (_root == parent)
	//	{
	//		_root = subL;
	//		subL->_parent = nullptr;
	//	}
	//	else
	//	{
	//		if (ppNode->_left == parent)
	//		{
	//			ppNode->_left = subL;
	//			subL->_parent = ppNode;
	//		}

	//		else
	//		{
	//			ppNode->_right = subL;
	//			subL->_parent = ppNode;
	//		}
	//	}
	//}

	void RotateL(Node* parent)
	{
		Node*SubR = parent->_right;
		Node*SubRL = SubR->_left;

		if (_root != parent)
		{
			Node* GrandFather = parent->_parent;
			if (GrandFather->_left == parent)
			{
				GrandFather->_left = SubR;
			}
			else if (GrandFather->_right == parent)
			{
				GrandFather->_right = SubR;
			}
			SubR->_parent = GrandFather;
		}
		else
		{
			_root = SubR;//���µĸ�
			SubR->_parent = nullptr;
		}

		parent->_right = SubRL;
		if (SubRL)//Ҫ�п�
			SubRL->_parent = parent;

		SubR->_left = parent;
		parent->_parent = SubR;
	}
	void RotateR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		if (_root != parent)
		{
			Node*GrandFather = parent->_parent;
			if (GrandFather->_left == parent)
				GrandFather->_left = SubL;
			else if (GrandFather->_right == parent)
				GrandFather->_right = SubL;
			SubL->_parent = GrandFather;
		}
		else
		{
			_root = SubL;
			SubL->_parent = nullptr;
		}

		parent->_left = SubLR;
		if (SubLR)
		{
			SubLR->_parent = parent;
		}

		SubL->_right = parent;
		parent->_parent = SubL;

	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	Node* Find(const K&key)
	{
		Node*cur = _root;
		while (cur)
		{
			if (cur->_kv.first<key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
private:
	Node*_root = nullptr;
};

void TestRBTTree()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();
}