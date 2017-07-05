/*
*
* 面试题46：求1+2+...+n
* 求1+2+3+...+n，要求不能使用乘除法、for、while、if、
* else、switch、case等关键字及条件判断语句（A?B:C）。
*
*/

//递归
int Sum_Solution_1(int n) 
{
	int  sum = n;
	//首先n>0，否则递归调用，实际上也是if
	bool flag = (n && (sum += Sum_Solution_1(n - 1)));
	return sum;
}

//静态变量方法
class tmp
{
public:
	static int n;
	static int sum;
	//每次创建对象都会增加该变量
	tmp() { n++; sum += n; }
};
//初始化
int tmp::n = 0;
int tmp::sum = 0;

int Sum_Solution(int n)
{
	//创建n个对象
	tmp *t = new tmp[n];
	delete[] t;
	t = nullptr;
	//返回累加值
	return tmp::sum;
}


//函数指针方法
typedef int(*fun)(int);
int solution1(int n)
{
	return 0;
}

int solution2(int n) 
{
	static fun f[2] = { solution1,solution2 };
	//n > 0 !!n == 1;  n==0,!!n = 0
	return n + f[!!n](n - 1);
}

int Sum_Solution2(int n) 
{
	return solution2(n);
}
