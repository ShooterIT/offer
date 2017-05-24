/*
*
* 面试题补10：数据流中的中位数
*
*/

#include <queue>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, less<int>>  maxheap;
priority_queue<int,vector<int>, greater<int>> minheap;

void Insert(int num)
{
	if (!maxheap.size() || num <= maxheap.top()) {
		maxheap.push(num);
	}else{
		minheap.push(num);
	}
	if (maxheap.size() == minheap.size() + 2) {
		minheap.push(maxheap.top());
		maxheap.pop();
	}
	if (maxheap.size() + 1 == minheap.size()) {
		maxheap.push(minheap.top());
		minheap.pop();
	}
}

double GetMedian()
{
	if (maxheap.size() == minheap.size()) {
		return (double)(maxheap.top() + minheap.top()) / 2;
	}
	else {
		return (double)maxheap.top();
	}
}

