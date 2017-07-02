/*
*
* 面试题38：数字在排序数组中出现的次数
* 统计一个数字在排序数组中出现的次数。如数组{1,2,3,3,3,3,4,5}和数字3,3出现了4次，则返回4
*
*/
#include <vector>

using namespace std;

//查找第一次出现的位置
int find_first(const vector<int> &data, int k, int start, int end)
{
	while (end >= start){
		int mid = start + (end - start) / 2;
		if (data[mid] > k) {
			end = mid-1;
		}
		else if (data[mid] < k) {
			start = mid + 1;
		//与直接二分查找的核心区别，如果相等，且前一个位置也是该数，不能返回
		//而是将end置为前一个位置，所以结束条件变为相等且前一个不是该数
		}else if(mid > start && data[mid - 1] == k) {
			end = mid - 1;
		}else{
			return mid;
		}
	}
	return -1;
}

//查找最后一次出现的位置
int find_last(const vector<int> &data, int k, int start, int end)
{
	while (end >= start) {
		int mid = start + (end - start) / 2;
		if (data[mid] > k) {
			end = mid - 1;
		}
		else if (data[mid] < k) {
			start = mid + 1;
		}
		//与直接二分查找的核心区别，如果相等，且后一个位置也是该数，不能返回
		//而是将start置为后一个位置，所以结束条件变为相等且后一个不是该数
		else if (mid < end && data[mid + 1] == k) {
			start = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int GetNumberOfK(vector<int> data, int k) 
{
	if (!data.size()) {
		return 0;
	}
	//左位置
	int left = find_first(data, k, 0, data.size() - 1);
	//右位置
	int right = find_last(data, k, 0, data.size() - 1);

	if (left != -1 && right != -1) {
		return right - left + 1;
	}
	return 0;
}

//第二版补充
/*
*
* 题目二：0 - n - 1中缺失的数字
* 一个长度为n - 1的递增排序数组的所有数字都是唯一的，并且每个数字都在范围0~n - 1范围内，
* 这n个数字只有一个数字不在该该数组内，找出这个数字。
*
*/

int getMissNum(vector<int> num)
{
	if (num.size() == 0) {
		return -1;
	}
	int start = 0;
	int end = num.size() - 1;
	while (end >= start){
		int  mid = start + (end - start) >> 1;
		//相等，查右边
		if (num[mid] == mid) {
			start = mid + 1;
		}
		//不相等，但前一个位置数组等于其下标
		else if (mid == 0 || num[mid - 1] == mid-1){
			return mid;
		}
		//不相等，但前一个位置数组不等于其下标
		else {
			end = mid - 1;
		}
	}
	//缺失的数字不在数组中，是其下一个位置
	if (start == num.size()) {
		return num.size();
	}
	return -1;
}

/*
*
* 题目三：数组中数值下标相等的元素
* 假设一个单调递增的数组里的每一个元素都是整数并且唯一的，
* 请编程实现一个找出人一个数值等于其下标的元素，
* 例如，在数组{ -3,-1,1,3,5 }中，数值3和它的下标相等。
*
*/

int getNumSameAsIndex(vector<int> num)
{
	if (num.size() == 0) {
		return -1;
	}
	int start = 0;
	int end = num.size() - 1;
	while (end >= start) {
		int  mid = start + (end - start) >> 1;
		//相等返回即可
		if (mid == num[mid]) {
			return mid;
		//下标大于值，则在右边
		}else if(mid > num[mid]){
			start = mid + 1;
		//下标小于值，则在左边
		}else{
			end = mid - 1;
		}
	}	
	return -1;
}