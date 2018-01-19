package c_stackqueue;

/*
	
	Interface of Stack
	pop(): Remove the top item from the stack
	push(item): Add an item to the top of the stack
	peek(): return the top of the stack
	isEmpty(): return true if and only if the stack is empty
	

*/

public class MyStack {

	private static class StackNode {
		int data;
		StackNode next;

		public StackNode(int data) {
			this.data = data;
		}
	}

	private StackNode top;

	public int pop() {
		if(top == null) throw new EmptyStackException();
		int topval = top.data;
		top = top.next;
		return topval;
	}

	public void push(int data) {
		StackNode newNode = new StackNode(data);
		newNode.next = top;
		top = newNode;
	}

	public int peek() {
		if(top == null) throw new EmptyStackException();
		return top.data;
	}

	public boolean isEmpty() {
		return top==null;
	}
}