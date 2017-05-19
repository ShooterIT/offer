/*
*
* 面试题31：连续子数组的最大和
*
*/

#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) 
{
	if (array.size() == 0) {
		return 0;
	}
	int max = array[0];
	int cur = array[0];
	for (int i = 1; i < array.size(); i++) {
		if (cur >= 0) {
			cur += array[i];
		}		
		if (cur < 0) {
			cur = array[i];
		}
		if (cur > max) {
			max = cur;
		}
	}
	return max;
}