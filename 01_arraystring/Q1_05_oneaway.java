/*

	One Away: There are three types of edits that can be performed on strings
				1. Insert a character
				2. Remove a character
				3. Replace a character
			Given two strings, write a function to check if they are one edit(or zero edits) away.
	
	Conceptual Solution: 
		First check if two strings are the same length or one length short or long.
		if insertion, then you need to move the longer string index up by one where the elements are not equal
		extraction is the same concept as the insertion.
		
		replacement (means two parameters have equal length)
		iterate both strings and find anomaly. If found, update your state to true, and continue.

*/

import java.util.*;

public class Q1_05_oneaway {

	public static boolean oneaway(String s1, String s2) {

		// check two strings length
		int difference = s1.length() - s2.length();
		if(Math.abs(difference) > 1)
			return false;

		if(difference == 0) {
			// same size, zero edit or replacement
			boolean rState = false;
			for(int i=0; i<s1.length(); i++) {
				if(s1.charAt(i) != s2.charAt(i)) {
					if(rState) return false;
					else rState = true;
				}	
			}
			return true;
		} else if(difference == -1) {
			return oneEdit(s2, s1);
		} else {
			return oneEdit(s1, s2);
		}
	}

	public static boolean oneEdit(String s1, String s2) {
		// make sure the s1 is bigger than s2 by one
		int i_s1 = 0;
		int i_s2 = 0;
		while(i_s1 < s1.length() && i_s2 < s2.length()) {
			if(s1.charAt(i_s1) != s2.charAt(i_s2)) {
				if(i_s1 != i_s2)
					return false;
				i_s1++;					
			} else {
				i_s1++;
				i_s2++;	
			}
		}
		return true;
	}

	public static void main(String[] args) {

		String[] testsetA = new String[4];
		String[] testsetB = new String[4];

		testsetA[0] = "pale";
		testsetA[1] = "pales";
		testsetA[2] = "pale";
		testsetA[3] = "pale";

		testsetB[0] = "ple";
		testsetB[1] = "pale";
		testsetB[2] = "bale";
		testsetB[3] = "bake";

		for(int i=0; i<testsetB.length; i++) {
			System.out.println(testsetA[i] + " & " + testsetB[i] + ": " + " "  + oneaway(testsetA[i], testsetB[i]));
		}

	}
}