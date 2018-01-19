package c_stackqueue;

/*

	Interface of Queue:
	add(item): Add an item to the end of the list
	remove(): Remove the first item in the list
	peek(): Return the top of the queue
	isEmpty(): Return true if and only if the queue is empty`


*/

public class MyQueue {

	private static class QueueNode {
		int data;
		QueueNode next;

		public QueueNode(int item) {
			this.data = item;
		}
	}

	private QueueNode front;
	private QueueNode last;

	public void add(int item) {
		QueueNode newNode = new QueueNode(item);
		if(this.isEmpty()) {
			front = newNode;
			end = front;
		} else {
			last.next = newNode;
			last = last.next;
		}
	}

	public int remove() {
		if(front==null) throw new NoSuchElementException();
		int removingNode = front.data;
		front = front.next;
		if(first==null) last = null;
		return removingNode;
	}

	public int peek() {
		if(front==null) throw new NoSuchElementException();
		return front.data;
	}

	public boolean isEmpty() {
		return front==null;
	}
}