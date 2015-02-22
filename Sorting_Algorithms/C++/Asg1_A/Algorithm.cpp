/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1  C++                                          ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This module implement  Insertion Sort , Selection Sort 
  Merge sort and Binary search tree.
 ********************************************************************/



#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include <fstream>
#include "Algorithm.h"

using namespace std;
extern ofstream outf;
/********************************************************************
 *** FUNCTION Sort                                                ***
 *********************************************************************
 *** DESCRIPTION : This is the constructor for the  sort          ***
*** INPUT ARGS  :- string filename                                ***
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : -                                               ***
 ********************************************************************/

int const Sort :: maxsize = 30;
Sort :: Sort(string fileName){
           this->fileName = fileName;
          inpArr1 = new int[ maxsize];
          inpArr2 = new int[ maxsize];
          inpArr3 = new int[maxsize];
           array1Size =0;
           array2Size= 0;
            array3Size =0; 
    }

/********************************************************************************
 *** FUNCTION readInputFile                                                    ***
 *********************************************************************************
 *** DESCRIPTION : This function read the input file                           ***                 
 *** INPUT ARGS  : None                                                         ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/

   

    void Sort :: readInputFile()
        {
         ifstream inf;
      
         inf.open(fileName);
         outf.open("output.txt");
           //cout<<maxsize;
         if (!inf) {
        cout << "can't open file";
        return ;
        }
             string line = "";
         if(inf.eof()){
               cout << "Incorrect file format";
              return ;
            }
         

          
         // cout<<line<<endl;
          for(int i= 0; i<maxsize; i++)
              {
              if(inf.eof())
                  break;
              
              getline(inf, line);
              
              if(line == "")
                  break;
               inpArr1[i]  = atoi(line.c_str());
               array1Size++;
               
              }
           cout<<"The first array: "<<endl;
           outf<<"The first array: "<<endl;
           printArray(inpArr1, array1Size);
          cout<<endl;
          outf<<endl;
        
          for(int i= 0; i<maxsize; i++)
              {
              
              if(inf.eof())
                  break;
              
              getline(inf, line);
              
              if(line == "")
                  break;
               inpArr2[i]  = atoi(line.c_str());
               array2Size++;
             
                  
          }
          cout<<"The second array: ";
           outf<<"The second array: ";
    



   printArray(inpArr2, array2Size);
   cout<<endl;
   outf<<endl;
   getline(inf, line);
     targetval = atoi(line.c_str());
     cout<<"The target value is "<<targetval<<endl<<endl;
     outf<<"The target value is "<<targetval<<endl<<endl;
     
           }
 /********************************************************************************
 *** FUNCTION PrintArray                                                   ***
 *********************************************************************************
 *** DESCRIPTION : This function print array element.                         ***                 
 *** INPUT ARGS  : integer, integer *                                         ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/
    void Sort:: printArray(int *inpArray, int count){
        
        cout<<"[";
		outf<<"[";
        for(int i =0; i<count; i++)
            {
            cout<<inpArray[i]<<" ";
             outf<<inpArray[i]<<" ";
            }
          cout<<"]"<<endl;
		   outf<<"]"<<endl;
                }
 /********************************************************************************
*** FUNCTION InsertionSort                                                   ***
*********************************************************************************
*** DESCRIPTION : This function sort the element from array 1                ***                 
*** INPUT ARGS  : integer, integer *                                         ***
*** OUTPUT ARGS : None                                                        ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/


     void Sort :: insertionSort(int *arrayList , int lastIndex){


         int currVal = 1;
         int temVal =0;
         int currentIndex =0;
         while(currVal <lastIndex)
             {
            temVal = arrayList[currVal];
             currentIndex = currVal-1;
             while(currentIndex >= 0 && temVal < arrayList[currentIndex])
                 {
                 arrayList[currentIndex +1] = arrayList[currentIndex];
                 currentIndex--;

                 }
             arrayList[currentIndex +1] = temVal;
             currVal++;
             }
         }

 /********************************************************************************
 *** FUNCTION selectionSort                                                   ***
 *********************************************************************************
 *** DESCRIPTION : This function sort the element from array 2                ***                 
 *** INPUT ARGS  : integer, integer *                                         ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/

      void  Sort :: selectionSort(int *arrayList ,int lastIndex)
          {

          int currVal = 0;
          int smallVal = 0;
          int tempVal = 0;
          int swapVal =0;
          while(currVal< lastIndex)
              {
              smallVal = currVal;

              tempVal = currVal +1;
              while(tempVal <lastIndex)
                  {

                  if(arrayList[tempVal] < arrayList[smallVal])
                      {
                      smallVal = tempVal;
                      }
                  tempVal++;
                  }
              swapVal =arrayList[currVal];
              arrayList[currVal] =arrayList[smallVal];
              arrayList[smallVal] =swapVal;
              currVal++;
              }

          }

 /********************************************************************************
 *** FUNCTION sortingArray                                                    ***
 *********************************************************************************
 *** DESCRIPTION : This function use to call all sorting function.             ***                 
 *** INPUT ARGS  : None                                                        ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/


     void  Sort ::sortingArray(){
          insertionSort(inpArr1 , array1Size);
            cout<<"After sorting first array using insertion sort"<<endl<<endl;
              outf<<"After sorting first array using insertion sort"<<endl<<endl;
      
        printArray(inpArr1, array1Size);
        cout<<endl;
        selectionSort(inpArr2 , array2Size);
          
         
          cout<<"After sorting second array using selection sort"<<endl;
           outf<<"After sorting second array using selection sort"<<endl;
   cout<<endl;


    printArray(inpArr2, array2Size);
    mergSort(inpArr1, inpArr2 , array1Size,array2Size);
     cout<<endl;
     outf<<endl;
     cout<<"After merging first and second array using merge sort"<<endl;
     outf<<"After merging first and second array using merge sort"<<endl;
   cout<<endl;
    outf<<endl;
    printArray(inpArr3, array3Size);
   
   int bsIndex = binarySearch(inpArr3,targetval, 0,array3Size-1);
   if(bsIndex == -1){
       cout<<"The target value "<<targetval<< " not found"<<endl;
        outf<<"The target value "<<targetval<< " not found"<<endl;
       }
   else{
       cout<<endl<<endl;
     outf<<endl<<endl;
   cout<<"The target value: "<<targetval<<" found at index: "<<bsIndex<<endl;
   outf<<"The target value: "<<targetval<<" found at index: "<<bsIndex<<endl;
       }
         }

/********************************************************************************
 *** FUNCTION mergSort                                                        ***
 *********************************************************************************
 *** DESCRIPTION : This function  mergr element from from array 1 and array 2. *** 
Then it store the megre element  in array 3.                                   ***                 
 *** INPUT ARGS  : integer, integer *  integer, integer *                      ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/

     void Sort:: mergSort(int *inpArr1, int*inpArr2 , int array1Size, int array2Size){

         int i =0;
         int j =0;
         int *tempArray1 = new int[array1Size +1];
          int *tempArray2 = new int[array2Size +1];
          for(int l = 0; l<array1Size ;l++)
              {
              tempArray1[l] =inpArr1[l];
              }
          for(int l = 0; l<array2Size ;l++)
              {
              tempArray2[l] =inpArr2[l];
              }

         tempArray1[array1Size] = numeric_limits<int>::max();
         
          tempArray2[array2Size] = numeric_limits<int>::max();

          int maxarray3Size = array1Size + array2Size;
         
        // cout<<"Size1:"<<array1Size<<endl;
         //cout<<"Size2:"<<array2Size<<endl;
         for(int k =0; k< maxarray3Size; k++)
             {

             if(tempArray1[i] < tempArray2[j])
                 {
                 if(inpArr3[k-1] ==tempArray1[i])
                     {
                     maxarray3Size--;
                     k--;
                     i++;
                     }
                 else {
                 inpArr3[k] = tempArray1[i];
                 i++;
                 array3Size++;
                     }
                 }
             else if(tempArray1[i] == tempArray2[j])
                 {
                  if(inpArr3[k-1] ==tempArray1[i])
                     {
                     maxarray3Size--;
                      k--;
                      i++;
                   j++; 
                     }

                  else{
                 inpArr3[k] = tempArray1[i];
                 i++;
                   j++;  
                   array3Size++;
                   maxarray3Size--;
                 }
                 }
             else{
                 if(inpArr3[k-1] ==tempArray2[j])
                     {
                     maxarray3Size--;
                      k--;
                      j++;
                     }
                 else{
                 inpArr3[k] = tempArray2[j];
                 j++;
                 array3Size++;
                 }
                 }
             }
         delete tempArray1;
         delete tempArray2;
         }
/********************************************************************
 *** FUNCTION BST_search                                           ***
 *********************************************************************
 *** DESCRIPTION :This function is used to serch value in the      ***
     binary  search tree                                           ***
 *** INPUT ARGS  :integer*,Integer key, integer left,integer right *** 
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : Return the  search  value.                      ***
 ********************************************************************/

        int Sort :: binarySearch(int *inpArr3, int key, int left,int right){

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