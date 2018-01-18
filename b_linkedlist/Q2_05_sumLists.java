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


package b_linkedlist;
import java.util.*;


public class Q2_05_sumLists {


	public static ListNode questionA(ListNode first, ListNode second) {

		int result = convertToIntA(first) + convertToIntA(second);
		// System.out.println(result);
		ListNode output = new ListNode();
		ListNode solution = output;
		while(result > 0) {
			int onedigit = result%10;
			result /= 10;
			solution.next = new ListNode(onedigit);
			solution = solution.next;
		}
		return output.next;
	}

	// under construction
	public static int questionB(ListNode first, ListNode second) {

		int result = convertToIntB(first) + convertToIntB(second);
		return result;
	}

	public static int convertToIntA(ListNode head) {

		int result = 0;
		int power = 0;
		while(head != null) {
			result += head.data * Math.pow(10, power++);
			head = head.next;
		}

		return result;
	}

	public static int convertToIntB(ListNode head) {

		int result = 0;
		while(head != null) {
			result *= 10;
			result += head.data;
			head = head.next;
		}

		return result;
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

	public static void main(String[] args){

		ListNode a = new ListNode(9);
		ListNode b = new ListNode(2);
		ListNode c = new ListNode(3);
		
		ListNode d = new ListNode(1);
		ListNode e = new ListNode(5);
		ListNode f = new ListNode(6);
		ListNode g = new ListNode(1);

		a.next = b;
		b.next = c;

		d.next = e;
		e.next = f; 
		f.next = g;

		printListNode(a);
		printListNode(d);

		// printListNode(questionA(a, d));
		// printListNode(questionB(a, d));



	}
}