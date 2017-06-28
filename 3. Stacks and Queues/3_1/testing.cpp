#include "FixedStack.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	FixedStack first;
	first.push(0,1);
	first.push(0,2);
	first.push(0,3);
	first.push(0,1);
	first.peek(0);
	first.pop(0);
	first.isEmpty(0);
	first.print(0);
	

	return 0;
}