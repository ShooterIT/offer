/*
*
* 面试题36：数组中的逆序对
* 在数组中的两个数字，如果前面一个数字大于后面的数字，
* 则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
* 并将P对1000000007取模的结果输出。 即输出P%1000000007 
*
*/

#include <vector>

using namespace std;

long long merge(vector<int> &data, vector<int> &copy_data, int start, int end)
{
	if (start >= end) {
		return 0;
	}
	int mid   = start + (end - start) / 2;
	long long left  = merge(copy_data, data, start, mid);
	long long right = merge(copy_data, data, mid + 1, end);

	long long  count = 0;
	int i = mid;
	int j = end;
	int copy_idx = end;
	while (i >= start && j >= mid+1){
		if (data[i] > data[j]) {
			count += (j - mid);
			copy_data[copy_idx--] = data[i--];
		}else{
			copy_data[copy_idx--] = data[j--];
		}
	}
	while (i >= start){
		copy_data[copy_idx--] = data[i--];
	}
	while (j >= mid+1) {
		copy_data[copy_idx--] = data[j--];
	}

	for (int k = start; k <= end; k++) {
		data[k] = copy_data[k];
	}
	return count + left + right;
}

int InversePairs(vector<int> data) 
{
	if (data.size() < 2) {
		return 0;
	}
	vector<int> copy_data = data;
	return merge(data, copy_data, 0, data.size()-1) % 1000000007;
}