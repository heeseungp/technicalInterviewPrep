/*

	Palindrome Permutation: Given a string, write a function to check if it's a permutation of a palindrome.
							A palindrome is a word or phrase that is the same forwards and backwards. 
							A permutation is a rearrangement of letters.
							The palindrome does note need to be limited to just dictionary words.

	Conceptual Solution:
		Each unique char in the string must have a pair, unless the string length is odd.
		For example, 
			aba
		a: 2
		b: 1

		$ Determine if the string's length is even or odd.
		$ if even:
			all unique char should have a matching pair (even count)
		$ if odd:
			all unique char should have a matching pair (even count) except one with odd count.

*/

import java.util.*;

public class Q1_04_palindromePermutation {

	public static boolean solution(String str) {

		boolean[] lookup = new boolean[128];
		boolean odd = false;
		for(int i=0; i<str.length(); i++) {
			int ascii = (int) str.charAt(i);
			if(lookup[ascii]) lookup[ascii] = false;
			else lookup[ascii] = true;
		}		

		if(str.length()%2 == 0) {
			// even number
			for(int i=0; i<lookup.length; i++) {
				if(lookup[i])
					return false;
			}

		} else { 
			// odd number
			for(int i=0; i<lookup.length; i++) {
				if(lookup[i]) {
					if(!odd) {
						odd = true;
					} else return false;
				}
			}
		}

		return true;
	}

	// more optimal answer
	public static boolean solutionB(String str) {
		int[] lookup = new int[128];
		int countodd = 0;
		for(int i=0; i<str.length(); i++) {
			int ascii = (int) str.charAt(i);
			lookup[ascii]++;
			if(lookup[ascii] % 2 == 1) {
				countodd++;
			} else {
				countodd--;
			}
		}

		return countodd <= 1;	
	}


	public static void main(String[] args) {

		String[] testset = new String[3];
		testset[0] = "hello";
		testset[1] = "racecar";
		testset[2] = "tacocat";

		for(int i=0; i<testset.length; i++) {
			System.out.println(testset[i] + ": " + solutionB(testset[i]));
		}

	}
}			