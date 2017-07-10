#include "StackNode.h"
#include "Stack.h"
#include "MyQueue.h"
#include <iostream>
using std::cout;
using std::endl;

int MyQueue::pop() {
	if(sstack.isEmpty() && qstack.isEmpty()) {
		cout << "Cannot Pop; Stack is Empty" << endl;
		return 404;
	} else {
		if(qstack.isEmpty()) {
			this->shift();
		} 
		return qstack.pop();
	}
}

int MyQueue::peek() {
	if(sstack.isEmpty() && qstack.isEmpty()) {
		cout << "Cannot Peek; Stack is Empty" << endl;
		return 404;
	} else {
		if(qstack.isEmpty()) {
			this->shift();
		}
		return qstack.peek();
	}
}

void MyQueue::push(int value) {
	sstack.push(value);
}

bool MyQueue::isEmpty() {
	return (sstack.isEmpty() && qstack.isEmpty());
}

void MyQueue::shift() {
	while(!sstack.isEmpty()) {
		qstack.push(sstack.pop());
	}
}