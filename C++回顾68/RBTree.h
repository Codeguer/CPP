#pragma once
#include<utility>//多功能的
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
		//1、按搜索树的规则进行插入
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

		//新增的节点默认给红的还是黑的？
		//给红破坏第三条
		//给黑破坏第四条

		//第3条规则：不能有连续的红节点，这条破坏后只会影响一条路径上的
		//第4条规则：4.对于每个结点，从该结点到其所有后代叶结点的简单路径上，
		//均包含相同数目的黑色结点第四条规则破坏起来会影响到每条路径

		cur->_col = RED;//默认给红

		while (parent&&parent->_col == RED)
		{
			//红黑树的调节关键看叔叔
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node*uncle = grandfather->_right;
				//情况1：uncle存在，且为红
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}

				else//叔叔不存在或者叔叔存在且为黑
				{
					//情况三：双旋-》变为单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					//第二种情况：（有可能是第三种变过来的）
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}

			else 
			{
				Node*uncle = grandfather->_left;
				//uncle存在，且为红
				
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}

				else//uncle不存在 or uncle存在,且为黑
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
	//	//1.parent是这棵树的根，现在subR是根
	//	if (_root == parent)
	//	{
	//		_root = subR;
	//		subR->_parent = nullptr;
	//	}

	//	else//2、parent为根的树只是整颗树中的子树，改变链接关系，
	//		//那么subR要顶替他的位置
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
			_root = SubR;//给新的根
			SubR->_parent = nullptr;
		}

		parent->_right = SubRL;
		if (SubRL)//要判空
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