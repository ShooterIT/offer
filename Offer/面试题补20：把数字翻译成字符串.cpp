/*
*
* 面试题补20：把数字翻译成字符串
* 给定一个数字，我们按照如下规则把它翻译成字符串：0翻译成‘a’, 
* 1翻译成‘b’...,25翻译成‘z’, 一个数字可能有多种翻译，
* 例如12258有5种翻译，分别为bccfi，bwfi，bczi，mcfi和mzi。
* 请实现一个函数，用来计算一个数字有多少中不同的翻译方法。
*
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//递归
int getTransCount(const string & numstr, int i)
{
	int len = numstr.size();

	//超过长度，只有一种可能
	if (i >= len - 1) {
		return 1;
	}
	//[i]和[i+1]可以组合成一个字符的,有两种方案
	if (i + 1 < len ) {
		int sum = (numstr[i] - '0') * 10 + numstr[i + 1] - '0';
		if (sum > 9 && sum < 26) {
			return getTransCount(numstr,i+1) + getTransCount(numstr,i+2);
		}
	}
	//不能组合成一个字符的
	return getTransCount(numstr, i + 1);
}
//动态规划,从后往前，并记录
int getTransCount(const string & numstr)
{
	int len = numstr.size();
	vector<int>  dp(len);
	int cur = 0;
	for (int i = len - 1; i >= 0; i--) {
		cur = 0;
		//当前数字为方法
		if (i < len - 1) {
			cur = dp[i + 1];
		}else{
			cur = 1;
		}
		//两个能不能组合成一个字符
		if (i < len - 1) {
			int sum = (numstr[i] - '0') * 10 + numstr[i + 1] - '0';
			if (sum > 9 && sum < 26) {
				if (i < len - 2) {
					cur += dp[i + 2];
				}
				else {
					cur += 1;
				}
			}
		}
		dp[i] = cur;
	}
	return dp[0];
}

//获得数字的翻译组合
int getTransCount(int number)
{
	if (number < 0) {
		return 0;
	}
	string numstring = to_string(number);
	//递归方式
	return getTransCount(numstring,0);
	//非递归方式
	return getTransCount(numstring);
}

//牛客网上没有该题目，对应测试如下
//单元测试
void test(char *testname, int index, int expect)
{
	int result = getTransCount(index);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	test("num0", 0, 1);
	test("num10", 10, 2);
	test("num126", 126, 2);
	test("num426", 426, 1);
	test("num12258", 12258, 5);

	return 0;
}