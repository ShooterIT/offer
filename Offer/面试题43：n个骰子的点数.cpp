/*
*
* 面试题43：n个骰子的点数
*
*/

#include <iostream>
#include <cmath>

using namespace std;

const int max_val = 6;

//核心，计算概率
//original为起始值，n个骰子起始值为n
//current为当前骰子个数
//骰子数之和
//和对应的次数
void probalility(int original, int current, int sum, int *probabilities)
{
	if (current == 1) {
		probabilities[sum - original]++;
	}
	else{
		//每个骰子都有六种可能
		for (int i = 1; i <= max_val; i++) {
			probalility(original, current - 1, i + sum, probabilities);
		}
	}
}
//计算概率
void probalility(int number, int *probabilities)
{
	for (int i = 1; i <= max_val; i++) {
		probalility(number, number, i, probabilities);
	}
}


void PrintPrabability(int number)
{
	if (number < 1) {
		return;
	}
	//申请空间
	int max_sum = number * max_val;
	int *probabilities = new int[max_sum];
	for (int i = number; i <= max_sum; i++) {
		probabilities[i] = 0;
	}
	//计算可能的情况
	probalility(number, probabilities);

	//计算概率
	int total = pow(double(max_val), number);
	for (int i = number; i <= max_sum; i++) {
		double ratio = (double)probabilities[i - number] / total;
		cout << i << " " << ratio << endl;
	}
}

/*
int main(void)
{
	PrintPrabability(3);
	getchar();
	return 0;
}
*/