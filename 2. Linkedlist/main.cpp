#include "Node.h"
#include "LinkedList.h"
#include "answer.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

// problem 2.5
// Sum Lists: Write a function that adds the two numbers and returns the sum as a linked list	
LinkedList iter_sumlists(LinkedList* first, LinkedList* second);
// Sum Lists Follow Up
LinkedList sumlists(Node* first, Node* second);

// problem 2.7
Node* intersection(LinkedList first, LinkedList second);	

int main() {

	LinkedList first;
	LinkedList second;

	Node firstnode(3);
	Node secondnode(4);
	Node thirdnode(5);

	firstnode.set_next(&secondnode);
	secondnode.set_next(&thirdnode);
	thirdnode.set_next(&firstnode);

	first.addtoTail(1);
	first.addtoTail(2);
	first.addNodetoTail(&firstnode);

	// first.print();
	// second.print();

	cout << first.loopDetection()->get_data() << endl;

	return 0;
} 	