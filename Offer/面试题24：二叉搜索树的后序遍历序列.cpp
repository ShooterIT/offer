/*
*
* 面试题24：二叉搜索树的后序遍历序列
* 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
* 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
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
	//左右子树也得满足条件
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
