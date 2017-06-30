#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <set>
#include <stack>
using std::set;
using std::stack;
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
	if(head == NULL && tail == NULL) {
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
	if(head == NULL && tail == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->set_next(head);
		head = newNode;
	}
	count++;
}


void LinkedList::addNodetoTail(Node* newNode) {
	if(head != NULL && tail != NULL) {
		tail->set_next(newNode);
		tail = newNode;	
	} else {
		head = newNode;
		tail = newNode;
	}
	count++;
}

void LinkedList::addNodetoHead(Node* newNode) {
	if(head != NULL && tail != NULL) {
		newNode->set_next(head);
		head = newNode;
	} else {
		head = newNode;
		tail = newNode;
	}
	count++;
}

void LinkedList::addAt(int index, int value) {
//index starts from zero
//the index you provide is where your new node will be stored at
	if(index > count) {
		cout << "Invalid index entry" << endl;
	} else {
		if(index == 0) {
			this->addtoHead(value);
		} else if(index == count-1) {
			this->addtoTail(value);
		} else {
			Node* newNode = new Node(value);
			Node* temp = head;
			for(int i=0; i<=index; i++) {
				if(i+1 == index) {
					newNode->set_next(temp->nextNode());
					temp->set_next(newNode);
					break;	
				}
				temp = temp->nextNode();
			}
			count++;
		}
	}
} 

void LinkedList::removeTail() {
	if(head == NULL && tail == NULL) {
		cout << "Nothing to Remove" << endl;
	} else {
		if(head == tail) {
			head = NULL;
			tail = NULL;
		} else {
			Node* temp = head;
			for(int i=0; i<count; i++) {
				if(i+1 == count) {
					temp->set_next(NULL);
					tail = temp;
					break;
				}
				temp = temp->nextNode();
			}
		}
		count--;
	}
}

void LinkedList::removeHead() {	
	if(head == NULL && tail == NULL) {
		cout << "Nothing to Remove" << endl;
	} else {
		if(head == tail) {
			head = NULL;
			tail = NULL;
		} else {
			head = head->nextNode();
		}
		count--;
	}
}

void LinkedList::removeAt(int index) {
//index starts from zero
//remove the node at the given index
	if(head == NULL && tail == NULL) {
		cout << "Nothing to Remove" << endl;
	} else {
		if(index >= count) {
			cout << "Invalid index entry" << endl;
		} else {
			if(index == 0) {
				this->removeHead();
			} else if(index == count-1) {
				this->removeTail();
			} else {
				Node* temp = head;
				for(int i=0; i<=index; i++) {
					if(i+1 == index) {
						temp->set_next(temp->nextNode()->nextNode());
						break;
					}
					temp = temp->nextNode();
				}
				count--;
			}
		}
	}
} 

bool LinkedList::search(int value) {
	Node* temp = head;
	if(head == NULL && tail == NULL) {
		return false;
	} else {
		for(int i=0; i<count; i++) {
			if(temp->get_data() == value) {
				return true;
			}
			temp = temp->nextNode();
		}
		return false;
	}
}

int LinkedList::size() const{
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


int LinkedList::get_head_data() const {
	return head->get_data();
}

int LinkedList::get_tail_data() const {
	return tail->get_data();
}


Node* LinkedList::get_head_node() const {
	return head;
}

Node* LinkedList::get_tail_node() const {
	return tail;
}


//problem 2.1: Remove Duplicate
void LinkedList::removeDups() {
	/*
	Method solved using set
	if(head != NULL) {
		set<int> myset;
		Node* prev = NULL;
		Node* temp = head;
		while(temp != NULL) {
			if(myset.find(temp->get_data()) != myset.end()) {
			// if it is found
				prev->set_next(temp->nextNode());
				count--;
			} else {
			// if it isn't found
				myset.insert(temp->get_data());
				prev = temp;
			}
			temp = temp->nextNode();
		}
	}
	*/

	// method solved using no temporary buffer
	if(head != NULL) {
		Node* current = head;
		Node* runner = head;
		while(current != NULL) {
			while(runner->nextNode() != NULL) {
				if(current->get_data() == runner->nextNode()->get_data()) {
					runner->set_next(runner->nextNode()->nextNode());
					count--;
				} else {
					runner = runner->nextNode();
				}
			}
			current = current->nextNode();
			runner = current;
		}

	}
}

//problem 2.2 Return kth to last
void LinkedList::lastKth(int k) {
// If the size is given (the first last index is 0)
	if(count-1 < k) {
		cout << "Invalid k entry" << endl;
	} else {
		Node* temp = head;
		for(int i=0; i<count; i++) {
			if(i == count-1-k) {
				cout << "Kth to last: " << temp->get_data() << endl;
				break;
			}
			temp = temp->nextNode();
		}
	}

}

// problem 2.2 Return kth to last (recursive solution)
int LinkedList::recur_lastKth(Node* node, int k) {
	if(node == NULL) {
		return 0;
	}

	int index = this->recur_lastKth(node->nextNode(), k) + 1;
	if(index-1 == k) {
		cout << "Kth to Last: " << node->get_data() << endl;
	}
	return index;
}

// problem 2.2 Return kth to last (iteratively)
void LinkedList::iter_lastKth(int k) {
	if(count < k-1) {
		cout << "Invalid k" << endl;
	} else {
		Node* current = head;
		Node* runner = head;
		for(int i=0; i<k; i++) {
			runner = runner->nextNode();
		}
		while(runner->nextNode() != NULL) {
			current = current->nextNode();
			runner = runner->nextNode();
		}
		cout << "Kth to last: " << current->get_data() << endl;
	}
}

// problem 2.3 Delete Middle Node
void LinkedList::deleteMiddle(Node* willDelete) {
	if(willDelete == head || willDelete == tail) {
		cout << "Not a Middle Node" << endl;
	} else {
		Node* temp = willDelete->nextNode();
		willDelete->set_next(temp->nextNode());
		willDelete->set_data(temp->get_data());
	}
}

// problem 2.4 Partition
void LinkedList::partition(int value) {
	Node* prev = head;
	Node* next = prev->nextNode();

	while(next != NULL) {
		if(next->get_data() < value) {
			prev->set_next(next->nextNode());
			next->set_next(head);
			head = next;
			next = prev->nextNode();
		} else {
			prev = next;
			next = next->nextNode();
		}
	}
}


// problem 2.6 Palindrome
bool LinkedList::palindrome() {
	Node* current = head;
	Node* runner = head;
	stack<int> mystack;

	while(runner != NULL && runner->nextNode() != NULL) {
		mystack.push(current->get_data());
		current = current->nextNode();
		runner = runner->nextNode()->nextNode();
	}
	if(runner != NULL) {
		current = current->nextNode();
	}
	while(current != NULL) {
		if(!mystack.empty() && current->get_data() == mystack.top()) {
			mystack.pop();
			current = current->nextNode();
		} else {
			return false;
		}
	}
	return true;
}

// problem 2.8 Loop Detection
Node* LinkedList::loopDetection() {
	Node* temp = new Node(404);
	if(head != NULL) {
		return temp;
	} else {
		Node* current = head;
		Node* runner = head;
		while(current != NULL && runner != NULL && runner->nextNode() != NULL) {
			if(current == runner) {
				current = head;
				while(current != runner) {
					current = current->nextNode();
					runner = runner->nextNode();
				}
				return current;
			}
			current = current->nextNode();
			runner = runner->nextNode()->nextNode();
		}
		return temp;
	}
}