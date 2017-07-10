#include "Stack.h"
#include "StackNode.h"
#include "MyQueue.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	Stack hi;
	hi.sortStack();
	hi.push(1);
	hi.push(2);
	hi.push(3);
	hi.push(4);
	hi.push(5);
	hi.print();
	cout << endl;
	hi.sortStack();
	hi.print();
	cout << endl;

	hi.pop();
	hi.print();
	cout << endl;

	hi.sortStack();
	hi.print();
	cout << endl;


	return 0;
}