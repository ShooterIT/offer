/*
*
* 面试题补11：矩阵中的路径
*
*/

#include <cstring>

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, 
	char* str, int& length, bool *visited)
{
	if (str[length] == '\0') {
		return true;
	}
	bool ishasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[length] &&
		!visited[row * cols + col]) {
		length++;
		visited[row * cols + col] = true;

		ishasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, length, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col,
				str, length, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1,
				str, length, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col,
				str, length, visited);
		//回溯
		if (!ishasPath) {
			length--;
			visited[row * cols + col] = false;
		}
	}
	return ishasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (!matrix || rows <= 0 || cols <= 0 || !str) {
		return false;
	}

	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	int length = 0;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (hasPathCore(matrix, rows, cols, row, col, str, length, visited)) {
				return true;
			}
		}
	}
	return false;
}