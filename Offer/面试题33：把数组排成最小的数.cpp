/*
*
* 面试题33：把数组排成最小的数
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
	if (!numbers.size()) {
		return result;
	}

	vector<string> vs;
	for (auto val : numbers) {
		stringstream ss;
		ss << val;
		vs.push_back(ss.str());
	}
	sort(vs.begin(), vs.end(), [](const string &a, const string &b) {
		string s1 = a + b;
		string s2 = b + a;
		return s1 < s2;
	});
	
	for (auto val : vs) {
		result += val;
	}
	return result;
}