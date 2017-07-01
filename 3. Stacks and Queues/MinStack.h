#include "StackNode.h"
#include "Stack.h"

#ifndef MINSTACK_H
#define MINSTACK_H

class MinStack: public Stack {
	public:
		int pop();
		void push(int value);
		int getMin();
	
	private:
		Stack minStack;
};

#endif