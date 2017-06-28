/*
*
* 面试题20：顺时针打印矩阵
* 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
* 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
* 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) 
{
	vector<int> result;
	if (matrix.size() == 0) {
		return result;
	}
	int start = 0;
	int row = matrix.size();
	int col = matrix[0].size();

	//循环条件，以为是一个环，其实每次当前行数和列数都减2
	while (row > start * 2 && col > start * 2) {
		int endx = row - start;
		int endy = col - start;

		//向右
		for (int i = start; i < endy; i++) {
			result.push_back(matrix[start][i]);
		}
		//向下
		for (int i = start + 1; i < endx; i++) {
			result.push_back(matrix[i][endy - 1]);
		}
		//向左,避免重复
		for (int i = endy - 2; start != endx - 1 && i >= start; i--) {
			result.push_back(matrix[endx - 1][i]);
		}
		//向上,避免重复
		for (int i = endx - 2; start != endy - 1 && i > start; i--) {
			result.push_back(matrix[i][start]);
		}
		start++;
	}
	return result;
}