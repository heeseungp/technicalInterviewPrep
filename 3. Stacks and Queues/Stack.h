#include "StackNode.h"

#ifndef STACK_H
#define STACK_H

class Stack {

public:
	Stack();
	int pop();
	void push(int value);
	int peek() const;
	bool isEmpty() const;
	void print();
	int getSize() const;
	StackNode* getTop() const;
	void sortStack();
protected:
	StackNode* top;
	int size;
};

#endif