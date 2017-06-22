#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

// Sum Lists: Write a function that adds the two numbers and returns the sum as a linked list	
LinkedList iter_sumlists(LinkedList* first, LinkedList* second) {
	//iterative version
	LinkedList resultList;
	Node* first_temp = first->get_head_node();
	Node* second_temp = second->get_head_node();
	int result = 0;
	int carry = 0;
	while(first_temp != NULL && second_temp != NULL) {
		result = carry;
		if(first_temp != NULL) {
			result += first_temp->get_data();
			first_temp = first_temp->nextNode();			
		} 
		if(second_temp != NULL) {
			result += second_temp->get_data();
			second_temp = second_temp->nextNode();
		}
		carry = result / 10;
		result = result % 10;
		resultList.addtoTail(result);
		result = 0;
	}
	return resultList;
}
// Sum Lists Follow Up
LinkedList sumlists(LinkedList* first, LinkedList* second) {
	
}

int main() {

	LinkedList first;
	LinkedList second;

	first.addtoTail(7);	
	first.addtoTail(1);
	first.addtoTail(6);
	second.addtoTail(5);	
	second.addtoTail(9);
	second.addtoTail(2);

	first.print();
	second.print();


	sumlists(&first, &second).print();


	return 0;
} 