/*
*
* 面试题25：二叉树中和为某一值的路径
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