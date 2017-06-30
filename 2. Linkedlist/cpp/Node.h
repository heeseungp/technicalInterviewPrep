#ifndef NODE_H
#define NODE_H

class Node {
	public:
		Node(int data);
		int get_data();
		void set_data(int d);
		void set_next(Node* d);
		Node* nextNode();

	private:
		int data;
		Node* next;
};

#endif