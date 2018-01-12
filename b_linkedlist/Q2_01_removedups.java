/*

	Remove Dups: Write code to remove duplicates from an unsorted linked list
			Follow up: How would you solve this problem if a temporary buffer is not allowed?
	
	Conceptual Solution:
		Buffer:
			Using hashset, we can check if we have seen the element in the past. If an element exists already 
			inside the hashset, we have to skip the node.

		No Buffer:
			Using two pointers (one for current, one for runner), we can keep comparing those two values.
			If the values are equivalent, we have to skip the node.

*/
package b_linkedlist;
import java.util.*;

public class Q2_01_removedups {

	public static void buffer(ListNode head) {
		HashSet<Integer> lookup = new HashSet<Integer>();
		ListNode previous = null;
		while(head != null) {
			if(lookup.contains(head.data)) {
				previous.next = head.next;
			} else {
				lookup.add(head.data);
				previous = head;
			}
			head = head.next;
		}
	}


	public static void nobuffer(ListNode head) {

		// runner needs previous (-1)
		// new runner  = + 1 from current
		// current updates when runner is null

		// while(head != null) {
		// 	ListNode previous = head;
		// 	ListNode runner = head.next;
		// 	while(runner != null) {
		// 		if(head.data == runner.data) {
		// 			previous.next = runner.next;
		// 		} else {
		// 			previous = previous.next;
		// 		}
		// 		runner = runner.next;
		// 	}
		// 	head = head.next;
		// } 

		while(head != null) {
			ListNode runner = head;
			while(runner.next != null) {
				if(head.data == runner.next.data) {
					runner.next = runner.next.next;
				} else {
					runner = runner.next;
				}
			}
			head = head.next;
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

		// printListNode(a);	
		// buffer(a);
		printListNode(a);
		nobuffer(a);
		printListNode(a);

	}
}