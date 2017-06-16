#include <iostream>
#include "Node.h"

Node::Node(int d) {
	data = d;
	next = NULL;
}

int Node::get_data() {
	return data;
}

void Node::set_data(int d) {
	data = d;
}

void Node::set_next(Node* newNode) {
	next = newNode;
}

Node* Node::nextNode() {
	return next;
}