#include "StackNode.h"
#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;

Queue::Queue() {
	front = NULL;
	back = NULL;
	current_size = 0;
}

bool Queue::isEmpty() const {
	return (front == NULL);
}

int Queue::size() const {
	return current_size;
}

int Queue::peek() const {
	if(front == NULL) {
		cout << "Nothing in Front; Empty Queue" << endl;
		return 404;
	} else {
		return front->getdata();
	}
}

void Queue::push(int value) {
	StackNode* newFront = new StackNode(value);
	StackNode* newBack = new StackNode(value);
	if(front == NULL) {
		front = newFront;
		back = newFront;
	} else {
		back->setnext(newBack);
		back = newBack;
	}
	current_size++;
}

int Queue::pop() {
	if(front == NULL) {
		cout << "Nothing to pop" << endl;
		return 404;
	} else {
		int temp = front->getdata();
		if(front == back) {
			front = NULL;
			back = NULL;
		} else {
			front = front->getnext();
		}
		current_size--;
		return temp;
	}
}
