#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

// problem 2.5
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
LinkedList sumlists(Node* first, Node* second) {
	// shorter way is to just save it to int and make a new linkedlist
	LinkedList final;
	Node* first_temp = first;
	Node* second_temp = second;
		
	if(first != NULL || second != NULL) {
		// converting the linkedlist to integer values
		int first_result = 0;
		int second_result = 0;
		while(first_temp != NULL) {
			first_result = first_result*10 + first_temp->get_data();
			first_temp = first_temp->nextNode();
		}
		while(second_temp != NULL) {
			second_result = second_result*10 + second_temp->get_data();
			second_temp = second_temp->nextNode();
		}
		first_result = first_result + second_result;
		// convert the integer value to linkedlist
		while(first_result > 0) {
			final.addtoHead(first_result%10);
			first_result /= 10;
		}

	} else {
		final.addtoTail(0);
	}

	return final;
}

// problem 2.7
// Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note: intersecting node is not by value, but it is by reference.

Node* intersection(LinkedList first, LinkedList second) {
	/*
	1. to check if the linkedlists intersect, we need to check if the tail of the linkedlists are the same (by reference)
	*/

	if(first.get_tail_node() == second.get_tail_node()) {
		Node* first_temp = first.get_head_node();
		Node* second_temp = second.get_head_node();
		if(first_temp != NULL && second_temp != NULL) {
			int sizeDifference = 0;
			if(first.size() > second.size()) {
				sizeDifference = first.size() - second.size();
				while(first_temp != NULL && sizeDifference > 0) {
					first_temp = first_temp->nextNode();
					sizeDifference--;
				}
			} else if(first.size() < second.size()) {
				sizeDifference = second.size() - first.size();
				while(second_temp != NULL && sizeDifference > 0) {
					second_temp = second_temp->nextNode();
					sizeDifference--;
				} 
			}

			while(true) {
				if(first_temp == second_temp) {
					return first_temp;
				} else {
					first_temp = first_temp->nextNode();
					second_temp = second_temp->nextNode();
				}
			}
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}