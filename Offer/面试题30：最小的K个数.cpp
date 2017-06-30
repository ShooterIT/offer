/*
*
* 面试题30：最小的K个数
* 输入n个整数，找出其中最小的K个数。
* 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*
*/

#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int> result;
	//特殊值处理
	if (input.size() == 0 || k < 1 || input.size() < k) {
		return result;
	}
	//优先队列，维护最小的k个数
	priority_queue<int> pq;
	for (int v : input) {
		//小于k个时，直接放入
		if (pq.size() < k) {
			pq.push(v);
		}else{
			//如果堆中最大值大于v，则弹栈，压该值
			int max_val = pq.top();
			if (max_val > v) {
				pq.pop();
				pq.push(v);
			}
		}
	}
	while (!pq.empty()){
		result.push_back(pq.top()); pq.pop();
	}
	return result;
}