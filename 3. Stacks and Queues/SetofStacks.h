#include "StackNode.h"
#include "Stack.h"
#include <vector>
using std::vector;

#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H

class SetofStacks {

public:
	SetofStacks();
	int pop();
	// int popAt(int index);
	void push(int value);
	int peek() const;
	bool isEmpty() const;
	void print();

private:
	const static unsigned sizePerStack = 3; //using three as an example
	vector<Stack> stackList;
	unsigned topIndex;
};

#endif