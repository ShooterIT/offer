/*
*
* 面试题35：第一个只出现一次的字符
*
*/

#include <string>

using namespace std;

//剑指offer题目
char FirstNotRepeatingChar_offer(string str) 
{
	if (!str.size()) {
		return 0;
	}
	const int size = 256;
	unsigned int hash_table[256];
	for (int i = 0; i < size; i++) {
		hash_table[i] = 0;
	}
	for (auto ch : str) {
		hash_table[ch]++;
	}

	for (int i = 0; i < size; i++) {
		if (hash_table[i] == 1) {
			return i;
		}
	}
	return 0;
}
//牛客网
int FirstNotRepeatingChar(string str) 
{
	if (!str.size()) {
		return 0;
	}
	const int size = 256;
	unsigned int hash_table[256];
	for (int i = 0; i < size; i++) {
		hash_table[i] = 0;
	}
	for (auto ch : str) {
		hash_table[ch]++;
	}

	for (int i = 0; i < str.size(); i++) {
		if (1 == hash_table[str[i]]) {
			return i;
		}
	}
	return 0;
}

//字符流中第一个只出现一次的字符
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
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (occurrence[ch] == 0) {
			occurrence[ch] = idx++;
		}else if(occurrence[ch] > 0){
			occurrence[ch] = -1;
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char ch = '#';
		int min = INT_MAX;
		for (int i = 0; i < 256; ++i) {
			if (occurrence[i]>0 && occurrence[i] < min) {
				ch = (char)i;
				min = occurrence[i];
			}
		}
		return ch;
	}

};
