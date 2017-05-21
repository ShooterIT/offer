/*
*
* 面试题40：数组中只出现一次的数字
*
*/

#include <vector>
#include <iostream>

using namespace std;

unsigned int find_first_bit1(int num)
{
	int idx = 0;
	while (((num & 1) == 0) && (idx < 8 *sizeof(int))){
		num >>= 1;
		idx++;
	}
	return idx;
}

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
	int allor = 0;
	for (auto v : data) {
		allor ^= v;
	}
	unsigned int idx = find_first_bit1(allor);

	*num1 = *num2 = 0;
	for (auto v : data) {
		if (is_bit1(v,idx)) {
			*num1 ^= v;
		}else{
			*num2 ^= v;
		}
	}
}