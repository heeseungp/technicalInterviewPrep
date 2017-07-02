#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;

Stack::Stack() {
	top = NULL;
	size = 0;
}

int Stack::pop() {
	if(top == NULL) {
		// cout << "Not found" << endl;
		return 404;
	} else {
		int result = top->getdata();
		top = top->getnext();
		size--;
		return result;
	}
}

void Stack::push(int value) {
	StackNode* newnode = new StackNode(value);
	newnode->setnext(top);
	top = newnode;
	size++;
}

int Stack::peek() const {
	if(top == NULL) {
		// cout << "Nothing on Stack" << endl;
		return 404;
	} else {
		return top->getdata();
	}
}

bool Stack::isEmpty() const {
	if(top == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void Stack::print() {
	if(top == NULL) {
		cout << "Nothing on Stack" << endl;
	} else {
		StackNode* temp = top;
		while(temp != NULL) {
			cout << temp->getdata();
			if(temp->getnext() != NULL) {
				cout << "->";
			}
			temp = temp->getnext();
		} 
	}
}


int Stack::getSize() const {
	return size;
}

StackNode* Stack::getTop() const {
	return top;
}