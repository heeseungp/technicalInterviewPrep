#include "StackNode.h"
#include "Stack.h"
#include "SetofStacks.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

SetofStacks::SetofStacks() {
	topIndex = 0;
}

int SetofStacks::pop() {
	if(stackList.empty()) {
		return 404;
	} else {
		int result = stackList[topIndex].pop();
		if(stackList[topIndex].isEmpty()) {
			if(topIndex > 0) {
				topIndex--;
			}
		}
		return result;
	}
}

// int SetofStacks::popAt(int index) const {
// 	if(topIndex < index) {
// 		return 404;
// 	} else {
// 		stackList[index].pop();
// 	}
// }

void SetofStacks::push(int value) {
	Stack newNode;
	newNode.push(value);
	if(stackList.empty()) {
		stackList.push_back(newNode);
		topIndex++;
	} else {
		if(stackList[topIndex].getSize() == sizePerStack) {
			stackList[++topIndex].push(value);
		} else {
			stackList[topIndex].push(value);
		}
	}
}

int SetofStacks::peek() const {
	return stackList.empty() ? 404 : stackList[topIndex].peek();
}

bool SetofStacks::isEmpty() const {
	return stackList.empty() ? 0 : stackList[topIndex].isEmpty();	
}

void SetofStacks::print() {
	if(stackList.empty()) {
		cout << "Stack is Empty; Nothing to Print" << endl;
	} else {
		if(stackList[topIndex].isEmpty()) {
			cout << "Stack is Empty: Nothing to Print" << endl;
		} else {
			for(int i=topIndex; i>=0; i--) {
				stackList[i].print();
				cout << "->";
			}
			cout << endl;
		}
	}
}