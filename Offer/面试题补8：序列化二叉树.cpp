/*
*
* 面试题补8：序列化二叉树
*
*/

#include <vector>
#include <queue>
#include <string>

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

void Serialize_run(TreeNode*root, string &str)
{
	if (!root) {
		str.push_back('#');
		return;
	}
	string s = to_string(root->val);
	str += s;
	str.push_back(',');
	Serialize_run(root->left, str);
	Serialize_run(root->right, str);
}

char* Serialize(TreeNode *root) 
{
	string str;
	Serialize_run(root, str);
	char * result = new char[str.size() + 1];
	strcpy(result, str.c_str());
	return result;
}

TreeNode* Deserialize_run(char* &str)
{
	if (*str == '#') {
		str++;
		return nullptr;
	}
	int num = 0;
	while (*str != ',') {
		num = num * 10 + *str - '0';
		str++;
	}
	str++;
	TreeNode *root = new TreeNode(num);
	root->left = Deserialize_run(str);
	root->right = Deserialize_run(str);

	return root;
}

TreeNode* Deserialize(char *str) 
{
	if (!str || *str == 0) {
		return nullptr;
	}
	return Deserialize_run(str);

}
