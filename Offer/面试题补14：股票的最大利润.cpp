/*
*
* 面试题补15：股票的最大利润
* 假设把某股票的价格按照时间先后顺序存储在数组中，
* 请问买卖该股票一次可能获得的最大利润是多少？
*
*/

#include <vector>

using namespace std;

//最大的差值
int maxDiff(const vector<int> num)
{
	if (!num.size()) {
		return 0;
	}

	int min = num[0];		//最小值
	int diff = num[0] - min;//差价
	for (int i = 1; i < num.size(); ++i) {
		//更新最小值
		if (num[i] < min) {
			min = num[i];
		}
		//当前差价
		int tmp = num[i] - min;
		//更新差价
		if (tmp > diff) {
			diff = tmp;
		}
	}
	return diff;
}
