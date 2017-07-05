/*
 * 
 * 面试题补17：正则表达式匹配
 * 题目：请实现一个函数来匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任何一个字符，
 * 而'*'表示它前面的字符可以出现任意次(含0次)，在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 *
 */

bool match(char* str, char* pattern)
{
	//特殊条件判断
	if (!str || !pattern) {
		return false;
	}
	//模式匹配
	return matchcore(str, pattern);
}

//匹配核心
bool matchcore(char *str, char *pattern)
{
	//都到字符串的尾部，匹配成功
	if (*str == '\0' && *pattern == '\0') {
		return true;
	}
	//字符串没结束，而模式已结束匹配失败
	if (*str != '\0' && *pattern == '\0') {
		return false;
	}

	//下一个字符'*'
	if (*(pattern + 1) == '*') {
		if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
			//当前位置字符匹配时
			return matchcore(str + 1, pattern)    //匹配多次
				|| matchcore(str + 1, pattern + 2)//匹配0次
				|| matchcore(str, pattern+2);     //忽略
		}
		//不匹配，只能跳到下一个匹配位置
		return matchcore(str, pattern + 2);
	}
	//不为'*'，只能比较
	if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
		return matchcore(str + 1, pattern + 1);
	}
	return false;
}
