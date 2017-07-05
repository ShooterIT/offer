/*
*
* 面试题45：圆圈中的最后剩下的数字
* 0,1,...,n-1这n个数字排成一个圆圈，从数字0开始，
* 每次从这个圆圈中删除第m个数字，求出这个圆圈里最后一个数字。
*
*/

int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1) {
		return -1;
	}
	//创建数组，用作模拟
	int *circle = new int[n];
	for (int i = 0; i < n; i++) {
		circle[i] = i;
	}
	int count = n;
	//i为数组下标的索引，step为走的步数
	int i = -1, step = 0;
	//剩余的个数大于0
	while (count > 0) {
		i++;
		if (i == n) {
			i = 0;
		}
		//该位置已经被删除过
		if (circle[i] == -1) {
			continue;
		}
		step++;
		//已经走了m步
		if (step == m) {
			circle[i] = -1;
			step = 0;
			count--;
		}
	}
	return i;
}