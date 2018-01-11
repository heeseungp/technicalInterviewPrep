/*

	Rotate Matrix: Given an image represented by NxN matrix, where each pixel in the image is 4 bytes,
					write a method to rotate the image by 90 degrees. Can you do this in place?

	Conceptual Solution:
		start = 0
		end = array.length - 1
		$ outer layer to inner layer 
			$ save the top row ***
			$ left -> top
			$ bottom -> left	
			$ right -> bottom
			$ saved top *** -> right
			$ start++
			$ end--

*/	


import java.util.*;

public class Q1_07_rotateMatrix {

	public static int[][] solution(int[][] image) {

		int n = image.length;
		for(int layer=0; layer<n/2; layer++) { // iterating outer layer to inner layer
			int begin = layer;
			int end = n-1-layer;
			for(int i=begin; i<end; i++) {
				int top = image[begin][i]; 								// save the top (layer)
				image[begin][i] = image[end-i][begin]; 					// left -> top
				image[end-i][begin] = image[end][end-i]; 				// bottom -> left
				image[end][end-i] = image[begin+i][end]; 				// right -> bottom
				image[begin+i][end] = top; 								// saved top -> right
			}
		}
		return image;
	}

	// Initialize the array from 0
	public static int[][] initializeArray(int size) {
		int count = 0;
		int[][] image = new int[size][size];
		for(int i=0; i<image.length; i++) {
			for(int j=0; j<image.length; j++) {
				image[i][j] = count++;
			}
		}
		return image;
	}

	// Just printing the array
	public static void printArray(int[][] image) {
		System.out.println("");	
		for(int i=0; i<image.length; i++) {
			for(int j=0; j<image.length; j++) {
				System.out.print(image[i][j] + " ");
			}
			System.out.println("");
		}
		System.out.println("");
	}

	public static void main(String[] args) {
		// int[][] testa = new int[2][2];
		// testa = initializeArray(testa.length);
		// printArray(testa);
		// printArray(solution(testa));

		int[][] testb = new int[4][4];
		testb = initializeArray(testb.length);
		printArray(testb);
		printArray(solution(testb));

	}
}		