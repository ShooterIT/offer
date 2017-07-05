/*
*
* 面试题补18：表示数值的字符串
* 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
* 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
* 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
* 表示数值的字符串遵循模式A[.[B]][e|EC]或者.B[e|EC],
* 其中A为数值的整数部分，B紧跟着小数点为数值的小数部分，
* C紧跟着'e'或者'E'为数值的指数部分。也是一个有限状态机问题。
*
*/

//扫描无符号整数
bool scanUnsignedInteger(char* &str)
{
	const char *before = str; //记录起始位置
	while (*str != '\0' && *str >= '0' && *str <= '9') {
		str++;
	}
	return str > before; //扫描存在的数字
}

//扫描有符号整数
bool scanInteger(char* &str)
{
	if (*str == '+' || *str == '-') {
		str++;
	}
	return scanUnsignedInteger(str);
}

bool isNumeric(char* string)
{
	if (string == nullptr) {
		return false;
	}
	//扫描A部分
	bool numeric = scanInteger(string);

	//小数部分
	if (*string == '.') {
		++string;
		//使用||的原因，可以没有整数部分，也可以没有小数部分
		//.123 233. 233.444
		numeric = numeric || scanUnsignedInteger(string);
	}
	//E或者e，则接下来是数字的指数部分
	if (*string == 'e' || *string == 'E') {
		++string;
		//&&原因，1 e|E之前必须有内容， e后面必须有整数
		numeric = numeric && scanInteger(string);
	}
	return numeric && (*string == '\0');
}
