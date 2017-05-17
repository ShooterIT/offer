/*
*
* 面试题20：顺时针打印矩阵
*
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> result;
	if (matrix.size() == 0) {
		return result;
	}
	int start = 0;
	int row = matrix.size();
	int col = matrix[0].size();
	while ((row + 1) / 2 > start && (col + 1) / 2 > start) {
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