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

//分治合并，其中返回值为逆序对的个数
long long merge(vector<int> &data, vector<int> &copy_data, int start, int end)
{
	//没有逆序对
	if (start >= end) {
		return 0;
	}
	//分治，划分
	int mid   = start + (end - start) / 2;
	long long left  = merge(copy_data, data, start, mid);
	long long right = merge(copy_data, data, mid + 1, end);
	//如果左边有比右边大的，那么就存在逆序对，而且逆序对的个数等于
	long long count = 0;
	int copy_idx = end; //拷贝的下标索引
	int i = mid, j = end;
	while (i >= start && j > mid){
		//左边比右边大，存在逆序对
		if (data[i] > data[j]){
			count += (j - mid);
			copy_data[copy_idx--] = data[i--];
		}
		//右边比左边大，不存在逆序对
		else {
			copy_data[copy_idx--] = data[j--];
		}

	}
	//如果一边有剩余，则直接拷贝
	while (i >= start){
		copy_data[copy_idx--] = data[i--];
	}
	while (j >= mid+1) {
		copy_data[copy_idx--] = data[j--];
	}
	//拷贝排序好的数组
	for (int k = start; k <= end; k++) {
		data[k] = copy_data[k];
	}
	//返回逆序对的个数
	return count + left + right;
}

int InversePairs(vector<int> data) 
{
	if (data.size() < 2) {
		return 0;
	}
	//copy_data作为中间拷贝数据
	vector<int> copy_data = data;
	//分治
	return merge(data, copy_data, 0, data.size()-1) % 1000000007;
}