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
using System;
using System.IO;
namespace Algorithm
{


    public class Sort
    {

        public

            int array1Size;
        int array2Size;
        int array3Size;
        int targetval;
        static int maxsize;
        int[] inpArr1;
        int[] inpArr2;
        int[] inpArr3;
        StreamWriter writer;
      /*
     * =============Constructor for the Class===========
     */
        public Sort()
        {
            
             writer = new StreamWriter("output.txt");

            this.array1Size = 0;
            this.array2Size = 0;
            this.array3Size = 0;
            this.targetval = 0;
            maxsize = 30;
            this.inpArr1 = new int[maxsize];
            this.inpArr2 = new int[maxsize];
            this.inpArr3 = new int[2 * maxsize];
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

        public void readInputFile(string fileName)
        {
            string line;
            int i = 0;
            int j = 0;
            System.IO.StreamReader file = new System.IO.StreamReader(fileName);
           

            while ((line = file.ReadLine()) != null)
            {
                if (line == "")
                    break;
                inpArr1[i] = Convert.ToInt32(line);

                array1Size++;
                //Console.WriteLine(inpArr1[i]);
                i++;



            }
            Console.WriteLine("The first array: ");

            Console.WriteLine();

            writer.WriteLine("The first array: ");
            writer.WriteLine();
            printArray(inpArr1, array1Size);
            Console.WriteLine();
            writer.WriteLine();
            while ((line = file.ReadLine()) != null)
            {
                if (line == "")
                    break;
                inpArr2[j] = Convert.ToInt32(line);

                array2Size++;
                //Console.WriteLine(inpArr2[i]);
                j++;



            }


            Console.WriteLine();
            writer.WriteLine();
            Console.WriteLine("The second array: ");
            writer.WriteLine("The second array: ");
            Console.WriteLine();
            writer.WriteLine();
            printArray(inpArr2, array2Size);
            Console.WriteLine();
            writer.WriteLine();
            targetval = Convert.ToInt32(file.ReadLine());
            Console.WriteLine();
            writer.WriteLine();
            Console.WriteLine(("The target value is " + targetval));
            writer.WriteLine(("The target value is " + targetval));
            Console.WriteLine();
            writer.WriteLine();



            file.Close();
           
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
        void printArray(int[] inpArray, int count)
        {

            Console.Write("[");
            writer.Write("[");

            for (int i = 0; i < count; i++)
            {
                Console.Write(inpArray[i] + " ");
                writer.Write(inpArray[i] + " ");

            }

            Console.WriteLine("]");
            writer.Write("]");

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

        void insertionSort(int[] arrayList, int lastIndex)
        {
            int currVal = 1;
            int temVal = 0;
            int currentIndex = 0;

            while (currVal < lastIndex)
            {
                temVal = arrayList[currVal];
                currentIndex = currVal - 1;
                while (currentIndex >= 0 && temVal < arrayList[currentIndex])
                {
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


        void selectionSort(int[] arrayList, int lastIndex)
        {

            int currVal = 0;
            int smallVal = 0;
            int tempVal = 0;
            int swapVal = 0;
            while (currVal < lastIndex)
            {
                smallVal = currVal;

                tempVal = currVal + 1;
                while (tempVal < lastIndex)
                {

                    if (arrayList[tempVal] < arrayList[smallVal])
                    {
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

        void mergSort(int[] inpArr1, int[] inpArr2, int array1Size, int array2Size)
        {

            int i = 0;
            int j = 0;
            int[] tempArray1 = new int[array1Size + 1];
            int[] tempArray2 = new int[array2Size + 1];
            for (int l = 0; l < array1Size; l++)
            {
                tempArray1[l] = inpArr1[l];
            }
            for (int l = 0; l < array2Size; l++)
            {
                tempArray2[l] = inpArr2[l];
            }

            tempArray1[array1Size] = Int32.MaxValue;

            tempArray2[array2Size] = Int32.MaxValue;

            int maxarray3Size = array1Size + array2Size;

            for (int k = 0; k < maxarray3Size; k++)
            {

                if (tempArray1[i] < tempArray2[j])
                {
                    if (inpArr3[k - 1] == tempArray1[i])
                    {
                        maxarray3Size--;
                        k--;
                        i++;
                    }
                    else
                    {
                        inpArr3[k] = tempArray1[i];
                        i++;
                        array3Size++;
                    }
                }
                else if (tempArray1[i] == tempArray2[j])
                {
                    if (inpArr3[k - 1] == tempArray1[i])
                    {
                        maxarray3Size--;
                        k--;
                        i++;
                        j++;
                    }

                    else
                    {
                        inpArr3[k] = tempArray1[i];
                        i++;
                        j++;
                        array3Size++;
                        maxarray3Size--;
                    }
                }
                else
                {

                    if (k > 0 && (inpArr3[k - 1] == tempArray2[j]))// need to change k-1
                    {
                        maxarray3Size--;
                        k--;
                        j++;
                    }
                    else
                    {
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

        int binarySearch(int[] inpArr3, int key, int left, int right)
        {

            int m = 0;
            m = (left + right) / 2;
            if (left > right)
            {
                return -1;
            }
            if (inpArr3[m] == key)
            {
                return m;
            }

            else if (key < inpArr3[m])
            {
                return binarySearch(inpArr3, key, left, m - 1);
            }
            else
            {
                return binarySearch(inpArr3, key, m + 1, right);
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

        public void sortingArray()
        {

            insertionSort(inpArr1, array1Size);
            Console.WriteLine("After sorting first array using insertion sort");
            writer.WriteLine("After sorting first array using insertion sort");

            Console.WriteLine();
            writer.WriteLine();
            printArray(inpArr1, array1Size);
            Console.WriteLine();
            writer.WriteLine();
            Console.WriteLine();
            writer.WriteLine();
            selectionSort(inpArr2, array2Size);

            Console.WriteLine("After sorting second array using selection sort");
            writer.WriteLine("After sorting second array using selection sort");
            Console.WriteLine();
            writer.WriteLine();



            printArray(inpArr2, array2Size);

            Console.WriteLine();
            writer.WriteLine();

            mergSort(inpArr1, inpArr2, array1Size, array2Size);

            Console.WriteLine();
            writer.WriteLine();


            Console.WriteLine("After merging first and second array using merge sort");
            writer.WriteLine("After merging first and second array using merge sort");

            Console.WriteLine();
            writer.WriteLine();

            printArray(inpArr3, array3Size);


            int bsIndex = binarySearch(inpArr3, targetval, 0, array3Size - 1);
            if (bsIndex == -1)
            {
                Console.WriteLine();
                writer.WriteLine();
                Console.WriteLine();
                writer.WriteLine();
                Console.WriteLine("The target value " + targetval + " not found");
                writer.WriteLine("The target value " + targetval + " not found");

            }
            else
            {
                Console.WriteLine();
                Console.WriteLine();
                writer.WriteLine();
                writer.WriteLine();


                Console.WriteLine("The target value: " + targetval + " found at index: " + bsIndex);
                writer.WriteLine("The target value: " + targetval + " found at index: " + bsIndex);

            }

            Console.WriteLine();
            writer.WriteLine();

            Console.WriteLine("Program Completed");
            writer.WriteLine("Program Completed");

            writer.Close();
        }

    }
}


  