/*
*
* 面试题4：替换空格
* 请实现一个函数，将一个字符串中的空格替换成“%20”。
* 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*
*/

//字符串拷贝函数
//返回值，为了实现链式拷贝
char *strcpy(char *dst, const char *src)
{
	//特殊值判断
	if (dst == nullptr || src == nullptr) {
		return nullptr;
	}
	//返回值
	char *start = dst;
	//拷贝
	while ((*dst++ = *src++))
		;
	return start;
}

void replaceSpace(char *str)
{
	//特殊值
	if (str == nullptr) {
		return;
	}
	int i = 0;
	int newlen = 0;
	int oldlen = 0;
	//计算长度
	while (str[i] != '\0') {
		oldlen++;
		newlen++;
		if (str[i] == ' ') {
			newlen += 2;
		}
		i++;
	}
	//新索引大于就索引说明前面有空格，否则没有空格
	while (oldlen >= 0 && oldlen < newlen) { 
		//遇到空格,替换
		if (str[oldlen] == ' ') {
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		//不是空格，直接替换
		else {
			str[newlen] = str[oldlen];
			newlen--;
		}
		oldlen--;
	}
}