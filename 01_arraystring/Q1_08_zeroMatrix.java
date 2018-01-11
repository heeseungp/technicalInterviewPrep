/*

	Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

	Conceptual Solution:
		$ create a boolean arrays for row and col
		$ iterate through the given array
		$ if 0 is found
			$ mark true on row and col array 
		$ fix the array

*/

import java.util.Arrays;
import java.util.*;

public class Q1_08_zeroMatrix {


	public static int[][] solution(int[][] image) {
		
		int rowSize = image.length;
		int colSize = image[0].length;

		boolean[] row = new boolean[rowSize];
		boolean[] col = new boolean[colSize];

		for(int i=0; i<rowSize; i++) {
			for(int j=0; j<colSize; j++) {
				if(image[i][j] == 0) {
					row[i] = true;
					col[j] = true;
				}
			}
		}

		nullifyRow(image, row);
		nullifyCol(image, col);
 		
 		return image;
	}

	public static void nullifyRow(int[][] image, boolean[] row) {
		for(int i=0; i<row.length; i++) { // iterating through boolean array
			if(row[i]) {
				for(int j=0; j<image[0].length; j++) {
					image[i][j] = 0;
				}
			}
		}
	}


	public static void nullifyCol(int[][] image, boolean[] col) {
		for(int i=0; i<col.length; i++) { // iterating through boolean array
			if(col[i]) {
				for(int j=0; j<image.length; j++) {
					image[j][i] = 0;
				}
			}
		}	
	}

	// Just printing the array
	public static void printArray(int[][] image) {
		System.out.println("");	
		for(int i=0; i<image.length; i++) {
			for(int j=0; j<image[0].length; j++) {
				System.out.print(image[i][j] + " ");
			}
			System.out.println("");
		}
		System.out.println("");
	}


	// Initialize the array by count
	public static int[][] initializeArray(int sizeA, int sizeB) {
		int count = 1;
		int[][] image = new int[sizeA][sizeB];
		for(int i=0; i<sizeA; i++) {
			for(int j=0; j<sizeB; j++) {
				image[i][j] = count;
			}
		}
		return image;
	}


	public static void main(String[] args) {

		int[][] testa = new int[3][5];
		testa = initializeArray(testa.length, testa[0].length);
		testa[1][1] = 0;
		printArray(testa);

		printArray(solution(testa));
	}
}