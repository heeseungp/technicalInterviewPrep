/*

	Delete Middle Node: Implement an algorithm to delete a node in the middle 
						(i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given
						only access to that node.

	Conceptual Solution:
		Copy attributes or node as a whole to the given node.
		

*/


package b_linkedlist;
import java.util.*;

public class Q2_03_deleteMiddleNode {
		
	public static void solution(ListNode middle) {
		if(middle != null || middle.next != null) {
			middle.data = middle.next.data;
			middle.next = middle.next.next;
		}
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
		solution(f);
		printListNode(a);

	}	
}