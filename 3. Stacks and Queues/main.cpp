#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	Queue hi;
	cout << "Queue Empty?: " << hi.isEmpty() << endl;
	cout << "Queue Size: " << hi.size() << endl;
	cout << "Queue Peek: " << hi.peek() << endl;

	hi.push(1);
	cout << "Queue Empty?: " << hi.isEmpty() << endl;
	cout << "Queue Size: " << hi.size() << endl;
	cout << "Queue Peek: " << hi.peek() << endl;

	hi.push(2);	
	cout << "Queue Empty?: " << hi.isEmpty() << endl;
	cout << "Queue Size: " << hi.size() << endl;
	cout << "Queue Peek: " << hi.peek() << endl;

	hi.push(3);
	cout << "Queue Empty?: " << hi.isEmpty() << endl;
	cout << "Queue Size: " << hi.size() << endl;
	cout << "Queue Peek: " << hi.peek() << endl;

	cout << "Queue Popping: " << hi.pop() << endl;
	cout << "Queue Peek: " << hi.peek() << endl;

	
	return 0;
}