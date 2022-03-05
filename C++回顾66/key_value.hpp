#pragma once
#include <iostream>
#include <string>
using namespace std;

//二叉搜索树的修改其key是不能修改的，修改了那么就不是二叉搜索树了
//如果是kv模式的话，那么其value是可以修改的

//场景：中英文互译,其搜索效率为log(N)
	//  统计次数
//如果插入的数据是有序的或者接近有序，那么其效率就得不到保证了
//如1 2 3 4 5 6 7
/*1
	2
	  3
	    4
		  5
		    6
			  7
			  那么在这种最坏的情况下是O(N)
			  如何解决：平衡树
			  1、AVLTree
			  2、红黑树*/
namespace bit3
{
	template<class K, class V>
	struct BSTreeNode // Binary Search Tree Node
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;

		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree // Binary Search Tree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
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

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)//先找
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 找到了，开始删除
					// 1、左为空
					// 2、右为空
					// 3、左右都不为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_right == cur)
								parent->_right = cur->_right;
							else
								parent->_left = cur->_right;
						}


						delete cur;

					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;

						}
						delete cur;
					}
					else
					{
						// 这里的逻辑还有问题？
						Node* rightMinParent = cur;//这里改一下
						Node* rightMin = cur->_right;
						while (rightMin->_left)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}
						// 替代删除吗
						cur->_key = rightMin->_key;
						cur->_value = rightMin->_value;

						// 转换成删除rightMin
						if (rightMin == rightMinParent->_left)
							rightMinParent->_left = rightMin->_right;
						else//如果rightMin左为空那么就绑在父亲的右边
							rightMinParent->_right = rightMin->_right;
						delete rightMin;
					}


					return true;
				}
			}

			return false;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " :" << root->_value << endl;
			_InOrder(root->_right);
		}

		void InOrder()//用这个给用户一个接口
		{
			_InOrder(_root);//_root是私有的，因此要在类里面才能访问的到
			cout << endl;
		}

	private:
		Node* _root = nullptr;
	};

	void TestBSTree()
	{
		BSTree<string, string>dict;
		dict.Insert("sort", "排序");
		dict.Insert("string", "字符串");
		dict.Insert("tree", "树");
		dict.Insert("insert", "插入");

		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>*ret = dict.Find(str);
			if (ret)
			{
				cout << ret->_value << endl;
			}
			else
			{
				cout << "无此单词" << endl;
			}
		}
	}
		void Test_bit3()//统计次数
		{
			string strs[] = { "西瓜","苹果","西瓜","苹果", "西瓜","香蕉", "西瓜","樱桃","西瓜" };
			BSTree<string, int>coutTree;
			for (auto str : strs)
			{
				BSTreeNode<string, int>*ret = coutTree.Find(str);
				if (ret == nullptr)
				{
					coutTree.Insert(str, 1);
				}
				else
				{
					ret->_value++;
				}
			}

			coutTree.InOrder();
		}
}