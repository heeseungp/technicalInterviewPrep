#include "StackNode.h"
#include "Stack.h"
#include "MinStack.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {	

	MinStack first;
	first.push(1);
	first.push(2);
	first.push(3);
	first.push(5);
	first.push(1);
	first.push(0);

	first.print();
	cout << first.getMin() << endl;

	first.pop();

	first.print();
	cout << first.getMin() << endl;

	return 0;
}