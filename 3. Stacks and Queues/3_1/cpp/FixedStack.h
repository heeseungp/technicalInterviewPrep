#ifndef FIXEDSTACK_H
#define FIXEDSTACK_H

class FixedStack {
//we assume that if a value in stack has -1, that means it is empty

public:
	FixedStack();
	int pop(int index);
	void push(int index, int value);
	int peek(int index);
	bool isEmpty(int index);
	void print(int index);

private:
	const static int numStack = 3;
	int data[9];
	int size[3];
};

#endif