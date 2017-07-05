/*
*
* 面试题补14：队列的最大值
* 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
* 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
* 他们的最大值分别为{4,4,6,6,6,5}； 
*针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
* {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
* {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
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
	//前窗口大小的数据全部放入
	deque<int> di;
	for (int i = 0; i < size; ++i) {
		//当前值大，前面的不可能成为窗口的最大值，所有全部弹出
		while (!di.empty() && num[i] >= num[di.back()]){
			di.pop_back();
		}
		//压进
		di.push_back(i);
	}
	result.push_back(num[di.front()]);//结果

	for (unsigned int i = size; i < num.size(); ++i) {		
		while (!di.empty() && num[i] >= num[di.back()]) {
			di.pop_back();
		}
		//判读当前头部的数据是否过期
		if (!di.empty() && di.front() < (i - size)) {
			di.pop_front();
		}
		di.push_back(i);
		result.push_back(num[di.front()]);
	}
	
	return result;

}


//队列的最大值
//请定义一个队列并实现函数max得到队列里的最大值，
//要求函数max，push和pop的时间复杂度都是O(1)。
template<typename T>
class QueueWithMax
{
public:
	QueueWithMax():cur_idx(0){}
	void push(T v) 
	{
		//先插入的值，比之前最大值大
		while (!maxdat.empty() && v > maxdata.back().val){
			maxdata.pop_back();
		}
		//插入该数据
		Data d = { v, cur_idx };
		data.push_back(d);
		maxdata.push_back(d);
		cur_idx++;
	}
	void pop() 
	{
		if (maxdata.empty()) {
			throw new exception("queue is empty.");
		}
		//如果数据索引等于最大值数据索引，则最大值队列弹出
		if (maxdata.front().index == data.front().index) {
			maxdata.pop_front();
		}
		data.pop_front();
	}
private:
	struct Data {
		T val;
		int index;
	};
	deque<Data> data;
	deque<Data> maxdata;
	int cur_idx; //记录是否过期
};