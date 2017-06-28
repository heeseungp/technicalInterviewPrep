#include "FixedStack.h"
#include <iostream>
using std::cout;
using std::endl;


FixedStack::FixedStack() {
	for(int i=0; i<sizeof(data)/4; i++) {
		data[i] = -1;
	}
	for(int i=0; i<sizeof(size)/4; i++) {
		size[i] = 0;
	}
}

int FixedStack::pop(int index) {
	if(index > 3 || index < 0) {
		cout << "Invalid index entry" << endl;
		return 404;
	} else if(size[index] < 0) {
		cout << "Empty Stack: Nothing to Pop." << endl;
		return 404;
	} else {
		int pointer = numStack * index;
		pointer += size[index];
		size[index]--;
		return pointer;
	}
}

void FixedStack::push(int index, int value) {
	if(index > 3 || index < 0) {
		cout << "Invalid index entry" << endl;
	} else if(size[index] > 2) {
		cout << "Full Stack: Cannot Insert." << endl;		
	} else {
		int pointer = numStack * index + size[index] + 1;
		data[pointer] = value;
		size[index]++;
	}
}

int FixedStack::peek(int index) {
	if(index > 3 || index < 0) {
		cout << "Invalid index entry" << endl;
		return 404;
	} else {
		return data[numStack * index + size[index]];
	}
}

bool FixedStack::isEmpty(int index) {
	if(index > 3 || index < 0) {
		cout << "Invalid index entry" << endl;
		return 0;
	} else if(size[index] < 1) {
		return 0;
	} else {
		return 1;
	}
}

void FixedStack::print(int index) {
	if(index > 3 || index < 0) {
		cout << "Invalid index entry" << endl;
	} else {
		if(size[index] == 0) {
			cout << "Empty Stack" << endl;
		} else {
			int pointer = numStack * index;
			cout << "From Bottom to Top" << endl;
			for(int i=0; i<size[index]; i++) {
				cout << data[pointer + i];
				if(i+1 < size[index]) {
					cout << "->";
				}
			}
			cout << endl;
		}
	}
}

