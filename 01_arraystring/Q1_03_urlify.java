/*

	URLify: Write a method to replace all spaces in a string with "%20".
			You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

	Conceptual Solutions:
		*skips are defined as the number of steps it will move to the right
		We can find the number of !skips! by calculating array.length() - truelength.
		We use skip length to determine the new position for each chars.
		When we encounter a space, then we write 0 2 % downwards.
		The skip will be skip = skip - 2 after every space we see.

*/

public class Q1_03_urlify {
	
	public static String urlify(String str, int truelength) {
		char[] charArray = str.toCharArray();
		int nspace = (charArray.length - truelength)/2;
		int end = charArray.length - 1;
		int start = truelength - 1;

		while(nspace != 0) {
			if(charArray[start] != ' ') {
				charArray[end--] = charArray[start--];
			} else {
				charArray[end--] = '0';
				charArray[end--] = '2';
				charArray[end--] = '%';
				start--;
				nspace--;
			}
		}
		
		return new String(charArray);
	}

	public static void main(String[] args) {

		String test = "Mr John Smith    ";
		int truelength = 13;

		System.out.println(urlify(test,13));

	}
}