/*
*
* 面试题27：二叉搜索树与双向链表
* 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
* 要求不能创建任何新的结点，只能调整树中结点指针的指向。
*
*/

#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

TreeNode* Convert(TreeNode* pRootOfTree)
{
	//边界判断
	if (pRootOfTree == nullptr) {
		return nullptr;
	}
	if (pRootOfTree->left == nullptr&&pRootOfTree->right == nullptr) {
		return pRootOfTree;
	}
	// 1.将左子树构造成双链表，并返回链表头节点
	TreeNode *left = Convert(pRootOfTree->left);
	// 2.定位至左子树双链表最后一个节点
	TreeNode *n = left;
	while (n != nullptr && n->right != nullptr) {
		n = n->right;
	}
	// 3.如果左子树链表不为空的话，将当前root追加到左子树链表。
	if (n != nullptr) {
		pRootOfTree->left = n;
		n->right = pRootOfTree;
	}
	// 4.将右子树构造成双链表，并返回链表头节点
	TreeNode *right = Convert(pRootOfTree->right);
	// 5.如果右子树链表不为空的话，将该链表追加到root节点之后
	if (right != nullptr) {
		pRootOfTree->left = right;
		right->left = pRootOfTree;
	}
	// 6.根据左子树链表是否为空确定返回的节点。
	return left == nullptr ? pRootOfTree : left;
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	//边界判断
	if (pRootOfTree == nullptr) {
		return nullptr;
	}
	//return sub_convert(pRootOfTree,1);
	stack<TreeNode*> st; //非递归的栈
	TreeNode* p = pRootOfTree; //遍历的指针
	TreeNode* pre,*root;
	bool first = true;
	while (p != nullptr || !st.empty()) {
		//循环遍历左子树
		while (p != nullptr){
			st.push(p);
			p = p->left;
		}
		//访问根节点
		p = st.top(); st.pop();
		if (first) { //初次，设置头结点
			root = p;
			root->left = nullptr;
			pre = root;
			first = false;
		}else{
			//左子树指向上一个节点
			p->left = pre;
			pre->right = p;
			pre = p; //pre为当前节点
		}
		//转到右子树
		p = p->right;
	}
	return root;
}
