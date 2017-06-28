/*
*
* 面试题3：二维数组的查找
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
* 每一列都按照从上到下递增的顺序排序。
* 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
* 例如:
* 1   2    8     9
* 2   4    9    12
* 4   7    10  13
* 6   8    11  15
*
*/

#include <vector>

using std::vector;

bool Find(int target, vector<vector<int>> array) 
{
	if (array.size() == 0 || array[0].size() == 0) {
		return false;
	}
	int row = 0;
	int col = array[0].size() - 1;
	//从右上角查找，向下增加，向左减小
	while (row < array.size() && col >= 0) {
		if (array[row][col] == target) {
			return true;
		}
		//目标值大，往下
		if (array[row][col] < target) {
			row++;
		}
		//目标值小，往左
		else {
			col--;
		}
	}
	return false;
}