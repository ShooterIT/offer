/*
*
* 面试题28：字符串的排列
*
*/

#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> result;
void Permutation(string str, int idx)
{
	if (idx == str.size()) {
		result.push_back(str);
	}
	else {
		sort(str.begin() + idx, str.end());
		for (int i = idx; i < str.size(); i++) {
			if (idx != i && str[idx] == str[i]) {
				continue;
			}
			swap(str[idx], str[i]);
			Permutation(str, idx + 1);
			swap(str[i], str[idx]);
		}
	}
}
vector<string> Permutation(string str) {
	if (!str.size()) {
		return result;
	}
	Permutation(str, 0);
	return result;
}