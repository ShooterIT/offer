/*
*
* 面试题10：二进制中1的个数
*
*/

int  NumberOf1(int n) 
{
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag) {
			count++;
		}
		flag <<= 1;
	}
	return count;
}

int  NumberOf1_2(int n)
{
	int count = 0;
	while (n){
		count++;
		n = (n - 1) & n;
	}
	return count;
}

//判断一个整数是不是2的整数次方
bool is2power(int n)
{
	return !((n - 1)&n);
}

//输入两个整数m,n,需要改变m二进制中多少位才能得到n
int change(int m, int n)
{
	//先异或求不同位，在统计1的个数
	return NumberOf1_2(m^n);
}

/*
* NOTE:
*	把一个整数减去1之后再和原来的整数做位与运算，得到的结果相当于是把整数的二进制表示中的最右边一个1变成0
*/
