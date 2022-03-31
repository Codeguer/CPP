#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	//ǰ�����
	void preorderTraversal(TreeNode* root,vector<int>& v) {
		stack<TreeNode*> st;
		TreeNode*cur = root;
		while (cur != nullptr || !st.empty()) {
			while (cur) {
				v.push_back(cur->val);
				st.push(cur);
				cur = cur->left;
			}
			TreeNode*top = st.top();
			st.pop();
			if (top->right)cur = top->right;
		}
	}
	//�������
	void inorderTraversal(TreeNode* root, vector<int>& v) {
		stack<TreeNode*>st;
		TreeNode*cur = root;
		while (cur != nullptr || !st.empty()) {
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			TreeNode*top = st.top();
			v.push_back(top->val);
			st.pop();
			if (top->right)cur = top->right;

		}
	}
	//�������
	void postorderTraversal(TreeNode* root, vector<int>& v) {
		stack<TreeNode*>st;
		TreeNode*cur = root;
		TreeNode*lastNode = nullptr;
		while (cur != nullptr || !st.empty()) {
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
			TreeNode*top = st.top();
			if (top->right == nullptr||top->right == lastNode) {
				v.push_back(top->val);
				st.pop();
				lastNode = top;
			}
			else {
				cur = top->right;
			}

		}
	}
};
//ǰ�����[1,2,4,5,3,6,7]
//�������[4,2,5,1,6,3,7]
//�������[4,5,2,6,7,3,1]
int main() {
	TreeNode A(1);
	TreeNode B(2);
	TreeNode C(3);
	TreeNode D(4);
	TreeNode E(5);
	TreeNode F(6);
	TreeNode J(7);

	A.left = &B;
	A.right = &C;
	B.left = &D;
	B.right = &E;
	C.left = &F;
	C.right = &J;
	
	Solution s;
	vector<int>v;
	//s.preorderTraversal(&A, v);
	//s.inorderTraversal(&A, v);
	//s.postorderTraversal(&A, v);
	return 0;
}