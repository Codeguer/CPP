#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Queue.h"
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
typedef char BinaryTreeDataType;
typedef struct BinaryTree//用左右孩子指针建立二叉树的结构
{
	BinaryTreeDataType _data;//数据域
	struct BinaryTree *_leftchild;//左指针域
	struct BinaryTree *_rightchild;//右指针域
}BTree;




BTree* BinaryTreeNodeCreat(BinaryTreeDataType data);//新建结点
//打印结点
void BinaryTreePrint(BTree* Node);
// 二叉树前序遍历
void BinaryTreePrevOrder(BTree* Proot);
// 二叉树中序遍历
void BinaryTreeInOrder(BTree* Proot);
// 二叉树后序遍历
void BinaryTreePostOrder(BTree* Proot);

// 二叉树节点个数
int BinaryTreeSize(BTree* Proot);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTree* Proot);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTree* Proot, int k);
// 二叉树查找值为x的节点
BTree* BinaryTreeFind(BTree* Proot, BinaryTreeDataType x);

// 层序遍历
void BinaryTreeLevelOrder(BTree* Proot);

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTree* Proot);
// 二叉树销毁
void BinaryTreeDestory(BTree** PProot);

