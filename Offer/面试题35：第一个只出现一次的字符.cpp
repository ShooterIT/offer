/*
*
* 面试题35：第一个只出现一次的字符
* 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*
*/

#include <string>

using namespace std;


int FirstNotRepeatingChar(string str) 
{
	//特殊值判断
	if (!str.size()) {
		return 0;
	}
	//字符hash表
	const int size = 256;
	unsigned int hash_table[256];
	for (int i = 0; i < size; i++) {
		hash_table[i] = 0;
	}
	//统计字符串的字符
	for (auto ch : str) {
		hash_table[ch]++;
	}
	//找出第一个字符个数为1的字符
	for (int i = 0; i < str.size(); i++) {
		if (1 == hash_table[str[i]]) {
			return i;
		}
	}
	return 0;
}

//字符流中第一个只出现一次的字符
//请实现一个函数用来找出字符流中第一个只出现一次的字符。
//例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
//当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
class Solution
{
public:
	int idx;
	int occurrence[256];
	Solution():idx(1)
	{
		for (int i = 0; i < 256; ++i) {
			occurrence[i] = 0;
		}
	}
	//插入一个字符，hash表建立字符对应位置
	void Insert(char ch)
	{
		//第一次出现hash值为索引
		if (occurrence[ch] == 0) {
			occurrence[ch] = idx++;
		//再次出现hash值为-1
		}else if(occurrence[ch] > 0){
			occurrence[ch] = -1;
		}
	}
	//字符流中第一个字符
	char FirstAppearingOnce()
	{
		char ch;
		int min = INT_MAX;
		//统计下标索引最小的
		for (int i = 0; i < 256; ++i) {
			if (occurrence[i]>0 && occurrence[i] < min) {
				ch = (char)i;
				min = occurrence[i];
			}
		}
		return ch;
	}
};
