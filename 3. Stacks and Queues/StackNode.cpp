#include "StackNode.h"
#include <iostream>


StackNode::StackNode(int value) {
	data = value;
	next = NULL;
}

void StackNode::setdata(int value) {
	data = value;
}

void StackNode::setnext(StackNode* newnode) {
	next = newnode;
}

int StackNode::getdata() const {
	return data;
}

StackNode* StackNode::getnext() const {
	return next;
}	
