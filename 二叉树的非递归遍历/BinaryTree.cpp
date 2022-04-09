#include"BinaryTree.h"


BTree* BinaryTreeNodeCreat(BinaryTreeDataType data)
{
	BTree*Node = (BTree*)malloc(sizeof(BTree));
	Node->_data = data;
	Node->_leftchild = NULL;
	Node->_rightchild = NULL;
	return Node;
}
void BinaryTreePrint(BTree* Node)
{
	if (Node == NULL)
		printf("%d\n", -1);
	else
	{
		printf("%c\n", Node->_data);

	}
}
// 二叉树前序遍历
//void BinaryTreePrevOrder(BTree* Proot)
//{
//	if (Proot == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//		
//	printf("%c ", Proot->_data);
//	BinaryTreePrevOrder(Proot->_leftchild);
//	BinaryTreePrevOrder(Proot->_rightchild);
//}

//二叉树的非递归遍历之前序遍历
void BinaryTreePrevOrder(BTree* Proot)
{
	vector<char>ret;
	stack<BTree*>st;
	BTree*cur = Proot;
	while (cur || !st.empty())
	{
		while (cur)
		{
			ret.push_back(cur->_data);
			st.push(cur);
			cur = cur->_leftchild;
		}

		//st在这一步必定不为空
		cur = st.top()->_rightchild;
		st.pop();
	}

	for (auto e : ret)
	{
		cout << e << " ";
	}
}





// 二叉树中序遍历
//void BinaryTreeInOrder(BTree* Proot)
//{
//	if (Proot == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	BinaryTreeInOrder(Proot->_leftchild);
//	printf("%c ", Proot->_data);
//	BinaryTreeInOrder(Proot->_rightchild);
//}
//二叉树非递归遍历之中序遍历
void BinaryTreeInOrder(BTree* Proot)
{
	vector<char>ret;
	stack<BTree*>st;
	BTree*cur = Proot;
	while (cur || !st.empty())
	{
		while (cur)
		{
			st.push(cur);
			cur = cur->_leftchild;
		}

		//st在这一步必定不为空
		ret.push_back(st.top()->_data);
		cur = st.top()->_rightchild;
		st.pop();

	}

	for (auto e : ret)
	{
		cout << e << " ";
	}
}
//// 二叉树后序遍历
//void BinaryTreePostOrder(BTree* Proot)
//{
//	if (Proot == nullptr)
//	{
//		//cout << "NULL ";
//		return;
//	}
//
//	BinaryTreePostOrder(Proot->_leftchild);
//	BinaryTreePostOrder(Proot->_rightchild);
//	printf("%c ", Proot->_data);
//}

// 二叉树非递归之后序遍历（使用前后指针）
void BinaryTreePostOrder(BTree* Proot)
{
	vector<char>ret;
	stack<BTree*>st;
	BTree*cur = Proot;
	BTree*lastNode = nullptr;//最近访问的结点
	while (cur || !st.empty())
	{
		while (cur)
		{
			//ret.push_back(cur->_data);
			st.push(cur);
			cur = cur->_leftchild;
		}
		//lastNode NULL
		if (st.top()->_rightchild == nullptr || lastNode == st.top()->_rightchild)
		{
			ret.push_back(st.top()->_data);
			lastNode = st.top();
			st.pop();
		}
		else
		{
			cur = st.top()->_rightchild;
		}


	}

	for (auto e : ret)
	{
		cout << e << " ";
	}
}

// 二叉树节点个数
int BinaryTreeSize(BTree* Proot)
{
	return Proot == NULL ? 0 : (BinaryTreeSize(Proot->_leftchild) + BinaryTreeSize(Proot->_rightchild) + 1);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTree* Proot)
{
	if (Proot == NULL)
	{
		return 0;
	}

	if (Proot->_leftchild == NULL && Proot->_rightchild == NULL)
		return 1;

	return BinaryTreeLeafSize(Proot->_leftchild) + BinaryTreeLeafSize(Proot->_rightchild);


}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTree* Proot, int k)
{
	if (Proot == NULL)
		return 0;
	if (1 == k)
		return 1;
	return BinaryTreeLevelKSize(Proot->_leftchild, k - 1)
		+ BinaryTreeLevelKSize(Proot->_rightchild, k - 1);
}


// 二叉树查找值为x的节点
BTree* BinaryTreeFind(BTree* Proot, BinaryTreeDataType x)
{
	if (Proot == NULL)
		return NULL;
	if (Proot->_data == x)
		return Proot;
	BTree* LeftTmp = BinaryTreeFind(Proot->_leftchild, x);
	if (LeftTmp)
		return LeftTmp;
	BTree* RightTmp = BinaryTreeFind(Proot->_rightchild, x);
	if (RightTmp)
		return RightTmp;
	if (LeftTmp == NULL && RightTmp == NULL)
	{
		return NULL;
	}
}

// 层序遍历
void BinaryTreeLevelOrder(BTree* Proot)
{
	if (Proot == NULL)
	{
		printf("NULL ");
		return;
	}
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, Proot);
	while (!QueueEmpty(&Q))
	{
		QDataType front = QueueFront(&Q);
		if (front == NULL)
			printf("NULL ");
		else
		{
			printf("%c ", front->_data);
			QueuePush(&Q, front->_leftchild);
			QueuePush(&Q, front->_rightchild);
		}
		QueuePop(&Q);
	}
	QueueDestroy(&Q);
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTree* Proot)
{
	if (Proot == NULL)
	{
		return false;
	}
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, Proot);
	while (!QueueEmpty(&Q))
	{
		QDataType front = QueueFront(&Q);
		QueuePop(&Q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&Q, front->_leftchild);
		QueuePush(&Q, front->_rightchild);
	}
	while (!QueueEmpty(&Q))
	{
		QDataType front = QueueFront(&Q);
		QueuePop(&Q);
		if (front != NULL)
			return false;
	}
	return true;
}
// 二叉树销毁
void BinaryTreeDestory(BTree** PProot)
{
	if (*PProot == NULL)
		return;

	BinaryTreeDestory(&((*PProot)->_leftchild));
	BinaryTreeDestory(&((*PProot)->_rightchild));
	free(*PProot);
	*PProot = NULL;
}
