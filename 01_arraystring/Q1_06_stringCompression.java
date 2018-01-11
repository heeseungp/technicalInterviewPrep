/*

	String Compression: Implement a method to perform basic string compression using the counts of repeated characters.
						For example, the string aabcccccaaa would become a2b1c5a3.
						If the "compressed" string would not become smaller than the original string, your method should return the original string.
						You can assume the string has only uppercase and lower case letters(a-z).

	Conceptual Solution:
		$ for loop through the sequence of characters from a given string
			$ increment counter
			$ if not seeing the same char
				$ append the char to StringBuilder
				$ append the counter to StringBuilder
				$ reset the counter to 0

		$ Check if the StringBuilder size is smaller than the original string length

*/

import java.util.*;

public class Q1_06_stringCompression {

	public static String solution(String str) {

		StringBuilder result = new StringBuilder();
		int counter = 0;
		for(int i=0; i<str.length(); i++) {
			counter++;
			if(i+1 >= str.length() || str.charAt(i) != str.charAt(i+1)) {
				result.append(str.charAt(i));
				result.append(counter);
				counter = 0;
			}
		}

		return (result.toString()).length() < str.length() ? result.toString() : str;
	}


	public static void main(String[] args) {
		String[] testset = new String[3];
		testset[0] = "aabcccccaaa";
		testset[1] = "aaabc";
		testset[2] = "abc";

		for(int i=0; i<testset.length; i++) {
			System.out.println(testset[i] + ": " + solution(testset[i]));
		}
	}
}			