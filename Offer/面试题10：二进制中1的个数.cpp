/*
*
* 面试题10：二进制中1的个数
* 请实现一个函数，输入一个整数
* 输出该二进制表示中1的个数，如9二进制为1001，则输出为2。
*
*/

int  NumberOf1(int n) 
{
	int count = 0;
	unsigned int flag = 1; //控制整数的长度
	while (flag) {
		if (n & flag) { //对应的位上是否为1
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
		//去掉第一个1
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
*	把一个整数减去1之后再和原来的整数做位与运算，
*   得到的结果相当于是把整数的二进制表示中的最右边一个1变成0
*/
