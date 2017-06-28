/*
*
* 面试题补11：矩阵中的路径
* 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
* 路径可以从矩阵中的任意一个格子开始，
* 每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
* 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
* 例如 a b c e s f c s a d e e 矩阵中包含一条字符串”bcced”的路径，
* 但是矩阵中不包含”abcb”路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
* 路径不能再次进入该格子。
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
	//判断此位置是否满足
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[length] &&
		!visited[row * cols + col]) {
		//满足尝试字符串中的下一个位置
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
		//字符串下一个位置都不匹配
		//则此位置不是正确路径上的解，所以回退，尝试下一个位置
		if (!ishasPath) {
			length--;
			visited[row * cols + col] = false;
		}
	}
	return ishasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	//边界以及特殊值检查
	if (!matrix || rows <= 0 || cols <= 0 || !str) {
		return false;
	}

	//是否访问过的数组
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	int length = 0;
	//从第一个位置开始尝试
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (hasPathCore(matrix, rows, cols, row, col, str, length, visited)) {
				return true;
			}
		}
	}
	return false;
}