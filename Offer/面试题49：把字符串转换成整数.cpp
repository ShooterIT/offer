/*
*
* 面试题49：把字符串转换成整数
*
*/

#include <string>

using namespace std;

int StrToInt(string str) 
{ 
	long long result = 0;
	if (!str.size()) {
		return result;
	}
	bool minus = false;
	int idx = 0;
	if (str[idx] == '-') {
		minus = true;
		idx++;
	}
	if (str[idx] == '+') {
		minus = false;
		idx++;
	}
	if (idx >= str.size()) {
		return 0;
	}
	for (int i = idx; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + str[i] - '0';
		}
		else {
			return 0;
		}
	}
	result = minus ? -result : result;
	if (result > INT_MAX || result < INT_MIN) {
		return 0;
	}
	return result;

}