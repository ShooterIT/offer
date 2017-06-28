/*
*
* 面试题6：重建二叉树
* 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
* 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
* 例如输入前序遍历序列{1,2,4,7,3,5,6,8}
* 和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
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



//参数： 前序，起始位置，中序，起始位置
TreeNode* reConstruct(const vector<int> &pre, int pre_start, int pre_end,
	const vector<int> &in, int in_start, int in_end)
{
	//终止条件，没有元素
	if (pre_start > pre_end || in_start > in_end) {
		return nullptr;
	}
	//构造根节点
	TreeNode *root = new TreeNode(pre[pre_start]);
	//寻找中序遍历中根节点的位置
	for (int i = 0; i < (in_end - in_start + 1); i++) {
		if (in[i + in_start] == pre[pre_start]) { //找到根节点
												  //构造左子树
			root->left = reConstruct(pre, pre_start + 1, pre_start + i,
				in, in_start, in_start + i - 1);
			//构造右子树
			root->right = reConstruct(pre, pre_start + i + 1, pre_end,
				in, in_start + i + 1, in_end);
			break;
		}
	}
	//返回根节点
	return root;
}

//构建树的函数
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	//特殊值判断
	if (!pre.size() || !vin.size() || pre.size() != vin.size()) {
		return nullptr;
	}
	return reConstruct(pre, 0, pre.size() - 1,
		vin, 0, vin.size() - 1);

}


