#include "StackNode.h"
#include "Stack.h"

#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue {
	public:
		int pop();
		int peek();
		void push(int value);
		bool isEmpty();
		void shift();

	private:
		Stack sstack;
		Stack qstack;
};

#endif
