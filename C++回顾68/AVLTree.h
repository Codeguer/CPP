#pragma once
#include<utility>
using std::pair;
using std::make_pair;

template<class K, class V>
struct AVTreeNode{
	AVTreeNode<K, V>*_left;//三叉链
	AVTreeNode<K, V>*_right;
	AVTreeNode<K, V>*_parent;

	int _bf;//balance factor 平衡因子,来判断是否出现需要处理的情况
	/*5	这不需要处理	5	这需要处理
	4   6                  6
							  7
	*/

	pair<K, V> _kv;

	AVTreeNode(const pair<K, V>&kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree{
	typedef AVTreeNode<K, V>Node;
public:
	bool Insert(const pair<K, V>&kv)
	{
		//1、先按搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node*parent = nullptr;
		Node*cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}

			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}

			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//2、更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			//下面是判断平衡因子是否需要继续更新以及平衡因子是否出现异常
			//3、如果更新完了，没有出现违反规则，则插入结束
						//有违反规则，则旋转处理
			if (parent->_bf == 0)
			{
				//说明parent所在的子树高度不变，更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//说明parent所在的子树的高度变了，继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent所在的子树出现不平衡了，需要进行旋转处理
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						//左单旋
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						//右左双旋
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						//右单旋
						RotateR(parent);
					}

					else if (cur->_bf == 1)
					{
						//左右双旋
						RotateLR(parent);
					}
				}
				//旋转完成后，子树的高度恢复到了插入节点前的高度
				//如果是子树那么对上一层没有影响，更新结束
				break;
			}
		}
		return true;
	}

	void RotateL(Node*parent)
	{
		Node*subR = parent->_right;
		Node*subRL = subR->_left;

		parent->_right = subRL;
		Node*ppNode = parent->_parent;
		parent->_parent = subR;

		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		//1.parent是这棵树的根，现在subR是根
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}

		else//2、parent为根的树只是整颗树中的子树，改变链接关系，
			//那么subR要顶替他的位置
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}

			else
			{
				ppNode->_right = subR;
			}

			subR->_parent = ppNode;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node*parent)
	{
		Node*subL = parent->_left;
		Node*subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		Node*ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
				subL->_parent = ppNode;
			}

			else
			{
				ppNode->_right = subL;
				subL->_parent = ppNode;
			}
		}
		parent->_bf = subL->_bf = 0;
	}

	//左右双旋
	void RotateLR(Node*parent)
	{
		Node*subL = parent->_left;
		Node*subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}

		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}

		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}

	}

	//右左双旋
	void RotateRL(Node*parent)
	{
		Node*subR = parent->_right;
		Node*subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);
		//主要是控制平衡因子,根据图来
		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}

		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
	}

//void RotateL(Node* parent)
//{
//	Node*SubR = parent->_right;
//	Node*SubRL = SubR->_left;
//
//	if (_root != parent)
//	{
//		Node* GrandFather = parent->_parent;
//		if (GrandFather->_left == parent)
//		{
//			GrandFather->_left = SubR;
//		}
//		else if (GrandFather->_right == parent)
//		{
//			GrandFather->_right = SubR;
//		}
//		SubR->_parent = GrandFather;
//	}
//	else
//	{
//		_root = SubR;//给新的根
//		SubR->_parent = nullptr;
//	}
//
//	parent->_right = SubRL;
//	if (SubRL)//要判空
//		SubRL->_parent = parent;
//
//	SubR->_left = parent;
//	parent->_parent = SubR;
//
//	parent->_bf = 0;
//	SubR->_bf = 0;
//}
//void RotateR(Node* parent)
//{
//	Node* SubL = parent->_left;
//	Node* SubLR = SubL->_right;
//
//	if (_root != parent)
//	{
//		Node*GrandFather = parent->_parent;
//		if (GrandFather->_left == parent)
//			GrandFather->_left = SubL;
//		else if (GrandFather->_right == parent)
//			GrandFather->_right = SubL;
//		SubL->_parent = GrandFather;
//	}
//	else
//	{
//		_root = SubL;
//		SubL->_parent = nullptr;
//	}
//
//	parent->_left = SubLR;
//	if (SubLR)
//	{
//		SubLR->_parent = parent;
//	}
//
//	SubL->_right = parent;
//	parent->_parent = SubL;
//
//	SubL->_bf = parent->_bf = 0;
//}
//void RotateLR(Node* parent)
//{
//	Node*SubL = parent->_left;
//	Node*SubLR = SubL->_right;
//	int SubLR_bf = SubLR->_bf;
//
//	RotateL(SubL);
//	RotateR(parent);
//
//	更新平衡因子
//	三种情况
//
//	if (SubLR_bf == 1)
//	{
//		SubL->_bf = -1;
//		SubLR->_bf = 0;
//		parent->_bf = 0;
//	}
//
//	else if (SubLR_bf == 0)
//	{
//		SubL->_bf = 0;
//		SubLR->_bf = 0;
//		parent->_bf = 0;
//	}
//
//	else if (SubLR_bf == -1)
//	{
//		SubL->_bf = 0;
//		SubLR->_bf = 0;
//		parent->_bf = 1;
//	}
//}
//void RotateRL(Node* parent)
//{
//	Node*SubR = parent->_right;
//	Node*SubRL = SubR->_left;
//	int SubRL_bf = SubRL->_bf;
//
//	RotateR(SubR);
//	RotateL(parent);
//
//	if (SubRL_bf == 0)
//	{
//		SubR->_bf = 0;
//		SubRL->_bf = 0;
//		parent->_bf = 0;
//	}
//
//	else if (SubRL_bf == 1)
//	{
//		SubR->_bf = 0;
//		SubRL->_bf = 0;
//		parent->_bf = -1;
//	}
//
//	else if (SubRL_bf == -1)
//	{
//		SubR->_bf = 1;
//		SubRL->_bf = 0;
//		parent->_bf = 0;
//	}
//}
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

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return lefeHeight > rightHeight ? lefeHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return abs(lefeHeight - rightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	Node*_root = nullptr;
};

void TestAVLTree(){
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a){
		t.Insert(make_pair(e, e));
	}

	t.InOrder();
	cout << t.IsBalance() << endl;
}

