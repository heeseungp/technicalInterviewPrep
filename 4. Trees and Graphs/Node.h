#include <iostream>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::list;
using std::string;

#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	Node(T newData, string newName);
	T getdata() const;
	string getname() const;
	void getAdjacency();
private:
	T data;
	string name;
	list<Node<T>*> adjacentList;
};

template <class T>
Node<T>::Node(T newData, string newName) {
	this->data = newData;
	this->name = newName;
	adjacentList.push_back(1);
	adjacentList.push_back(2);
	adjacentList.push_back(3);
}

template <class T>
T Node<T>::getdata() const {
	return this->data;
}

template <class T>
string Node<T>::getname() const {
	return this->name;
}

template <class T>
void Node<T>::getAdjacency() {
	for(list<Node<T>*>::iterator it = this->adjacentList.begin(); it != this->adjacentList.end(); it++) {
		cout << *it << endl;
	}
}


#endif