#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	count = 0;
}

LinkedList::LinkedList(int d) {
	Node* temp = new Node(d);
	head = temp;
	tail = temp;
	count = 1;
}

void LinkedList::addtoTail(int value) {
	Node* newNode = new Node(value);
	if(head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		tail->set_next(newNode);
		tail = newNode;
	}
	count++;
}

void LinkedList::addtoHead(int value) {
	Node* newNode = new Node(value);
	newNode->set_next(head);
	head = newNode;
	count++;
}

void LinkedList::addAt(int index, int value) {
//index starts from zero
//the index you provide is where your new node will be stored at
	if(index == 0) {
		this->addtoHead(value);
	} else if(count > index){
		Node* temp = head;
		Node* newNode = new Node(value);
		for(int i=0; i<=index; i++) {
			if(i+1 == index) {
				newNode->set_next(temp->nextNode());
				temp->set_next(newNode);
				break;
			}
			temp = temp->nextNode();
		}
		count++;
	} else {
		cout << "Invalid index entry" << endl;
	}
} 

void LinkedList::removeTail() {
	if(count > 0) {
		Node* temp = head;
		for(int i=0; i<count; i++) {
			if(i+1 == count) {
				temp->set_next(NULL);
				tail = temp;
				break;
			}
			temp = temp->nextNode();
		}
		count--;
	} else {
		cout << "Nothing to Remove" << endl;
	}
}
void LinkedList::removeHead() {
	if(count > 0) {
		head = head->nextNode();
		count--;
	} else {
		cout << "Nothing to Remove" << endl;
	}
}

void LinkedList::removeAt(int index) {
//index starts from zero
//remove the node at the given index
	if(count > 0 && index < count) {
		Node* temp = head;
		for(int i=0; i<index; i++) {
			if(i+1 == index) {
				temp->set_next(temp->nextNode()->nextNode());
				break;
			}
			temp = temp->nextNode();
		}
		count--;
	} else {
		cout << "Nothing to Remove OR invalid index" << endl;
	}

} 

bool LinkedList::search(int value) {
	Node* temp = head;
	if(temp == NULL) {
		return false;
	} else {
		for(int i=0; i<count; i++) {
			if(temp->get_data() == value) {
				return true;
			}
			temp = temp->nextNode();
		}
	}
}

int LinkedList::size() {
	return count;
}

void LinkedList::print() {
	Node* temp = head;
	if(count == 0) {
		cout << "Empty" << endl;
	} else {
		for(int i=0;i<count;i++) {
			cout << temp->get_data();
			if(i+1 < count) {
				cout << "->";
				temp = temp->nextNode();	
			}
		}
	}
	cout << endl;
}