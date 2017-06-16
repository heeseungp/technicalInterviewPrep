#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	LinkedList hi;
	hi.addtoTail(5);
	hi.addtoTail(6);
	hi.addtoTail(7);

	hi.iter_lastKth(1);
	
	return 0;
}