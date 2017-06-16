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

		int size();
		
		void print();
	private:
		Node* head;
		Node* tail;
		int count;
};

#endif