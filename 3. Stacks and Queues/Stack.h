#include "StackNode.h"

#ifndef STACK_H
#define STACK_H

class Stack {

public:
	Stack();
	int pop();
	void push(int value);
	int peek();
	bool isEmpty();
	void print();

private:
	StackNode* top;

};

#endif