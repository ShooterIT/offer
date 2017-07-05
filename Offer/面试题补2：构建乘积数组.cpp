/*
*
* 面试题补2：构建乘积数组
* 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
* 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*
*/

#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& A) 
{
	vector<int> B(A.size());
	if (!A.size()) {
		return B;
	}
	//A[0]*A[1]*...*A[i-1]部分的计算
	B[0] = 1;
	for (int i = 1; i < A.size(); i++) {
		B[i] = B[i - 1] * A[i - 1];
	}
	//A[i+1]*...*A[n-1]部分的计算
	int tmp = 1;
	for (int i = A.size() - 2; i >= 0; i--) {
		tmp *= A[i + 1];
		B[i] *= tmp;
	}

	return B;
}
