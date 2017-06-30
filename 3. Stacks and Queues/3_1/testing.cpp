#include "FixedStack.h"
#include "DynamicStack.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	DynamicStack first;
	first.push(0,1);
	first.push(0,1);
	first.push(0,1);
	first.push(0,1);
	first.push(0,2); //
	first.push(1,2);
	first.push(1,2);
	first.push(1,2);
	first.push(1,3); // 
	first.push(2,1); 

	first.print(0);
	first.print(1);
	first.print(2);

	first.pop(0);
	first.pop(1);
	cout << first.peek(0) << endl;
	cout << first.peek(1) << endl;
	cout << first.isEmpty(0) << endl;
	cout << first.isEmpty(1) << endl;
	first.print(0);
	first.print(1);
	first.print(2);

	return 0;
}