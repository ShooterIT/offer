/*
*
* 面试题12：打印1到最大的n位数
* 输入n，按顺序打印从1到最大的n位10进制数，如n=3,则输出1,2,3...999
*
*/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

//模拟加1
void increment(vector<int> &num)
{
	//末尾位加1
	num[0]++;
	for (int i = 0; i < num.size() - 1; i++) {
		//如果进位
		if (num[i] == 10) {
			num[i] = 0;
			num[i + 1]++;
		}else{ //一旦不进位，则不需要继续
			break;
		}
	}
}

void print(const vector<int> &num)
{
	bool isfind = false;
	for (int i = num.size() - 1; i >= 0; i--) {
		if (num[i] != 0) {
			isfind = true;
		}
		if (isfind) {
			cout << num[i];
		}
	}
	cout << endl;
}

void print_1_to_max_n_digits(int n)
{
	if (n <= 0) {
		return;
	}
	//申请空间并清0
	vector<int> number(n+1,0);
	while (1){
		//增加一位
		increment(number);
		//到达上限
		if(number[n] == 1){
			break;
		}
		print(number);
	}
}


