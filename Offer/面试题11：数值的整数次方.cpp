/*
*
* 面试题11：数值的整数次方
*
*/

double power_with_exponent(double base, long long exponent)
{
	/*double result = 1.0;
	for (long long i = 1; i < exponent; i++) {
		result *= base;
	}
	return result;*/
	if (exponent == 0) {
		return 1.0;
	}
	double result = power_with_exponent(base, exponent >> 1);
	result *= result;
	if(exponent & 0x01 == 1){
		result *= base;
	}
	return  result;
}

double Power(double base, int exponent) 
{
	long long exp = exponent;
	if(exponent < 0){
		exp = -exponent;
	}
	double result = power_with_exponent(base, exp);
	return exponent < 0 ? 1.0 / result : result;
}
