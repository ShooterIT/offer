/*
*
* 面试题4：替换空格
*
*/

void replaceSpace(char *str)
{
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
	//进行替换
	while (oldlen >= 0 && oldlen < newlen) {
		if (str[oldlen] == ' ') {
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else {
			str[newlen--] = str[oldlen];
		}
		oldlen--;
	}
}