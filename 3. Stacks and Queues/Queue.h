#include "StackNode.h"
#ifndef QUEUE_H
#define QUEUE_H

class Queue {

public:
	Queue();
	bool isEmpty() const;
	int size() const;
	int peek() const; //front peek
	void push(int value);
	int pop();

private:
	StackNode* front;
	StackNode* back;
	unsigned current_size;
};

#endif