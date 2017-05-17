/*
*
* 面试题24：二叉搜索树的后序遍历序列
*
*/

#include <vector>

using namespace std;

bool subVerifySquenceOfBST(const vector<int> sequence, int beg, int end)
{
	if (beg >= end) {
		return true;
	}
	int root = sequence[end];
	//找左子树
	int i = beg;
	for (; i < end; i++) {
		if (sequence[i] > root) {
			break;
		}
	}
	//判断右子树是否合法
	for (int j = i; j < end; j++) {
		if (sequence[j] < root) {
			return false;
		}
	}

	return subVerifySquenceOfBST(sequence, beg, i - 1)
		&& subVerifySquenceOfBST(sequence, i, end - 1);

}

bool VerifySquenceOfBST(vector<int> sequence) 
{
	if (!sequence.size()) {
		return false;
	}
	return subVerifySquenceOfBST(sequence, 0, sequence.size() - 1);
}
