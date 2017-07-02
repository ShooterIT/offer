/*
*
* 面试题40：数组中只出现一次的数字
* 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
* 请写程序找出这两个只出现一次的数字。
*
*/

#include <vector>
#include <iostream>

using namespace std;

//第一位为1的下标
unsigned int find_first_bit1(int num)
{
	int idx = 0;
	while (((num & 1) == 0) && (idx < 8 *sizeof(int))){
		num >>= 1;
		idx++;
	}
	return idx;
}

//判断该位是否是1
bool is_bit1(int num, unsigned int idx)
{
	num >>= idx;
	return (num & 1);
}

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
{
	if (data.size() < 2) {
		return;
	}
	//所有异或结果
	int allor = 0;
	for (auto v : data) {
		allor ^= v;
	}
	//第一位为1的下标
	unsigned int idx = find_first_bit1(allor);
	//分组，并就算该函数
	*num1 = *num2 = 0;
	for (auto v : data) {
		//分组
		if (is_bit1(v,idx)) {
			*num1 ^= v; //计算
		}else{
			*num2 ^= v;
		}
	}
}


//第二版：补充
/*
*
* 题目二：数组中唯一出现一次的数字
* 在一个数组中除了一个数字只出现了一次之外，其他数字都出现了三次，请找出那个只出现一次的数字。
*
*/
int findNumberAppearOnce(vector<int> data)
{
	if (data.size() == 0) {
		return -1;
	}
	int allbit[32] = { 0 };
	//遍历每一个数
	for (int i = 0; i < data.size(); i++) {
		//遍历每一位,计算每一位之和
		int mask = 1;
		for (int j = 31; j >= 0; j--) {
			int bit = data[i] & mask;
			if (bit != 0){
				allbit[j] += 1;
			}
			mask <<= 1;
		}
	}
	int result = 0;
	//取余
	for (int i = 0; i < 32; i++) {
		result = result << 1;
		result += allbit[i] % 3;
	}
	return result;
}