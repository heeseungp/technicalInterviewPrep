/*

	Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

	Conceptual Solutions:
		Permutation means that the string can written in any order. 
		For example, the word "hello" can be written "ohell".
		The order in which the characters are used do not violate the permutation property.
		
		First solution: 
			$ First check if two strings have the same length
			$ Sort two strings using any sorting algorithms (preferrably Timsort or Cubesort [best time complexity is big o of n])
			$ Compare sorted strings index by index.
				$ if not same : return false
				$ else : loop
			$ return true

		Second solution: 
			$ Use ASCII lookup to store the counter of each unique char
			$ All values inside the ASCII lookup should be zero
*/


import java.util.*;

public class Q1_02_checkPermutation {

	public static boolean firstSolution(String s1, String s2) {

		if(s1.length() != s2.length())
			return false;

		char[] s1_array = s1.toCharArray();
		char[] s2_array = s2.toCharArray();

		Arrays.sort(s1_array);
		Arrays.sort(s2_array);

		for(int i=0; i<s1_array.length; i++) {
			if(s1_array[i] != s2_array[i]) 
				return false;
		}

		return true;
	}

	public static boolean secondSolution(String s1, String s2) {

		if(s1.length() != s2.length()) 
			return false;

		int[] lookup = new int[128];
		int ascii = 0;
		for(int i=0; i<s1.length(); i++) {
			ascii = (int) s1.charAt(i);
			lookup[ascii]++;
		}

		for(int i=0; i<s2.length(); i++) {
			ascii = (int) s2.charAt(i);
			lookup[ascii]--;
			if(lookup[ascii] < 0)
				return false;
		}

		return true;
	}


	public static void main(String[] args) {
		String[] a_testset = new String[3];
		String[] b_testset = new String[3];

		a_testset[0] = "hello";
		a_testset[1] = "bye";
		a_testset[2] = "abd";

		b_testset[0] = "hello";
		b_testset[1] = "bey";
		b_testset[2] = "abc";

		for(int i=0; i<a_testset.length; i++) {
			System.out.println(a_testset[i] + " & " + b_testset[i] + ": " + firstSolution(a_testset[i], b_testset[i]));
		}

		for(int i=0; i<a_testset.length; i++) {
			System.out.println(a_testset[i] + " & " + b_testset[i] + ": " + secondSolution(a_testset[i], b_testset[i]));
		}

	}
}