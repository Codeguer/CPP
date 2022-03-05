#pragma once
#include <iostream>
#include <string>
using namespace std;

//�������������޸���key�ǲ����޸ĵģ��޸�����ô�Ͳ��Ƕ�����������
//�����kvģʽ�Ļ�����ô��value�ǿ����޸ĵ�

//��������Ӣ�Ļ���,������Ч��Ϊlog(N)
	//  ͳ�ƴ���
//������������������Ļ��߽ӽ�������ô��Ч�ʾ͵ò�����֤��
//��1 2 3 4 5 6 7
/*1
	2
	  3
	    4
		  5
		    6
			  7
			  ��ô����������������O(N)
			  ��ν����ƽ����
			  1��AVLTree
			  2�������*/
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
						// ������߼��������⣿
						Node* rightMinParent = cur;//�����һ��
						Node* rightMin = cur->_right;
						while (rightMin->_left)
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}
						// ���ɾ����
						cur->_key = rightMin->_key;
						cur->_value = rightMin->_value;

						// ת����ɾ��rightMin
						if (rightMin == rightMinParent->_left)
							rightMinParent->_left = rightMin->_right;
						else//���rightMin��Ϊ����ô�Ͱ��ڸ��׵��ұ�
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

		void InOrder()//��������û�һ���ӿ�
		{
			_InOrder(_root);//_root��˽�еģ����Ҫ����������ܷ��ʵĵ�
			cout << endl;
		}

	private:
		Node* _root = nullptr;
	};

	void TestBSTree()
	{
		BSTree<string, string>dict;
		dict.Insert("sort", "����");
		dict.Insert("string", "�ַ���");
		dict.Insert("tree", "��");
		dict.Insert("insert", "����");

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
				cout << "�޴˵���" << endl;
			}
		}
	}
		void Test_bit3()//ͳ�ƴ���
		{
			string strs[] = { "����","ƻ��","����","ƻ��", "����","�㽶", "����","ӣ��","����" };
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