/*
*
* 面试题12：打印1到最大的n位数
*
*/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void increment(vector<int> &num)
{
	num[0]++;
	for (int i = 0; i < num.size() - 1; i++) {
		if (num[i] == 10) {
			num[i] = 0;
			num[i + 1]++;
		}else{
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
	vector<int> number(n+1,0);
	while (1){
		increment(number);
		if(number[n] == 1){
			break;
		}
		print(number);
	}
}


/*
int main(void)
{
	print_1_to_max_n_digits(2);
	getchar();
	return 0;
}
*/