/*

	Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

	Definition. 
	Circular linked list: a corrupt linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list

	
	Conceptual Solution:
		Have a slow and fast runner. 
		When the two pointers meet, take the original front node and run it simultaneously with the collided pointer.
		when those two pointers meet, return the node
*/

package b_linkedlist;
import java.util.*;

public class Q2_08_loopDetection {

	public static ListNode loopDetection(ListNode head) {

		if(head == null) {
			return null;
		} 

		ListNode slow = head;
		ListNode fast = head;

		while(slow != null) {
			slow = slow.next;
			fast = fast.next.next;
			if(slow == fast) {
				break;
			}
		}

		while(fast != head) {
			fast = fast.next;
			head = head.next;
		}

		return fast;
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
		ListNode d = new ListNode(4);
		ListNode e = new ListNode(5);
		ListNode f = new ListNode(6);


		a.next = b;
		b.next = c;
		c.next = d;
		d.next = e;
		e.next = f; 
		f.next = c;

		System.out.println("Solution: " + c);
		System.out.println("My solution: " + loopDetection(a));
	}
}
