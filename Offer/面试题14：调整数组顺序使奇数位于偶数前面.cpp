/*
*
* 面试题14：调整数组顺序使奇数位于偶数前面
* 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
* 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
* 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*
*/
#include <vector>
#include <functional>
using std::vector;
using std::swap;

void reOrderArray(vector<int> &array)
{
	if (array.size() <= 1) {
		return;
	}
	int j = 0;//j之后的表示偶数
	for (int i = 0; i < array.size(); i++) {
		//如果i是奇数，则交换位置
		if (array[i] & 1 == 1) {
			swap(array[i], array[j]);
			j++;
		}
	}
}