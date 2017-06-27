#ifndef STACKNODE_H
#define STACKNODE_H

class StackNode {

public:
	StackNode(int value);
	void setdata(int value);
	void setnext(StackNode* newnode); 
	int getdata() const; 
	StackNode* getnext() const; 

private:	
	int data;
	StackNode* next;

};

#endif