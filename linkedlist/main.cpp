#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <math.h>
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
void sumlists(Node* first, Node* second) {
	// shorter way is to just save it to int and make a new linkedlist
	Node* firstTemp = first;
	Node* secondTemp = second;
	int firstnum, secondnum = 0;
	int count = 0;

	if(firstTemp != NULL) {
		firstnum += firstTemp->get_data() * pow(10, count);
		firstTemp = firstTemp->nextNode();
		count++;
	}
	count = 0;
	if(secondTemp != NULL) {
		secondnum += secondTemp->get_data() * pow(10, count);
		secondTemp = secondTemp->nextNode();
		count++;
	}
	// cout << secondnum << endl;

	int first_value, second_value, remaining = 0;
	while(firstnum > 0) {
		remaining = firstnum % 10;
		first_value = first_value*10 + remaining;
		firstnum /= 10;
	}
	remaining = 0;
	while(secondnum > 0) {
		remaining = secondnum % 10;
		second_value = second_value*10 + remaining;
		secondnum /= 10;
	}
	// finalvalue;
	firstnum = firstnum + secondnum;
	// cout << firstnum << endl;
	LinkedList final; 
	while(firstnum != 0) {
		final.addtoTail(firstnum%10);
		firstnum = firstnum/10;
	}

	
}

int main() {

	LinkedList first;
	LinkedList second;

	first.addtoTail(1);	
	first.addtoTail(2);
	first.addtoTail(3);
	second.addtoTail(4);	
	second.addtoTail(5);
	second.addtoTail(6);


	first.print();
	second.print();

	sumlists(first.get_head_node(), second.get_head_node());


	return 0;
} 