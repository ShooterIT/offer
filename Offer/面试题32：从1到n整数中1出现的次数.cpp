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


int NumberOf1Between1AndN_Solution_2(int n)
{
	int count = 0;//1的个数
	int i = 1;//当前位
	int current = 0, after = 0, before = 0;
	while ((n / i) != 0) {
		current = (n / i) % 10; //高位数字
		before = n / (i * 10); //当前位数字
		after = n - (n / i)*i; //低位数字
							   //如果为0,出现1的次数由高位决定,等于高位数字 * 当前位数
		if (current == 0) {
			count += before*i;
		}
		//如果为1,出现1的次数由高位和低位决定,高位*当前位+低位+1
		else if (current == 1) {
			count += before * i + after + 1;
		}
		//如果大于1,出现1的次数由高位决定,//（高位数字+1）* 当前位数
		else {
			count += (before + 1) * i;
		}
		//前移一位
		i = i * 10;
	}
	return count;
}