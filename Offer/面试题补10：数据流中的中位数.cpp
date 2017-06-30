/*
*
* 面试题补10：数据流中的中位数
* 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
* 那么中位数就是所有数值排序之后位于中间的数值。
* 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
*
*/

#include <queue>
#include <functional>

using namespace std;
//最大堆（维护小数）
priority_queue<int, vector<int>, less<int>>  maxheap;
//最小堆（维护大数）
priority_queue<int,vector<int>, greater<int>> minheap;

void Insert(int num)
{
	//当前值较小，插入最大堆，否则插入最小堆
	if (!maxheap.size() || num <= maxheap.top()) {
		maxheap.push(num);
	}else{
		minheap.push(num);
	}
	//维护两个堆的平衡，最大堆大小不小于最小堆，当然不能比最小堆大2个。
	if (maxheap.size() == minheap.size() + 2) {
		minheap.push(maxheap.top());
		maxheap.pop();
	}
	if (maxheap.size() == minheap.size() - 1) {
		maxheap.push(minheap.top());
		minheap.pop();
	}
}

double GetMedian()
{
	//两个堆大小一致，则最大堆的头和最小堆的头之和除以2就是中位数
	if (maxheap.size() == minheap.size()) {
		return (double)(maxheap.top() + minheap.top()) / 2;
	}
	//否则返回最大堆的头
	else {
		return (double)maxheap.top();
	}
}

