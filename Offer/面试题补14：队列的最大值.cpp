/*
*
* 面试题补14：队列的最大值
*
*/

#include <vector>
#include <queue>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	if (!num.size() || num.size() < size || size <= 0) {
		return result;
	}

	deque<int> di;
	for (int i = 0; i < size; ++i) {
		while (!di.empty() && num[i] >= num[di.back()]){
			di.pop_back();
		}
		di.push_back(i);
	}

	for (unsigned int i = size; i < num.size(); ++i) {
		result.push_back(num[di.front()]);
		while (!di.empty() && num[i] >= num[di.back()]) {
			di.pop_back();
		}
		if (!di.empty() && di.front() < (i - size)) {
			di.pop_front();
		}
		di.push_back(i);
	}
	result.push_back(num[di.front()]);
	return result;

}
