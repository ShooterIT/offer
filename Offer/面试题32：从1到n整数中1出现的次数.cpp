/*
*
* 面试题32：从1到n整数中1出现的次数
*
*/

int NumberOf1Between1AndN_Solution(int n)
{
	int number = 0;
	for (int i = 1; i <= n; i++) {
		int val = i;
		while (val){
			if (val % 10 == 1) {
				number++;
			}
			val /= 10;
		}
	}
	return number;
}