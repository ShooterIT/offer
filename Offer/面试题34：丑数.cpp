/*
*
* 面试题34：丑数
* 把只包含因子2、3和5的数称作丑数（Ugly Number）。
* 例如6、8都是丑数，但14不是，因为它包含因子7。
* 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*
*/

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int GetUglyNumber_Solution(int index) 
{
	if (index < 7) {
		return index;
	}
	//丑数数组
	vector<int> result(index);
	//乘2，3，5对应的下标索引
	int m2 = 0, m3 = 0, m5 = 0;
	//1是第一个丑数
	result[0] = 1;
	for (int i = 1; i < index; i++) {
		//找到乘2，3，5最小的一个
		int val = min(result[m2] * 2, min(result[m3] * 3, result[m5] * 5));
		//如果是乘2得到的，乘2的下标+1
		if (val == result[m2] * 2) {
			result[i] = val;
			m2++;
		}
		//如果是乘3得到的，乘3的下标+1
		if (val == result[m3] * 3) {
			result[i] = val;
			m3++;
		}
		//如果是乘5得到的，乘5的下标+1
		if (val == result[m5] * 5) {
			result[i] = val;
			m5++;
		}
	}
	return result[index - 1];
}
