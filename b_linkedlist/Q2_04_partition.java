/*

	Partition: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.
				If x is contained within the list, the values of x only need to be after the elements less than x. The partition element x can appear anywhere in the
				"right partition"; it does not need to appear between the left and right partitions.

	Conceptual Solutions:
		$ have a reference to the first node on the linked list
		$ iterate through the linked list
			$ find x
			$ from x, start looking for elements that are smaller
				$ when found, prev.next = current.next
				$ current.next = firstnode

*/

package b_linkedlist;
import java.util.*;


public class Q2_04_partition {

	public static ListNode solution(ListNode head, int x) {

		ListNode firstNode = head;
		ListNode previous = null;
		while(head != null) {
			if(head.data != x) { // if x is not found
				previous = head;
				head = head.next;
			} else { // if x is found
				while(head != null) {
					if(head.data < x) {
						previous.next = head.next;
						head.next = firstNode;
						firstNode = head;
						head = previous.next;
					} else {
						previous = head;
						head = head.next;
					}
				}
			}

		}	

		return firstNode;
	}

	public static ListNode solutionB(ListNode node, int x) {
		
		ListNode head = node;
		ListNode tail = node;

		while(node != null) {
			ListNode next = node.next;
			if(node.data < x) {
				node.next = head;
				head = node;
			} else {
				tail.next = node;
				tail = node;
			}
			node = next;
		}
		tail.next = null;
		return head;
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
		// printListNode(solution(a, 5));

		printListNode(a);
		a = solutionB(a, 5);
		printListNode(a);

	}
}