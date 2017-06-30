/*
*
* 面试题33：把数组排成最小的数
* 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
* 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
* 则打印出这三个数字能排成的最小数字为321323。
*
*/

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string PrintMinNumber(vector<int> numbers)
{
	string result;
	//特殊值判断
	if (!numbers.size()) {
		return result;
	}
	
	vector<string> vs;
	for (auto val : numbers) {
		//转换为字符串
		stringstream ss;
		ss << val;
		vs.push_back(ss.str());
	}
	//排序
	sort(vs.begin(), vs.end(), [](const string &a, const string &b) {
		string s1 = a + b;
		string s2 = b + a;
		return s1 < s2;
	});
	//输出
	for (auto val : vs) {
		result += val;
	}
	return result;
}
