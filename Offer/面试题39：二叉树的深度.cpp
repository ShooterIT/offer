/*
*
* 面试题39：二叉树的深度
*
*/

#include <algorithm>
#include <cmath>

using std::max;
using std::abs;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
}; 

int TreeDepth(TreeNode* pRoot)
{
	return !pRoot ? 0 : max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}


bool isBalanced(TreeNode *root, int &depth)
{
	if (!root) { 
		depth = 0;
		return true; 
	}
	int left = 0, right = 0;
	if (isBalanced(root->left, left) &&
		isBalanced(root->right, right)) {
		int diff = abs(left - right);
		if(diff <= 1){
			depth = max(left, right) + 1;
			return true;
		}
	}
	return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) 
{
	int depth = 0;
	return isBalanced(pRoot, depth);
}
