/*
*
* 面试题50：树中两个节点的最低公共祖先
*
*/

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

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

//中序遍历
void inorder(TreeNode *root)
{
	if (root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

bool insert(TreeNode **root, int v)
{
	if ((*root) == nullptr) {
		*root = new TreeNode(v);
		return true;
	}
	if ((*root)->val > v) {
		return insert(&((*root)->left), v);
	}
	if((*root)->val < v){
		return insert(&(*root)->right, v);
	}
	return false;
}

//二叉搜索树最低公共祖先
int find_first_common_node(TreeNode *root, int a, int b) 
{
	while (root){
		if (root->val > a && root->val > b) {
			root = root->left;
		}
		else if (root->val < a && root->val < b) {
			root = root->right;
		}
		else {
			return root->val;
		}
	}
	return -1;
}

//得到一条路径
bool get_path(vector<TreeNode *>& vt, TreeNode *root, int v)
{
	if (!root) {
		return false;
	}
	vt.push_back(root);
	if (root->val == v) {
		return true;
	}
	//多个需要判断
	if (get_path(vt, root->left, v)) {
		return true;
	}
	if (get_path(vt, root->right, v)) {
		return true;
	}
	vt.pop_back();
	return false;
}
//获得最后一个父节点
TreeNode *get_last_parent(const vector<TreeNode*> a, const vector<TreeNode*> b) 
{
	TreeNode *n = nullptr;
	int i = 0;
	while (i < a.size() && i < b.size()) {
		if(a[i] == b[i]){
			n = a[i];
		}else{
			break;
		}
		i++;
	}
	return n;
}

//默认a,b在树中存在
int find_first_common_node2(TreeNode *root, int a, int b)
{
	if (!root) {
		return -1;
	}
	vector<TreeNode *> v1;
	get_path(v1, root, a);
	vector<TreeNode *> v2;
	get_path(v2, root, b);
	TreeNode *n = get_last_parent(v1, v2);

	return n->val;
}
/*
int main(void)
{
	TreeNode *root = nullptr;
	insert(&root, 20);
	insert(&root, 15);
	insert(&root, 25);
	insert(&root, 5);
	insert(&root, 9);
	insert(&root, 11);
	insert(&root, 3);
	inorder(root);
	cout << endl;

	//cout << find_first_common_node(root, 25, 11) << endl;
	cout << find_first_common_node2(root, 3, 11) << endl;

	getchar();
	return 0;
}
*/