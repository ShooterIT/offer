/*
*
* 面试题14：调整数组顺序使奇数位于偶数前面
*
*/
#include <vector>
#include <functional>
using std::vector;
using std::swap;

void reOrderArray(vector<int> &array) 
{
	for (int i = 0; i < array.size(); i++) {
		if ((array[i] & 1) == 0) {
			for (int j = i + 1; j < array.size(); j++) {
				if (array[j] & 1) {
					int tmp = array[i];
					array[i] = array[j];
					for (int k = j; k > i; k--) {
						array[k] = array[k - 1];
					}
					array[i + 1] = tmp;
					i++;
				}
			}
			break;
		}
	}
}