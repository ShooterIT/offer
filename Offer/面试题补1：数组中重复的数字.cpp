/*
*
* 面试题补1：数组中重复的数字
*
*/


#include <functional>

using namespace std;


//修改内容
bool duplicate(int numbers[], int length, int* duplication)
{
	if (!numbers || length <= 0) {
		return false;
	}

	//充分利用下标和数值
	for (int i = 0; i < length; i++) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}
			swap(numbers[i], numbers[numbers[i]]);
		}
	}

	return false;
}


int countRange(const int *numbers, int length, int start, int end)
{
	if (!numbers || length <= 0) {
		return -1;
	}
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (numbers[i] >= start && numbers[i] <= end) {
			count++;
		}
	}
	return count;
}

//未修改内容
int getDuplication(const int *numbers, int length)
{
	if (!numbers || length <= 0) {
		return -1;
	}
	//利用二分查找，统计次数
	int start = 1;
	int end = length;
	while (end >= start) {
		int mid = start + (end - start) >> 1;
		int count = countRange(numbers, length, start, mid);
		if (end == start) { //只有一个元素了
			if (count > 1) {
				return start;
			}
			else {
				break;
			}
		}
		if (count > (mid - start + 1)) { //start-mid有重复
			end = mid;
		}else{							 //mid+1-end有重复
			start = mid + 1;
		}
	}
	return -1;
}