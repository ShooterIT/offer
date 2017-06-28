/*
*
* 面试题25：二叉树中和为某一值的路径
* 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
* 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
* 
*/

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int> > result;
vector<int> path;

void preorder2(TreeNode *root, int ex) 
{
	//没有元素，直接返回
	if (root == nullptr) {
		return;
	}
	path.push_back(root->val);
	ex -= root->val;
	if (ex < 0) {
		path.pop_back();
		return;
	}
	//找到满足条件的解
	if (root->left == nullptr && root->right == nullptr && ex == 0) {
		result.push_back(path);
	}
	else {
		preoder(root->left, ex);
		preoder(root->right, ex);
	}
	path.pop_back();
}

//前序优先遍历
void preoder(TreeNode* root, int expectNumber)
{
	if (root == nullptr) {
		return;
	}
	path.push_back(root->val);
	expectNumber -= root->val;
	if (root->left == nullptr && root->right == nullptr && expectNumber == 0) {
		result.push_back(path);
	}
	else {
		preoder(root->left, expectNumber);
		preoder(root->right, expectNumber);
	}
	//到该点的方案已遍历完，弹出
	path.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
{
	if (root == nullptr) {
		return result;
	}
	preoder(root, expectNumber);
	
	return result;
}
