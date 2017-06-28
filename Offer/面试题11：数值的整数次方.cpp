/*
*
* 面试题11：数值的整数次方
* 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*
*/

double power_with_exponent(double base, long long exponent)
{
	//幂为0
	if (exponent == 0) {
		return 1.0;
	}
	//偶数部分(用位运算代替乘法运算)
	double result = power_with_exponent(base, exponent >> 1);
	result *= result;
	//如果是计算再乘一个基本值
	if(exponent & 0x01 == 1){
		result *= base;
	}
	return  result;
}

double Power(double base, int exponent) 
{
	//base为0.0则发货0.0
	if (base - 0.0 < 0.000001) {
		return 0.0;
	}

	//判断正负，负的为：1.0/对应值
	long long exp = exponent;
	if(exponent < 0){
		exp = -exponent;
	}
	double result = power_with_exponent(base, exp);
	return exponent < 0 ? 1.0 / result : result;
}
