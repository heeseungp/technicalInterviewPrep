/*

	Palindrome: Implement a function to check if a linked list is a palindrome.

	Conceptual Solution:
		1. Put it in stack, and compare by popping the stack and iterating forward for linked list.
			The stack only needs to store the half (use the runner's method to get to the half point)
		The time and space complexity are O(n)
		2. Recursion: count the index and pass it to the recursive call 

		1     -     2     -     3     -     2     -     1

		^           ^          				^		    ^
	    1st index   2nd index			    2nd to last	1st to last
*/

package b_linkedlist;
import java.util.*;

public class Q2_06_palindrome {

	public static boolean solutionA(ListNode head) {
		Stack<Integer> container = new Stack<Integer>();
		ListNode runner = head;

		while(runner != null && runner.next != null) {
			container.push(head.data);
			head = head.next;
			runner = runner.next.next;
		}

		// for even and odd
		if(runner != null && runner.next == null ) {
			head = head.next;
		}
		
		while(head != null && !container.empty()) {
			if(container.peek() == head.data) {
				container.pop();
				head = head.next;
			} else {
				return false;
			}
		}

		return container.empty();
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
		ListNode c = new ListNode(2);
		ListNode d = new ListNode(2);

		a.next = b;
		b.next = c;
		c.next = d;

		printListNode(a);
		System.out.println(solutionA(a));

	}
}