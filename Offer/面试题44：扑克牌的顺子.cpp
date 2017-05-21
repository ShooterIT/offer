/*
*
* 面试题44：扑克牌的顺子
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
	int zero_num = 0;
	for (auto v : numbers) {
		if (v == 0) {
			zero_num++;
		}
	}
	if (zero_num == 4) {
		return true;
	}
	sort(numbers.begin(), numbers.end());

	//统计间隔
	int small = zero_num;
	int big = small + 1;
	int gap = 0;
	while (big < numbers.size()){
		//顺子
		if (numbers[big] == numbers[small]) {
			return false;
		}
		gap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	return zero_num >= gap;

}