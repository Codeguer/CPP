#include <iostream>
#include<vector>
#include<time.h>
using namespace std;
#include"AVLTree.h"
#include"RBTree.h"

void TestRB_AVLTree()
{
	const int n = 1000000;
	vector<int> v;
	v.reserve(n);
	srand((size_t)time(0));
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(i);
	}

	RBTree<int,int>rbtree;
	AVLTree<int, int>avltree;

	size_t begin1 = clock();
	for (auto e : v)
	{
		rbtree.Insert(make_pair(e, e));
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (auto e : v)
	{
		avltree.Insert(make_pair(e, e));
	}
	size_t end2 = clock();

	cout << "rbtree:" << end1 - begin1 << endl;
	cout << "avlree:" << end2 - begin2 << endl;

}


int main()
{
	//TestAVLTree();
	//TestRBTTree();
	TestRB_AVLTree();

	return 0;
}