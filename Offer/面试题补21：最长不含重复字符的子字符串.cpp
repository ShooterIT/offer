/*
*
* 面试题补22：最长不含重复字符的子字符串
* 请从字符串中找出一个最长不含重复字符的子字符串，计算该最长子字符串的长度。
* 例如字符串“arabcacfr”中，最长不含重复字符的子字符串是“acfr”，长度为4。 
*
*/


#include <string>
#include <vector>
#include <iostream>

using namespace std;

int longestSubStringWithoutDuplication(const string &str)
{
	if (str.size() == 0) {
		return 0;
	}
	//历史最长，当前最长
	int max = 0, cur = 0;
	vector<int> hash(26, -1);
	//遍历每一个字符
	for (int i = 0; i < str.size(); i++) {
		int preidx = hash[str[i] - 'a'];
		//之前为存储过或者重复字符距离大于当前最长未重复距离，则cur++;
		if (preidx < 0 || i - preidx > cur) {
			cur++;
		}
		//存储过，且在重复
		else {
			cur = i - preidx; //(i-1) - preidx + 1；
		}
		//存储字符对应的下标索引
		hash[str[i] - 'a'] = i;

		if (cur > max) {
			max = cur;
		}
	}
	return max;
}

//牛客网上没有该题目，对应测试如下
//单元测试
void test(char *testname,string str, int expect)
{
	int result = longestSubStringWithoutDuplication(str);
	if (result == expect) {
		cout << testname << " passed." << endl;
	}
	else {
		cout << testname << " failed." << endl;
	}

}

int main(void)
{
	test("num0", "h", 1);
	test("num10", "hihi", 2);
	test("num126", "arabcacfr", 4);
	test("num12258", "", 0);

	return 0;
}