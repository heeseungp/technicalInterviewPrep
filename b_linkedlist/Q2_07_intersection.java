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

package b_linkedlist;
import java.util.*;

public class Q2_07_intersection {

	public static ListNode intersection(ListNode first, ListNode second) {

		if(tail(first) != tail(second)) {
			return null;
		}

		int firstSize = sizeofList(first);
		int secondSize = sizeofList(second);

		if(firstSize == 0 || secondSize == 0) {
			return null;
		}

		int steps = firstSize-secondSize;
		if(steps > 0) {
			first = moveForward(first, steps);
		} else if(steps < 0){
			second = moveForward(second,steps);
		}

		// same length
		while(first != second) {
			first = first.next;
			second = second.next;
		}

		return first;
	}

	public static ListNode tail(ListNode head) {
		while(head != null && head.next != null) {
			head = head.next;
		}

		return head;
	}

	public static ListNode moveForward(ListNode head, int count) {
		while(head != null && count > 0) {
			head = head.next;
			count--;
		}
		return head;
	}

	public static int sizeofList(ListNode head) {
		int count = 0;
		while(head != null) {
			count++;
			head = head.next;
		}
		return count;
	}


	public static void printListNode(ListNode head) {
		System.out.println("");
		while(head != null) {
			System.out.print(head.data);
			if(head.next != null) {
				System.out.print(" -> ");
			}
			head = head.next;
		}
		System.out.println("");
		System.out.println("");
	}


	public static void main(String[] args) {
		ListNode a = new ListNode(1);
		ListNode b = new ListNode(2);
		ListNode c = new ListNode(3);
		ListNode d = new ListNode(1);
		ListNode e = new ListNode(5);
		
		ListNode f = new ListNode(6);
		ListNode g = new ListNode(1);
		ListNode h = new ListNode(2);
		ListNode i = new ListNode(3);
		ListNode j = new ListNode(1);
		ListNode k = new ListNode(5);

		a.next = b;
		b.next = c;
		c.next = d;
		d.next = e;

		f.next = g;
		g.next = h;
		h.next = d;

		printListNode(a);
		printListNode(f);

		System.out.println(intersection(a, f));

		System.out.println("The answer (intersection node): " + d);
	}
}