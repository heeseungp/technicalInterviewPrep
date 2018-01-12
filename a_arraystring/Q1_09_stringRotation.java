/*

	String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. 
					Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring

	Conceptual Solution:
		Concatenate the s1 + s1.
		Call isSubstring to verify

*/

public class Q1_09_stringRotation {

	public static boolean solution(String s1, String s2) {

		int len = s1.length();
		if(len == s2.length() && len > 0) {
			return isSubstring(s1+s1, s2);
		}
		return false;
	}

	public static void main(String[] args) {


	}
}