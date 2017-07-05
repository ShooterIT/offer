/*
*
* 面试题补13：机器人的运动范围
* 地上有一个m行和n列的方格。
* 一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
* 但是不能进入行坐标和列坐标的数位之和大于k的格子。
* 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
* 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*
*/

//计算所有位数之和
int digitNum(int num)
{
	int count = 0;
	while (num > 0){
		count += num % 10;
		num /= 10;
	}
	return count;
}

int movingCountCore(int threshold, int rows, int cols, 
	int row, int col, bool *visited)
{
	int count = 0;
	//判断此位置是否合适
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& !visited[row * cols + col] &&
		(digitNum(row) + digitNum(col) <= threshold)) {
		visited[row * cols + col] = true; //已访问
		//其他四个方向尝试
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}

	return count;
}


int movingCount(int threshold, int rows, int cols)
{
	//特殊值判断
	if (threshold < 0 || rows <= 0 || cols <= 0) {
		return 0;
	}

	//设置访问数组
	bool *visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; i++) {
		visited[i] = false;
	}
	//计算个数
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;

	return count;
}

