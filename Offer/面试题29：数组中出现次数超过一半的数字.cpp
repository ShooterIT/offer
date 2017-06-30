/*
*
* 面试题29：数组中出现次数超过一半的数字
* 数组中有一个数字出现的次数超过数组长度的一半，
* 请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
* 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*
*/

#include <vector>
#include <functional>

using namespace std;

int parition(vector<int> &numbers, int start, int end)
{
	if (start >= end) {
		return end;
	}
	/* static int first = 0;
	if(!first){
	  first = 1;
	  srand((unsigned)time(0));
	}
	int rand_num = start + rand() % (end - start + 1);
	swap(numbers[end],numbers[rand_num]);
	*/
	//快排的查找
	int key = numbers[end];
	int i = start;
	for (int j = start; j < end; j++) {
		if (numbers[j] < key) {
			swap(numbers[i++], numbers[j]);
		}
	}
	//最后交换，注意不是数值，而是两个下标对应的内容
	swap(numbers[i], numbers[end]);

	return i;
}

//partition方法
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.size() == 0) {
		return 0;
	}

	int start = 0;
	int end = numbers.size() - 1;
	int mid = start + (end - start) / 2;
	int idx = 0;
	//划分，直到索引返回的为中间数
	while ((idx = parition(numbers, start, end)) != mid) {
		if (idx > mid) {
			end = idx - 1;
		}
		else {
			start = idx + 1;
		}
	}
	//检验次数是否超过一半
	int result = numbers[mid];
	int times = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == result) {
			times++;
		}
	}
	return times > numbers.size() / 2 ? result : 0;
}


int MoreThanHalfNum_Solution2(vector<int> numbers)
{
	if (numbers.size() == 0) {
		return 0;
	}
	int result = numbers[0]; //当前存储数值
	int times = 1;			 //次数
	for (int i = 1; i < numbers.size(); i++) {
		if (times == 0) { //重置，当前存储数值和次数
			result = numbers[i];
			times = 1;
		}else if(numbers[i] == result){
			times++;
		}else{
			times--;
		}
	}
	times = 0;
	//校验
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == result) {
			times++;
		}
	}
	return times > numbers.size() / 2 ? result : 0;
}
