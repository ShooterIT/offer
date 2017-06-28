/*
*
* 面试题补1：数组中重复的数字
* 在一个长度为n的数组里的所有数字都在0到n-1的范围内。
* 数组中某些数字是重复的，但不知道有几个数字是重复的。
* 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
* 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*
*/


#include <functional>

using namespace std;


//修改内容
bool duplicate(int numbers[], int length, int* duplication)
{
	//特殊值检查
	if (!numbers || length <= 0) {
		return false;
	}
	//输入是否合法
	for (int i = 0; i<length; ++i)
	{
		if (numbers[i] <= 0 || numbers[i] > length - 1) {
			return false;
		}
	}
	//充分利用下标和数值,如果不重复，则排序后数字m应出现在下标为m的位置
	for (int i = 0; i < length; i++) {
		int m = numbers[i];
		while (m != i) {		   //第i个数对应的值也应该为i
			if (m == numbers[m]) { //位置m上已经存在m了，说明重复
				*duplication = m;
				return true;
			}
			swap(m, numbers[m]);   //交换数值
		}
	}

	return false;
}


//另一种方法
bool duplicate(int numbers[], int length, int* duplication)
{
	//特殊值检查
	if (!numbers || length <= 0) {
		return false;
	}
	//输入是否合法
	for (int i = 0; i<length; ++i)
	{
		if (numbers[i] <= 0 || numbers[i] > length - 1) {
			return false;
		}
	}
	//利用下标，将数值m对应的下标位置m加上length，如果位置m对应的数值大于length，说明有数字重复
	for (int i = 0; i < length; i++) {
		int m = numbers[i];
		//该值已经加了length，则缩减
		if (m >= length) {
			m -= length;
		}
		if (numbers[m] >= length) {
			*duplication = m;
			return true;
		}
		numbers[m] += length;
	}

	return false;
}

//计算范围[start,end]内的个数
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
		//计算[start,mid]之间的数字
		int count = countRange(numbers, length, start, mid);
		if (end == start) { //只有一个数字
			if (count > 1) {
				return start; //但是他们之间的数字个数大约1
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