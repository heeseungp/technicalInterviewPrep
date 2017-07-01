#include "DynamicStack.h"
#include <iostream>
using std::cout;
using std::endl;

DynamicStack::DynamicStack() {
	for(int i=0; i<sizeof(data)/4; i++) {
		data[i] = -1;
	}	
	for(int j=0; j<sizeof(top)/4; j++) {
		top[j] = -1;
	}
	for(int i=0; i<(sizeof(nextIndex)/4)-1; i++) {
		nextIndex[i] = i+1;
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
		int prevTop = top[index];
		top[index] = nextIndex[top[index]];
		nextIndex[prevTop] = nextAvailable;
		nextAvailable = prevTop;
		return result;
	}
}

void DynamicStack::push(int index, int value) {
	if(nextAvailable == -1) {
		cout << "Stack is Full: Unable to Push." << endl;
	} else {
		data[nextAvailable] = value;
		int previousPrevIndex = nextIndex[nextAvailable];
		nextIndex[nextAvailable] = (top[index] == -1) ? -1 : top[index];
		nextIndex[nextAvailable] = top[index];
		top[index] = nextAvailable;
		nextAvailable = previousPrevIndex;
	}
}

int DynamicStack::peek(int index) {
	if(top[index] == -1) {
		cout << "Cannot peek because stack is empty" << endl;
		return 404;
	} else {
		return data[top[index]];
	}
}

bool DynamicStack::isEmpty(int index) {
	return (top[index] == -1) ? 1 : 0;
}

void DynamicStack::print(int index) {
	if(top[index] == -1) {
		cout << "Cannot print because stack is empty" << endl;
	} else {
		int prev = top[index];
		while(prev != -1) {
			cout << data[prev];
			prev = nextIndex[prev];
			if(prev != -1) {
				cout << "->";
			}
		}
		cout << endl;
	}
}

void DynamicStack::get_nextIndex() {
	cout << "next index" << endl;
	for(int i=0; i<sizeof(nextIndex)/4; i++) {
		cout << nextIndex[i] << ' ' << endl;
	}

	cout << "data" << endl;
	for(int i=0; i<sizeof(data)/4;i++) {
		cout << data[i] << endl;
	}

	cout << "top" << endl;
	for(int i=0; i<sizeof(top)/4; i++) {
		cout << top[i] << endl;
	}
 
}