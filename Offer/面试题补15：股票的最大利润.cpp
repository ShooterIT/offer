/*
*
* 面试题补15：股票的最大利润
*
*/

#include <vector>

using namespace std;

int maxDiff(const vector<int> num)
{
	if (!num.size()) {
		return 0;
	}

	int min = num[0];
	int diff = num[0] - min;
	for (int i = 1; i < num.size(); ++i) {
		if (num[i] < min) {
			min = num[i];
		}
		int tmp = num[i] - min;
		if (tmp > diff) {
			diff = tmp;
		}
	}
	return diff;
}
