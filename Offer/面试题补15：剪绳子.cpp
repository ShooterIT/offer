/*
*
* 面试题补16：剪绳子
* 给你一根长度为n的绳子，请把绳子剪成m段（n,m均大于1），
* 每段长度记为k[0],k[1],...k[m]。请问k[0]*k[1]...*k[m]
* 可能的最大乘积是多少。例如绳长为8，剪成三段2,3,3，此时最大乘积是18。
* f(n) = max(i, f(i) * f(n-i)); 其中  0 < i < n。
* 
*/
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int maxProductAfterCutting(int length)
{
	//边界,因为题目中m>1，则至少剪一次
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;

	//创建dp数组
	int *dp = new int[length+1];
	dp[0] = 0; dp[1] = 1;

	int res = 0;
	//从下往上求解
	for (int i = 2; i <= length; i++) {
		res = 0;
		//绳子长度为i时，最优解，尝试每一种剪法
		for (int j = 1; j <= i / 2; j++) {
			int val = dp[j] * dp[i - j];
			res = max(i, max(res, val));
		}
		dp[i] = res;
	}
	res = dp[length];
	delete[] dp;

	return res;
}
//牛客网上没有该题目，对应测试如下
//单元测试
void test(char *testname, int len, int expect)
{
	int result = maxProductAfterCutting(len);
	if (result == expect) {
		cout<< testname <<" passed."<<endl;
	}
	else { 
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	test("length1", 1, 0);
	test("length2", 2, 1);
	test("length8", 8, 18);
	test("length50", 50, 86093442);
	
	return 0;
}
