/*
*
* 面试题22：栈的压入、弹出序列
* 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
* 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
* 序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
* 但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*
*/

#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	//两个大小必须一样
	if (pushV.empty() || popV.empty() 
		|| pushV.size() != popV.size()) {
		return false;
	}

	stack<int> si;
	int idx = 0;
	for (int i = 0; i < pushV.size(); i++) {
		//开始插入元素
		si.push(pushV[i]);
		//相等就弹栈
		while (!si.empty() && si.top() == popV[idx]){
			si.pop();
			idx++;
		}
	}
	return si.empty();
}