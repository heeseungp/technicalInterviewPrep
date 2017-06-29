#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

class DynamicStack {
public:
	DynamicStack();
	int pop(int index);
	void push(int index, int value);
	int peek(int index);
	bool isEmpty(int index);
	void print(int index);

private:
	const static int stackSize = 9;
	int data[stackSize];
	int top[stackSize/3];
	int nextIndex[stackSize];
	int nextAvailable;

};

#endif