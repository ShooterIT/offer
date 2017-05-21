/*
*
* 面试题38：数字在排序数组中出现的次数
*
*/
#include <vector>

using namespace std;

int find_first(const vector<int> &data, int k, int start, int end)
{
	while (end >= start){
		int mid = start + (end - start) / 2;
		if (data[mid] > k) {
			end = mid-1;
		}
		else if (data[mid] < k) {
			start = mid + 1;
		}else if(mid > start && data[mid - 1] == k) {
			end = mid - 1;
		}else{
			return mid;
		}
	}
	return -1;
}

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
	int left = find_first(data, k, 0, data.size() - 1);
	int right = find_last(data, k, 0, data.size() - 1);

	if (left != -1 && right != -1) {
		return right - left + 1;
	}
	return 0;
}