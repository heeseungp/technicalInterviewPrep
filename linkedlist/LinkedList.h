#include "Node.h"
#ifndef LINKEDLISTTT_H
#define LINKEDLISTTT_H

class LinkedList {
	public:
		LinkedList();
		LinkedList(int data);
		void addtoTail(int value);
		void addtoHead(int value);
		void addAt(int index, int value); //index starts from zero
		void removeTail();
		void removeHead();
		void removeAt(int index); //index starts from zero
		bool search(int value);
		int size() const;
		void print();

		int get_head_data() const;
		int get_tail_data() const;

		Node* get_head_node() const;
		Node* get_tail_node() const;
		
		// Remove Duplicates: Write code to remove duplicates from an unsorted linked list
		void removeDups();

		// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
		void lastKth(int k);
		// Recursive solution
		int recur_lastKth(Node* node, int k);
		// Iterative solution
		void iter_lastKth(int k);

		// Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node
		void deleteMiddle(Node* willDelete);

		// Partition: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater or equal to x.
		void partition(int value);

		// Palindrome: Implement a function to check if a linked list is a palindrome.
		bool palindrome();


	private:
		Node* head;
		Node* tail;
		int count;
};

#endif