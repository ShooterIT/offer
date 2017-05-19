/*
*
* 面试题30：最小的K个数
*
*/

#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int> result;
	if (!input.size() || k < 1 || input.size() < k) {
		return result;
	}
	priority_queue<int> pq;
	for (auto val : input) {
		if (pq.size() < k) {
			pq.push(val);
		}
		else {
			if (val < pq.top()) {
				pq.pop();
				pq.push(val);
			}
		}
	}

	while (!pq.empty()) {
		result.push_back(pq.top()); pq.pop();
	}
	return result;
}