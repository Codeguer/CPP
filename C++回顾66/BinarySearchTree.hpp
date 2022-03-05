#pragma once
#include<iostream>
using namespace std;
namespace bit1
{
	//������������дΪģ�壬�����.hpp����.h����Ҳ����
	//������K����T��
	template<class K>
	struct BSTreeNode // Binary Search Tree Node
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;

		K _key;

		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree // Binary Search Tree
	{
		typedef BSTreeNode<K> Node;
	public:
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
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

			cur = new Node(key);
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

		bool Find(const K& key)
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
					return true;
				}
			}

			return false;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)//����
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
					// �ҵ��ˣ���ʼɾ��
					// 1����Ϊ��
					// 2����Ϊ��
					// 3�����Ҷ���Ϊ��
					if (cur->_left == nullptr)
					{
						if (parent->_right == cur)
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;

						delete cur;

					}
					else if (cur->_right == nullptr)
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;

						delete cur;
					}
					else
					{
						// ������߼��������⣿
						Node* rightMinParent = nullptr;
						Node* rightMin = cur->_right;
						while (rightMin->_left)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}

						// ���ɾ����
						cur->_key = rightMin->_key;

						// ת����ɾ��rightMin
						rightMinParent->_left = rightMin->_right;
						//���￼�ǵĲ�ȫ�棬��һrightMinParent->_right == rightMin��

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
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		void InOrder()//��������û�һ���ӿ�
		{
			_InOrder(_root);//_root��˽�еģ����Ҫ����������۷��ʵĵ�
			cout << endl;
		}

	private:
		Node* _root = nullptr;
	};

	void TestBSTree()
	{
		BSTree<int> t;
		int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
		for (auto e : a)
		{
			t.Insert(e);
		}

		t.InOrder();

		// ���������⣿ȥ˼��Ϊʲô����ô�����
		//t.Erase(7);
		//t.InOrder();
	//���ֵ�����rightMinParent->_left = rightMin->_right;//��ʱrightMinParentΪ��

		// 1��Ҷ��
		t.Erase(2);
		t.InOrder();

		// ��Ϊ�գ�������Ϊ��
		t.Erase(8);
		t.Erase(1);
		t.InOrder();

		// ��Ϊ�գ�������Ϊ��
		t.Erase(5);
		t.InOrder();

		// ����Ҳ�����⣬������Լ���ȥ����һ�£�
		//��������ֵ�����һ��
		/*for (auto e : a)
		{
			t.Erase(e);
			t.InOrder();
		}*/
	}

}