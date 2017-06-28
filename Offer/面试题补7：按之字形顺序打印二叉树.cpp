/*
*
* 面试题补7：按之字形顺序打印二叉树
*
*/


#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

//之字型打印,使用连个栈，交替存放
vector<vector<int> > Print(TreeNode* pRoot) 
{
	vector<vector<int>> result;
	if (!pRoot) {
		return result;
	}
	stack<TreeNode*> st1, st2;
	st1.push(pRoot);
	//使用两个栈，交替存放数据，一个先放右子树，一个先放左子树
	while (!st1.empty() || !st2.empty()){
		if (!st1.empty()) {
			vector<int> vi;
			//栈元素中为一层中的所有节点
			while (!st1.empty()){
				TreeNode *n = st1.top(); st1.pop();
				vi.push_back(n->val);
				//将其存放在另一个栈中
				if (n->left) {
					st2.push(n->left);
				}
				if (n->right) {
					st2.push(n->right);
				}
			}
			result.push_back(vi);
		}
		if (!st2.empty()) {
			vector<int> vi;
			//栈元素中为一层中的所有节点
			while (!st2.empty()){
				TreeNode *n = st2.top(); st2.pop();
				vi.push_back(n->val);
				//将其存放在另一个栈中
				if (n->right) {
					st1.push(n->right);
				}
				if (n->left) {
					st1.push(n->left);
				}
			}
			result.push_back(vi);
		}
	}
	return result;
}

//层次打印，分行
vector<vector<int> > Print2(TreeNode* pRoot) 
{
	vector<vector<int>> result;
	if (!pRoot) {
		return result;
	}
	queue<TreeNode*> qt;
	qt.push(pRoot);
	while (!qt.empty()){
		int num = qt.size();
		int i = 0;
		vector<int> vi;
		//当前行中个数为num
		while (i++ < num){
			TreeNode* n = qt.front(); qt.pop();
			vi.push_back(n->val);
			//非空，减少了对空指针的判断
			//更重要的是保证分行正确，不会打印最后一空行
			if (n->left) {
				qt.push(n->left);
			}
			if (n->right) {
				qt.push(n->right);
			}
		}
		result.push_back(vi);
	}
	return result;
}