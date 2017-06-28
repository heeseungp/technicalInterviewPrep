#include "FixedStack.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	FixedStack first;
	first.push(0,1);
	first.push(0,2);
	first.push(0,3);
	first.print(0);
	cout << first.isEmpty(0) << endl;
	

	return 0;
}