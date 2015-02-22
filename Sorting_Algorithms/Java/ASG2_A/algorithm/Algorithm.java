
/********************************************************************
 *** NAME       : NISHA PATEL                                      
 *** CLASS      : CSc 710                                          
 *** ASSIGNMENT : Asg2_A  Java                                        
 *** DUE DATE   : 09/23/2012                                       
 *** INSTRUCTOR : Dr.Shin                                          
 *********************************************************************
 *** DESCRIPTION :This module implement  Insertion Sort , Selection Sort 
  Merge sort and Binary search tree.
 ********************************************************************/


package algorithm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;

import java.io.IOException;


public class Algorithm {

	public int array1Size;
	int array2Size;
	int array3Size;
	int targetval;
	static int maxsize;
	int inpArr1[];
	int inpArr2[];
	int inpArr3[];
	
	Writer output;
	/*
	 * =============Constructor for the Class===========
	 */
	public Algorithm() {
		super();
		this.array1Size = 0;
		this.array2Size = 0;
		this.array3Size = 0;
		this.targetval = 0;
		maxsize = 30;
		this.inpArr1 = new int[maxsize];
		this.inpArr2 = new int[maxsize];
		this.inpArr3 = new int[2 * maxsize];
		output = null;
	}
	/********************************************************************************
	 *** FUNCTION readInputFile                                                    
	 *********************************************************************************
	 *** DESCRIPTION : This function read the input file.                                           
	 *** INPUT ARGS  : String filename                                                        
	 *** OUTPUT ARGS : None                                                        
	 *** IN/OUT ARGS : -                                                           
	 *** RETURN      : void                                                        
	 *********************************************************************************/
	void readInputFile(String fileName) throws IOException {

		String line;
		FileReader fin;

		fin = new FileReader(fileName);
		BufferedReader br = new BufferedReader(fin);
		output = new BufferedWriter (new FileWriter(new File("output.txt")));

		// read characters until Eof is encountered
		int i = 0;
		int j = 0;
		while ((line = br.readLine()) != null)

		{

			if (line.equals(""))
				break;
			inpArr1[i] = Integer.parseInt(line);
			array1Size++;
			// System.out.println(inpArr1[i] );

			i++;
		}
		System.out.println("The first array: ");
		output.write("The first array: \n");
		System.out.println();
		output.write("\n");
		printArray(inpArr1, array1Size);
		System.out.println();
		output.write("\n");
		while ((line = br.readLine()) != null) {

			if (line.equals(""))
				break;
			inpArr2[j] = Integer.parseInt(line);
			array2Size++;
			// System.out.println(inpArr2[i] );
			j++;
		}
		System.out.println();
		output.write("\n");
		System.out.println("The second array: ");
		output.write("The second array: \n");
		System.out.println();
		output.write("\n");
		printArray(inpArr2, array2Size);
		System.out.println();
		output.write("\n");
		targetval = Integer.parseInt(br.readLine());
		System.out.println();
		output.write("\n");
		System.out.println("The target value is " + targetval);
		output.write("The target value is\n " + targetval);
		System.out.println();
		output.write("\n");
		
		

		fin.close();

	}
	/********************************************************************************
	 *** FUNCTION printArray                                                    
	 *********************************************************************************
	 *** DESCRIPTION : This function print Array.                                           
	 *** INPUT ARGS  : Integer array, Integer count                                                        
	 *** OUTPUT ARGS : None                                                        
	 *** IN/OUT ARGS : -                                                           
	 *** RETURN      : void                                                        
	 *********************************************************************************/
	void printArray(int inpArray[], int count) throws IOException {

		System.out.print("[");
		output.write("[");
		for (int i = 0; i < count; i++) {
			System.out.print(inpArray[i] + " ");
			output.write(inpArray[i] + " ");
		
		}

		System.out.print("]");
		output.write("]");
	}

	/********************************************************************************
	 *** FUNCTION InsertionSort 
	 ********************************************************************************* 
	 *** DESCRIPTION : This function sort the element from array 1  
	  INPUT ARGS : integer array , integer last index
	  OUTPUT ARGS : None 
	  IN/OUT ARGS : None
	  RETURN : void
	 ********************************************************************************* */

	void insertionSort(int arrayList[], int lastIndex) {
		int currVal = 1;
		int temVal = 0;
		int currentIndex = 0;

		while (currVal < lastIndex) {
			temVal = arrayList[currVal];
			currentIndex = currVal - 1;
			while (currentIndex >= 0 && temVal < arrayList[currentIndex]) {
				arrayList[currentIndex + 1] = arrayList[currentIndex];
				currentIndex--;

			}
			arrayList[currentIndex + 1] = temVal;
			currVal++;
		}
	}

	/********************************************************************************
	 *** FUNCTION selectionSort 
	 ********************************************************************************* 
	 *** DESCRIPTION : This function sort the element from array 2 
	 *** INPUT ARGS : integer array, integer last index 
	 *** OUTPUT ARGS : None 
	 *** IN/OUT ARGS : None
	 *** RETURN : void 
	 *********************************************************************************/

	void selectionSort(int arrayList[], int lastIndex) {

		int currVal = 0;
		int smallVal = 0;
		int tempVal = 0;
		int swapVal = 0;
		while (currVal < lastIndex) {
			smallVal = currVal;

			tempVal = currVal + 1;
			while (tempVal < lastIndex) {

				if (arrayList[tempVal] < arrayList[smallVal]) {
					smallVal = tempVal;
				}
				tempVal++;
			}
			swapVal = arrayList[currVal];
			arrayList[currVal] = arrayList[smallVal];
			arrayList[smallVal] = swapVal;
			currVal++;
		}

	}

	/********************************************************************************
	 *** FUNCTION mergSort 
	 ********************************************************************************* 
	 *** DESCRIPTION : This function mergr element from from array 1 and array 2.
	                   Then it store the megre element in array 3
	 *** INPUT ARGS :  integer array1, , integer array2* integer array1Size, 
	                   integer array2Size 
	 *** OUTPUT ARGS : None 
	 **** IN/OUT ARGS : None
	 *** RETURN : void 
	 *********************************************************************************/

	void mergSort(int inpArr1[], int inpArr2[], int array1Size, int array2Size) {

		int i = 0;
		int j = 0;
		int tempArray1[] = new int[array1Size + 1];
		int tempArray2[] = new int[array2Size + 1];
		for (int l = 0; l < array1Size; l++) {
			tempArray1[l] = inpArr1[l];
		}
		for (int l = 0; l < array2Size; l++) {
			tempArray2[l] = inpArr2[l];
		}

		tempArray1[array1Size] = Integer.MAX_VALUE;

		tempArray2[array2Size] = Integer.MAX_VALUE;

		int maxarray3Size = array1Size + array2Size;

		for (int k = 0; k < maxarray3Size; k++) {

			if (tempArray1[i] < tempArray2[j]) {
				if (inpArr3[k - 1] == tempArray1[i]) {
					maxarray3Size--;
					k--;
					i++;
				} else {
					inpArr3[k] = tempArray1[i];
					i++;
					array3Size++;
				}
			} else if (tempArray1[i] == tempArray2[j]) {
				if (inpArr3[k - 1] == tempArray1[i]) {
					maxarray3Size--;
					k--;
					i++;
					j++;
				}

				else {
					inpArr3[k] = tempArray1[i];
					i++;
					j++;
					array3Size++;
					maxarray3Size--;
				}
			} else {
				
				if ( k> 0 && (inpArr3[k - 1] == tempArray2[j]))// need to change k-1
				{
					maxarray3Size--;
					k--;
					j++;
				} else {
					inpArr3[k] = tempArray2[j];
					j++;
					array3Size++;
				}
			}
		}

	}
	/********************************************************************
	 *** FUNCTION BST_search                                           
	 *********************************************************************
	 *** DESCRIPTION :This function is used to serch value in the      
	                  binary  search tree                                           
	 *** INPUT ARGS  :integer array*,Integer key, integer left,integer right  
	 *** OUTPUT ARGS : None                                             
	 *** IN/OUT ARGS : None                                             
	 *** RETURN      : Return the  search  value.                      
	 ********************************************************************/

	        int  binarySearch(int inpArr3[], int key, int left,int right){

	            int m = 0;
	            m = (left + right)/2;
	            if(left > right)
	                {
	            return -1;
	                }
	            if(inpArr3[m] == key)
	                {
	                return m;
	                }

	            else if(key < inpArr3[m])
	                {
	                return binarySearch(inpArr3, key, left, m-1);
	                }
	            else
	                {
	                return binarySearch(inpArr3, key, m+1, right);
	                }
	            }

	/********************************************************************************
	 *** FUNCTION sortingArray ***
	 ********************************************************************************* 
	 *** DESCRIPTION : This function use to call all sorting function. 
	 *** INPUT ARGS : None 
	 *** OUTPUT ARGS : None 
	 *** IN/OUT ARGS : None
	 *** RETURN : void
      @throws IOException 
	 ********************************************************************************* */

	void sortingArray() throws IOException {

		insertionSort(inpArr1, array1Size);
		System.out.println("After sorting first array using insertion sort");
		output.write("After sorting first array using insertion sort\n");
		System.out.println();
		output.write("\n");
		printArray(inpArr1, array1Size);
		System.out.println();
		output.write("\n");
		System.out.println();
		output.write("\n");
		selectionSort(inpArr2, array2Size);

		System.out.println("After sorting second array using selection sort");
		output.write("After sorting second array using selection sort\n");
		
		System.out.println();
		output.write("\n");

		printArray(inpArr2, array2Size);
		System.out.println();
		output.write("\n");

		mergSort(inpArr1, inpArr2, array1Size, array2Size);
		System.out.println();
		output.write("\n");
		System.out
				.println("After merging first and second array using merge sort");
		 output.write("After merging first and second array using merge sort\n");
		System.out.println();
		output.write("\n");
		printArray(inpArr3, array3Size);

		
		  int bsIndex = binarySearch(inpArr3,targetval, 0,array3Size-1);
		  if(bsIndex == -1){
			  System.out.println();
			  System.out.println();
			  output.write("\n");
			  output.write("\n");
			  System.out.println("The target value " + targetval + " not found"); 
			  output.write("The target value " + targetval + " not found\n");
		   } 
		   else{
			   System.out.println();
			   System.out.println();
			   output.write("\n");
			   output.write("\n");
		  
			   System.out.println("The target value: " + targetval + " found at index: "+bsIndex);
			   output.write("The target value: " + targetval + " found at index: "+bsIndex);
		   }
		output.close(); 

	}
	

}
