/*
*
* 面试题49：把字符串转换成整数
* 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
* 数值为0或者字符串不是一个合法的数值则返回0 
*
*/
#include <cctype>
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
	//过滤掉空格
	while (isspace(str[idx])){
		idx++;
	}
	//正负号的判断
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
	//字符转数字
	for (int i = idx; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + str[i] - '0';
		}
		else {
			return 0;
		}
	}
	//结果
	result = minus ? -result : result;
	//范围判读
	if (result > INT_MAX || result < INT_MIN) {
		return 0;
	}
	return result;

}