/*
*
* 面试题45：圆圈中的最后剩下的数字
*
*/

int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1) {
		return -1;
	}
	int *circle = new int[n];
	for (int i = 0; i < n; i++) {
		circle[i] = i;
	}
	int count = n;
	int i = 0, step = 0;
	while (count > 0) {
		i++;
		if (i == n) {
			i = 0;
		}
		if (circle[i] == -1) {
			continue;
		}
		step++;
		if (step == m) {
			circle[i] = -1;
			step = 0;
			count--;
		}
	}
	return i-1;
}