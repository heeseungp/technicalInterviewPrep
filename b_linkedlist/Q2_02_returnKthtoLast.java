/*

	Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

	Conceptual Solution:
		1. Size: If the size of the linked list is given, you can size - k to go to the kth to last element of a singly linked list.
		2. No size: Use recursion. Recurse through the end of the linked list. When null is found, then s


*/


package b_linkedlist;
import java.util.*;

public class Q2_02_returnKthtoLast {

	public static int solution(ListNode head, int k) {

		if(head == null) {
			return 0;
		}
		int index = solution(head.next, k) + 1;
		if(index == k) {
			System.out.println("The value of the node in " + k + "th " + "is " + head.data);
		}
		return index;
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
		e.next = f; 
		f.next = g;
		g.next = h;
		h.next = i;
		i.next = j;
		j.next = k; 

		printListNode(a);
		solution(a, 1);
		solution(a, 2);
		solution(a, 3);
		solution(a, 4);

	}
}		