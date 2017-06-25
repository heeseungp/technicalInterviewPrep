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

	Node newNode(10);

	first.addNodetoTail(&newNode);

	second.addtoTail(1);
	second.addNodetoTail(&newNode);


	first.print();
	second.print();

	cout << intersection(first, second)->get_data()<< endl;


	return 0;
} 	