/*
*
* 面试题44：扑克牌的顺子
* 先把数字排序；其次统计数组中大小王的个数；
* 最后统计排序之后的数组中相邻数字之间的空缺总数。
* 如果空缺的空数小于或者等于大小王的个数，那么数组就是连续的，否则就是不连续的。
*
*/

#include <vector>
#include <algorithm>

using namespace std;


bool IsContinuous(vector<int> numbers) 
{
	if (!numbers.size()) {
		return false;
	}
	//1 统计0的个数,认为大小王就是0
	int zero_num = 0;
	for (auto v : numbers) {
		if (v == 0) {
			zero_num++;
		}
	}
	if (zero_num == 4) {
		return true;
	}
	//2 排序
	sort(numbers.begin(), numbers.end());

	//3 统计间隔
	int small = zero_num;
	int big = small + 1;
	int gap = 0;
	while (big < numbers.size()){
		//相等肯定不是顺子
		if (numbers[big] == numbers[small]) {
			return false;
		}
		//记录间隔
		gap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	//比较间隔和大小王的个数
	return zero_num >= gap;

}