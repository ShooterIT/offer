/*
*
* 面试题21：包含min函数的栈
* 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*
*/

#include <stack>

using std::stack;

stack<int> data_stack;
stack<int> min_stack;
void push(int value) {
	data_stack.push(value);
	if (min_stack.empty()) {
		min_stack.push(value);
	}
	else {
		min_stack.push(value < min_stack.top() ? value : min_stack.top());
	}
}

void pop() 
{
	data_stack.pop();
	min_stack.pop();
}

int top() 
{
	return data_stack.top();
}

int min() 
{
	return min_stack.top();
}