/*
*
* 面试题41：和为s的两个数字VS和为s的连续正数序列
*
*/

#include <vector>

using namespace std;

//为s的连续正数序列
vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int> > result;
	//小于3则肯定不是两个数的和
	if (sum < 3) {
		return result;
	}

	int small = 1;
	int big = 2;
	int cur = 3;
	//范围
	while (small < (sum + 1) / 2){
		//相等，输出即可
		if (cur == sum) {
			vector<int> vi;
			for (int i = small; i <= big; i++) {
				vi.push_back(i);
			}
			result.push_back(vi);
		}
		//当前和大于所求和，增大small，直到cur>small
		while (cur > sum && small < (sum + 1) / 2){
			cur -= small;
			small++;
			if (cur == sum) {
				vector<int> vi;
				for (int i = small; i <= big; i++) {
					vi.push_back(i);
				}
				result.push_back(vi);
				break;
			}
		}
		//增大big
		big++;
		cur += big;
	}

	return result;
}

//和为s的两个数字
vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	vector<int> result;
	if (array.size() > 1) {
		int i = 0;
		int j = array.size() - 1;
		//第一个头，第二个尾
		while (j > i){
			int two = array[i] + array[j];
			//相等输出即可
			if (two == sum) {
				result.push_back(array[i]);
				result.push_back(array[j]);
				break;
			//和大，则减少大数
			}else if(two > sum){
				j--;
			//和小，则增加小数
			}else{
				i++;
			}
		}
	}

	return result;
}