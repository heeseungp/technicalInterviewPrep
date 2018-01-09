#include "Node.h"
#include <iostream>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::list;
using std::string;

int main() {
	Node<int> hi(100, "first");
	hi.getAdjacency();

	return 0;
}