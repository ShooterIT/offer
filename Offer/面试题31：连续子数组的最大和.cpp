/*
*
* 面试题31：连续子数组的最大和
* HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
* 今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
* 当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
* 并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
* 连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
*
*/

#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) 
{
	if (array.size() == 0) {
		return 0;
	}
	//最大值
	int max = array[0];
	//当前和
	int cur = array[0];
	for (int i = 1; i < array.size(); i++) {
		//当前和大于0就加上该数字
		if (cur >= 0) {
			cur += array[i];
		}else{
		//当前和小于0，应舍掉，重新计算，否则只会更小
			cur = array[i];
		}
		//当前和是否大于最大值
		if (cur > max) {
			max = cur;
		}
	}
	return max;
}