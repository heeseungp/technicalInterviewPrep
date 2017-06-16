/*
Created By Joseph Park on 06/12/17

Remove Dups: Write code to remove duplicates from an unsorted linked list.
Follow Up: How would you solve this problem if a temporary buffer is not allowed

Explanation:
There are numerous ways of solving this problem. One way I can instinctly think of is using hash table to store the frequency of unique node values. For example, if we are given the linked list 1->2->1->2->4->6, our hash table will have 1 -> 2, 2 -> 2, 4 -> 1, 6 -> 1 (left represents the unique node and right represents the number of times that unique appeared in the entire linkedlist. After doing this, we can walk through the linkedlist again and delete the duplicates (do value-- everytime you remove the node)

Since the followup question asks to solve this problem without a temporary buffer, I would just take a brute force approach. We will have two pointers, one pointer will point to one particular node and the other pointer will point to every other nodes to check for duplicates. If duplicates are found, remove the node.

The time complexity of this algorithm is O(n^2) because each node in linkedlist will have to iterate all other nodes.
 */


#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {

	//simple testing
	LinkedList hi;
	hi.addtoTail(2);
	hi.print();
	cout << hi.search(2) << endl;

	return 0;
}