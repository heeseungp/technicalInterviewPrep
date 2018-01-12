/*

	isUnique: Implement an algorithm to determine if a string has all unique characters.
				What if you cannot use additional data structures?

	
	Conceptual Explanation:
		First Solution: (Using HashTable)
			$ Iterate through the entire string, 
			$ for each character, check if it exist inside a HashTable,
				if it exists : the string is not unique
				if it does not exist: append this char in HashTable
			$ all chars are unique, therefore, return true
		
		Second Solution: (Using static array)
			$ Iterate through the entire string,
			$ for each character, convert the the char to ASCII code
				$ check if a[ASCII code] is true
					if true : the string is not unique
					if false : make a[ASCII code] true
			$ all chars are unique, therefore, return true

*/

import java.util.*;			

public class Q1_01_isUnique {

	public static boolean firstSolution(String input) {
		
		if(input.length() > 128)
			return false;
		
		Hashtable<Character, Integer> lookup = new Hashtable<Character, Integer>(); // create a hashtable
		for(int i=0; i<input.length(); i++) {
			if(lookup.containsKey(input.charAt(i))) 
				return false;
			lookup.put(input.charAt(i), 0);
		}
		return true;
	}

	public static boolean secondSolution(String input) {

		// Assuming it is ASCII 128 possible characters = 7 bits
		boolean lookup[] = new boolean[128];
		for(int i=0; i<input.length(); i++) {
			int ascii = (int) input.charAt(i);
			if(lookup[ascii]) 
				return false;
			else 
				lookup[ascii] = true;
		}
		return true;
	}
 
	public static void main(String[] args) {

		String[] testset = new String[3];
		testset[0] = "hello";
		testset[1] = "abcde";
		testset[2] = "bye";

		for(int i=0; i<testset.length; i++) {
			System.out.println(testset[i] + ": " + firstSolution(testset[i]));			
		}


		for(int i=0; i<testset.length; i++) {
			System.out.println(testset[i] + ": " + secondSolution(testset[i]));			
		}

	}
}