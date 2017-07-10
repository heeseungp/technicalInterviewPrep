#include "Stack.h"
#include "StackNode.h"
#include "MyQueue.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	MyQueue first;
	cout << "Is it empty?: " << first.isEmpty() << endl;
	first.push(1);
	first.push(2);
	first.push(3);
	first.push(4);
	first.push(5);
	cout << "Is it empty?: " << first.isEmpty() << endl;
	cout << "Peeking: " << first.peek() << endl;
	cout << "Popping: " << first.pop() << endl;
	cout << "Popping: " << first.pop() << endl;
	cout << "Popping: " << first.pop() << endl;
	cout << "Peeking: " << first.peek() << endl;


	return 0;
}