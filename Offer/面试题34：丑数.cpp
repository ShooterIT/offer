/*
*
* ÃæÊÔÌâ34£º³óÊı
*
*/

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int GetUglyNumber_Solution(int index) 
{
	if (index < 7) {
		return index;
	}

	vector<int> result(index);
	int m2 = 0, m3 = 0, m5 = 0;
	result[0] = 1;
	for (int i = 1; i < index; i++) {
		int val = min(result[m2] * 2, min(result[m3] * 3, result[m5] * 5));
		if (val == result[m2] * 2) {
			result[i] = val;
			m2++;
		}
		if (val == result[m3] * 3) {
			result[i] = val;
			m3++;
		}
		if (val == result[m5] * 5) {
			result[i] = val;
			m5++;
		}
	}
	return result[index - 1];

}
