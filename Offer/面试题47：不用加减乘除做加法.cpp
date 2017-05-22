/*
*
* 面试题47：不用加减乘除做加法
*
*/

int Add(int num1, int num2)
{
	int  sum;
	while (num2 != 0){
		sum = num1 ^ num2;
		num2 = (num1 & num2) << 1;
		num1 = sum;
	} 

	return num1;
}
