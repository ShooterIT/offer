/*
*
* 面试题补21：礼物的最大价值
* 在一个m*n的棋盘的每一格都放有一个礼物，每个礼物都有一定价值（>0）。
* 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格，
* 直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请你计算你最多能拿到多少价值的礼物？
*
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000
int maxval[MAX][MAX];

int getMaxValue(const int *gift, int row, int col)
{
	//边界
	if (gift == nullptr || row < 1 || col < 1) {
		return 0;
	}
	//遍历每一个位置
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int up = 0, left = 0;
			//上最大值
			if (i > 0) {
				up = maxval[i - 1][j];
			}
			//左最大值
			if (j > 0) {
				left = maxval[i][j - 1];
			}
			//当前位置最大值
			maxval[i][j] = max(up, left) + gift[i * col + j];
		}
	}
	return maxval[row - 1][col - 1];
}

//牛客网上没有该题目，对应测试如下
//单元测试
void test(char *testname, int *gift, int row, int col, int expect)
{
	int result = getMaxValue(gift,row,col);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	int values1[] = {
		  1, 2, 3 ,
		 4, 5, 6 ,
		 7, 8, 9 
	};

	int values2[] = {1, 10, 3, 8 };
	int values3[] = { 3 };

	test("test1", values1, 3, 3, 29);
	test("test2", values2, 4, 1, 22);
	test("test3", values2, 1, 4, 22);
	test("test4", values3, 1, 1, 3);
	test("test5", nullptr ,0, 0, 0);
	

	return 0;
}