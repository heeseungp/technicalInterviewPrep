#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	LinkedList hi;
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(6);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	hi.addtoTail(5);
	
	hi.removeDups();

	cout << "Size is: " << hi.size() << endl;
	hi.print();

	return 0;
}