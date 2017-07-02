#include "StackNode.h"
#include "Stack.h"
#include "MinStack.h"
#include "SetofStacks.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {	

	SetofStacks hi;
	// hi.push(1);
	// hi.push(2);
	// hi.push(3);
	// cout << "peeking: " << hi.peek() << endl;
	// cout << "is it empty?: "<< hi.isEmpty() << endl << endl;

	// hi.push(6);
	// cout << "peeking: " << hi.peek() << endl;

	// hi.pop();
	// cout <<  "peeking: " << hi.peek() << endl;

	hi.push(1);
	hi.push(2);
	hi.push(3);
	hi.push(4);
	hi.push(5);
	hi.push(6);
	hi.push(7);
	hi.push(8);
	
	

	hi.print();


	return 0;
}