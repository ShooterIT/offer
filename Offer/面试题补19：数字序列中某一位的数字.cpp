/*
*
* 面试题补19：数字序列中某一位的数字
* 数字以0123456789101112131516...的格式序列化到一个字符序列中，
* 在这个序列中，第5为是5，第19为是4，等等，请写一个函数，求任意第n位对应的数字。
*
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int digitAtIndex(int index)
{
	int digits;
	for (digits = 1; ; digits++) {
		//计算digits位数的个数，如2位数10-99，共90个，长度为2*90
		int count = (digits == 1) ? 10 : 9 * (int)pow(10, digits - 1);
		//index与其长度比较
		if (index < digits * count) {
			break;
		}
		else {
			index -= digits * count;
		}
	}
	//对应digits位数的起始数值，如3位数的起始数值为100
	int begin = (digits == 1) ? 0 : pow(10, digits - 1);
	//该index对应的数值
	int result = begin + index / digits;
	//该数值中对应的位
	for (int j = 1; j < (digits - index % digits); j++) {
		result /= 10;
	}
	result %= 10;

	return result;
}
//牛客网上没有该题目，对应测试如下
//单元测试
void test(char *testname, int index, int expect)
{
	int result = digitAtIndex(index);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	test("index0", 0, 0);
	test("index1", 1, 1);
	test("index9", 9, 9);
	test("index10", 10, 1);
	test("index189", 189, 9);  // 数字99的最后一位，9
	test("index190", 190, 1);  // 数字100的第一位，1
	test("index1000", 1000, 3); // 数字370的第一位，3
	test("index1001", 1001, 7); // 数字370的第二位，7
	test("index1002", 1002, 0); // 数字370的第三位，0
	return 0;
}