/*
*
* 面试题42：翻转单词顺序 VS 左旋转字符串
*
*/

#include <string>

using namespace std;

void reverse(string &str, int beg, int end)
{
	while (end > beg){
		swap(str[beg], str[end]);
		end--;
		beg++;
	}
}
//翻转单词顺序
//I am a student. ==> student. a am I
string ReverseSentence(string str) 
{
	if (!str.size()) {
		return str;
	}
	//反转整体
	reverse(str, 0, str.size() - 1);
	//反转单词
	int start = 0; 
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			reverse(str, start, i - 1);
			start = i + 1;
		}
	}
	//别玩了反转最后一个单词，它是没有空格间隔的
	reverse(str, start, str.size() - 1);

	return str;
}

//左旋转字符串
//
string LeftRotateString(string str, int n) 
{
	if (!str.size() || n > str.size() || n < 1) {
		return str;
	}
	//反转所有
	reverse(str, 0, str.size() - 1);
	//反转前面部分，使其顺序
	reverse(str, 0, str.size() - n - 1);
	//反转后面部分，使其顺序
	reverse(str, str.size() - n, str.size() - 1);

	return str;
}