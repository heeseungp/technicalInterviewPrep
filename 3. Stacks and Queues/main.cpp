#include "Stack.h"
#include "StackNode.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	Stack mystack;

	mystack.push(0);
	mystack.push(1);
	mystack.push(2);
	cout << "Current stack: ";
	mystack.print();

	//popping
	cout << "POPPING" << endl;
	mystack.pop();
	mystack.print();

	//peeking 
	cout << "The top of the stack: ";
	cout << mystack.peek() << endl;

	//isempty checking 
	cout << "Is it empty?: ";
	cout << mystack.isEmpty() << endl;

	//printing
	cout << "Printing once again" << endl;
	mystack.print();
	return 0;
}