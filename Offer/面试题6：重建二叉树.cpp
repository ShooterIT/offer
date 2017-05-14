/*
*
* 面试题6：重建二叉树
*
*/

#include <vector>

using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//构建树的函数
TreeNode* reConstruct(const vector<int> pre, int pre_start, int pre_end,
	const vector<int> in, int in_start, int in_end)
{
	if (pre_start > pre_end || in_start > in_end) {
		return nullptr;
	}
	TreeNode * root = new TreeNode(pre[pre_start]);
	for (int i = in_start; i <= in_end; i++) {
		if (in[i] == pre[pre_start]) {
			root->left = reConstruct(pre, pre_start + 1, pre_start + i - in_start,
				in, in_start, i - 1);
			root->right = reConstruct(pre, pre_start + i - in_start + 1, pre_end,
				in, i + 1, in_end);
			break;
		}
	}
	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (!pre.size() || !vin.size() || pre.size() != vin.size()) {
		return nullptr;
	}
	return reConstruct(pre, 0, pre.size() - 1,
		vin, 0, vin.size() - 1);

}
