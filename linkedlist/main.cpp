#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	LinkedList hi;
	hi.addtoTail(1);
	hi.addtoTail(2);
	hi.print();
	hi.partition(5);
	hi.print();


	return 0;
}