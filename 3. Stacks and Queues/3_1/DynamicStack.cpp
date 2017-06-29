#include "DynamicStack.h"
#include <iostream>
using std::cout;
using std::endl;

DynamicStack::DynamicStack() {
	for(int i=0; i<sizeof(data)/4; i++) {
		data[i] = -1;
	}	
	for(int j=0; j<sizeof(top)/4; j++) {
		size[j] = -1;
	}
	for(int k=0; k-1<sizeof(nextIndex)/4; k++) {
		nextIndex[k] = k+1;
	}
	nextIndex[(sizeof(nextIndex)/4)-1] = -1;
	nextAvailable = 0;
}

int DynamicStack::pop(int index) {
	if(top[index] == -1) {
		cout << "Cannot pop because stack is empty" << endl;
		return 404;
	} else {
		int result = data[top[index]];
		data[top[index]] = -1;
		top[index] = nextIndex[top[index]];
		int prevTop = top[index];
		nextIndex[top[index]] = nextAvailable;
		nextAvailable = prevTop;
		return result;
	}
}

void DynamicStack::push(int index, int value) {
	if(nextAvailable == -1) {
		cout << "Stack is Full: Unable to Push." << endl;
	} else {
		data[nextAvailable] = value;
		int previousPrevIndex = prevIndex[nextAvailable];
		prevIndex[nextAvailable] = top[index];
		top[index] = nextAvailable;
		nextAvailable = previousPrevIndex;
	}
}

int DynamicStack::peek(int index) {
	if(top[index] == -1) {
		cout << "Cannot peek because stack is empty" << endl;
		return 404;
	} else {
		return top[index];
	}
}

bool DynamicStack::isEmpty(int index) {
	return (top[index] == -1) ? 1 : 0
}

void DynamicStack::print(int index) {
	if(top[index] == -1) {
		cout << "Cannot print because stack is empty" << endl;
	} else {
		int prev = top[index];
		while(prev != -1) {
			cout << data[prev];

			prev = nextIndex[prev];
		}
		// working on it
	}
}