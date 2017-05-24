/*
*
* 面试题补2：构建乘积数组
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
	B[0] = 1;
	for (int i = 1; i < A.size(); i++) {
		B[i] = B[i - 1] * A[i - 1];
	}
	int tmp = 1;
	for (int i = A.size() - 2; i >= 0; i--) {
		tmp *= A[i + 1];
		B[i] *= tmp;
	}

	return B;
}
