/*
*
* 面试题8：旋转数组的最小数字
* 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
* 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
* 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
* NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*
*/

#include <iostream>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>


using std::vector;
using std::cout;
using std::swap;

//快排分割
int partition(vector<int> &data, int start, int end)
{
	static int first = 0;
	if (!first) {
		first = 1;
		srand((unsigned)time(0));
	}
	int rand_n = rand() % (end - start + 1) + start;
	swap(data[end], data[rand_n]);
	
	int key = data[end];
	int small = start;
	for (int i = start; i < end; i++) {
		if (data[i] < key) {
			swap(data[small++], data[i]);
		}
	}
	swap(data[small], data[end]);
	return small;
}

//快排
void quick_sort(vector<int> &data, int start, int end)
{
	if (start < end) {
		int idx = partition(data, start, end);
		quick_sort(data, start, idx - 1);
		quick_sort(data, idx + 1, end);
	}
}


//年龄排序
void age_sort(vector<int> &age)
{
	if (age.size() <= 1) {
		return;
	}
	const int max_age = 100;
	int all_age[max_age];
	for (int i = 0; i < max_age; i++) {
		all_age[i] = 0;
	}
	for (int i = 0; i < age.size(); i++) {
		if (age[i] < 0 || age[i] > max_age) {
			throw new std::exception("error: age out of range.");
		}
		all_age[age[i]]++;
	}
	int idx = 0;
	for (int i = 0; i < max_age; i++) {
		for (int j = 0; j < all_age[i]; j++) {
			age[idx++] = i;
		}
	}
}

/*
int main(void)
{
	vector<int> vi{ 1,2,8,9,4,2,5,7,6 };
	//quick_sort(vi, 0, vi.size() - 1);
	age_sort(vi);
	for (auto v : vi) {
		cout << v << " ";
	}
	cout << "\n";
	getchar();
	return 0;
}
*/

//旋转数组的最小数字
int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0) {
		return 0;
	}
	int low = 0;
	int high = rotateArray.size() - 1;

	//递增序列，返回第一个即可
	if(rotateArray[high] > rotateArray[low]){
		return rotateArray[low];
	}
	//最小值前面的元素肯定都大于最小值后面的元素
	while (high > low) {
		//中间位置
		int mid = low + (high - low) / 2;
		
		if (rotateArray[high] > rotateArray[mid]) {
			//[mid，high]为递增区域
			high = mid;
		
		}else if(rotateArray[high] < rotateArray[mid]){
			//[low，mi]为递减区
			low = mid+1;
		}else{//相同无法知道其中相等元素的个数，只能移动一位
			high--;
		}
	}
	return rotateArray[low];
}
