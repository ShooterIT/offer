/*
*
* 面试题23：从上往下打印二叉树
*
*/


#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

//队列，广度优先
vector<int> PrintFromTopToBottom(TreeNode* root) 
{
	vector<int> result;
	if (root == nullptr) {
		return result;
	}
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty()) {
		//头，front
		TreeNode *node = que.front(); que.pop();
		result.push_back(node->val);
		//保证对列中没有空指针，不仅减少计算次数，在行打印时能保证正确
		if (node->left != nullptr) {
			que.push(node->left);
		}
		if (node->right != nullptr) {
			que.push(node->right);
		}
	}
	return result;
}