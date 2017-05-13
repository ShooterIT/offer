/*
*
* 面试题7：用两个栈实现队列
*
*/

#include <stack>

using std::stack;

stack<int> stack1;
stack<int> stack2;

void push(int node) 
{
	stack1.push(node);
}

int pop() 
{
	if (stack2.empty()) {
		//拷贝stack1
		while (!stack1.empty()) {
			int v = stack1.top(); stack1.pop();
			stack2.push(v);
		}
	}
	if (stack2.empty()) {
		throw;
	}

	int v = stack2.top();
	stack2.pop();
	
	return v;
}
	