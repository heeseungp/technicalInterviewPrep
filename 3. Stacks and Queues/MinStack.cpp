#include "StackNode.h"
#include "Stack.h"
#include "MinStack.h"
#include <iostream>
using std::cout;
using std::endl;

int MinStack::pop() {
	int result = Stack::pop();
	if(result != 404) {
		if(result == minStack.peek()) {
			Stack::pop();
			minStack.pop();
			return result;
		}
	}
	return result;
}

void MinStack::push(int value) {
	Stack::push(value);
	if(value <= minStack.peek()) {
		minStack.push(value);
	}
}

int MinStack::getMin() {
	if(minStack.isEmpty()) {
		// cout << "Nothing on Stack, cannot retrieve minimum" << endl;
		return 404;
	} else {
		return minStack.peek();
	}
}