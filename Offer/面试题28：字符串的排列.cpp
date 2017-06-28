/*
*
* 面试题28：字符串的排列
* 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
* 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*
*/

#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> result;
void Permutation(string& str, int idx)
{
	//终止条件
	if (idx == str.size()) {
		result.push_back(str);
	}else{
		//之后内容排序
		sort(str.begin() + idx, str.end());
		for (int j = idx; j < str.size(); j++) {
			//排除相等的
			if (j != idx && str[idx] == str[j]) {
				continue;
			}
			swap(str[idx], str[j]);
			Permutation(str, idx + 1);//下标+1
			swap(str[idx], str[j]);
		}
	}
}
vector<string> Permutation(string str) {
	//非空，排列
	if (str.size()) {
		Permutation(str, 0);
	}
	return result;
}
