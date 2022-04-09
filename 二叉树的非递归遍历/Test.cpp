#include"BinaryTree.h"

void Test()
{
	BTree*A = BinaryTreeNodeCreat('A');
	BTree*B = BinaryTreeNodeCreat('B');
	BTree*C = BinaryTreeNodeCreat('C');
	BTree*D = BinaryTreeNodeCreat('D');
	BTree*E = BinaryTreeNodeCreat('E');
	BTree*F = BinaryTreeNodeCreat('F');
	BTree*H = BinaryTreeNodeCreat('H');
	BTree*J = BinaryTreeNodeCreat('J');
	BTree*K = BinaryTreeNodeCreat('K');

	A->_leftchild = B;
	A->_rightchild = C;
	B->_leftchild = D;
	D->_rightchild = E;
	E->_leftchild = F;
	C->_leftchild = H;
	C->_rightchild = J;
	H->_leftchild = K;

	BinaryTreePrint(A);

	
	BinaryTreePrevOrder(A);//前序遍历
	printf("前序遍历\n");
	BinaryTreeInOrder(A);//中序遍历
	printf("中序遍历\n");
	BinaryTreePostOrder(A);//后序遍历
	printf("后序遍历\n");
	printf("\n");

	printf("一共有%d个节点\n", BinaryTreeSize(A));
	printf("一共有%d个叶子节点\n", BinaryTreeLeafSize(A));
	int k = 1;
	while (k<6)
	{
		printf("第%d层一共有%d个节点\n", k, BinaryTreeLevelKSize(A, k));
		k++;
	}
	
	printf("查找值为H的节点：");
	BinaryTreePrint(BinaryTreeFind(A, 'H'));
	printf("查找值为U的节点：");
	BinaryTreePrint(BinaryTreeFind(A, 'U'));
	
	BinaryTreeLevelOrder(A);//层次遍历
	printf("层次遍历\n");

	printf("判断是否为完全二叉树: %d", BinaryTreeComplete(A));

	BinaryTreeDestory(&A);
	
}

int main()
{
	Test();
	return 0;
}