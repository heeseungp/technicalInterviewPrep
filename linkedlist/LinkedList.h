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
	private:
		Node* head;
		Node* tail;
		int count;
};

#endif