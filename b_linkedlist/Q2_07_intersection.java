/*

	Intersection: Given two (singly) linked lists, determine if the two lists intersect.
				Return the intersecting node. Note that the intersection is defined based on reference, not value.
				That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the
				second linked list, then they are intersecting.

	Conceptual Solution: 
		1. Find the length of the linked list.
		2. Move the longer linked list up to match the starting point 
		3. Iterate through the linked list to find intersecting node.
			If it does not exist, return false
			If found, return the intersecting node

*/