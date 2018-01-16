/*

	Sum Lists: You have two numbers represented by a linked list, where each node contains a single 
				digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list.
				Write a function taht adds the two numbers and returns the sum as a linked list.
	
	Follow Up: Suppose the digits are stored in forward order. Repeat the above problem.


	Conceptual Solution:
		First question:
			Linked List to int by using x10 every node we encounter
			First start with power 0 and work your way up.
			For example: 
				3 -> 2 -> 1 is a representation of int 123
				3 * 10^0 + 2 * 10^1 + 1 * 10^2 = 123

			Add two int together, then convert it back to linked list using modulo operation

			For example:
				int 123 ; 3 -> 2 -> 1
				
				123%10 = 3 // head of linked list
				123/10 = 12 // remainder 

		Second question:
			Maybe use recursion



*/