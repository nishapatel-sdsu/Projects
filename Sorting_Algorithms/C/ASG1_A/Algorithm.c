/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg1_A  C                                        ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This module implement  Insertion Sort , Selection Sort 
  Merge sort and Binary search tree.
 ********************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Algorithm.h"



/********************************************************************************
 *** FUNCTION readInputFile                                                    ***
 *********************************************************************************
 *** DESCRIPTION : This function read the input file                           ***                 
 *** INPUT ARGS  : None                                                         ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/


 FILE *rp;
void readInputFile(struct Sort *sort)
  {
   int i;
            
  FILE *fp;
  
  char ch;
  char line[40];
    sort->array1Size = 0;
  sort-> array2Size = 0;
    sort->maxsize = 30;
  sort->inpArr1 =(int*) malloc(sort->maxsize*sizeof(int));
 sort-> inpArr2 = (int*) malloc(sort->maxsize*sizeof(int));
   fp = fopen("input.txt", "r");
   rp = fopen("output.txt", "w");
      if(fp == NULL)
          {
          printf("can't open the file");
          exit(1);
          }

    

    for( i= 0; i< sort->maxsize; i++)
              {
             
             if( fgets(line,40,fp) == NULL) break;
             line[ strlen(line) - 1 ] = '\0';
               
              
              if(strlen(line) == 0)
                  break;
              sort->inpArr1[i]  = atoi(line);
                  sort->array1Size++;
               
              }
     printf("Program started ASG1_A C: \n\n");
     fprintf(rp,"Program started ASG1_A C: \n\n");
     
     printf("The first array: \n");
      fprintf(rp,"The first array: \n");
    
          
    printArray( sort->inpArr1, sort->array1Size);
     fprintf(rp,"\n");
     printf("\n");
        
        fprintf(rp,"\n");
    for( i= 0; i< sort->maxsize; i++)
              {
              
             if( fgets(line,40,fp) == NULL) break;
			     if (line[strlen(line) - 1] == '\n') 
              line[ strlen(line) - 1 ] = '\0';
               
              
              if(strlen(line) == 0)
                  break;
              sort->inpArr2[i]  = atoi(line);
                   sort->array2Size++;
             
                  
          }
    fgets(line,40,fp);
  sort->target =  atoi(line);
    printf("The second array: ");
    fprintf(rp,"The second array: ");
       printf("The target value is %d \n\n",sort->target);
        fprintf(rp,"The target value is %d \n\n",sort->target);

     printArray( sort->inpArr2, sort->array2Size);
   
     printf("\n");
    
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

           
 void  printArray(int *inpArray, int count){
     int i;   
     
         printf("[ ");
          fprintf(rp,"[ ");
        for( i =0; i<count; i++)
            {
            printf("%d ",*inpArray);
            
            fprintf(rp,"%d ",*inpArray);
           
            inpArray++;
            
            }
        printf("]\n");
          fprintf(rp,"]\n");
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


                
     void insertionSort(int *arrayList , int lastIndex){


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

      void   selectionSort(int *arrayList ,int lastIndex)
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

     void  sortingArray(struct Sort * sort){
        
          int bsIndex ;
          insertionSort(sort->inpArr1 , sort->array1Size);
            printf("After sorting first array using insertion sort\n\n");
             fprintf(rp,"After sorting first array using insertion sort\n\n");
      
        printArray(sort->inpArr1 , sort->array1Size);
        printf("\n");
        selectionSort(sort->inpArr2 , sort->array2Size);
          
         printf("After sorting second array using selection sort\n\n");
           fprintf(rp,"After sorting second array using selection sort\n\n");
  


    
     printArray(sort->inpArr2 , sort->array2Size);
      printf("\n");
    fprintf(rp,"\n");
    mergSort(sort);
     printf("After merging first and second array using merge sort\n\n");
      fprintf(rp,"After merging first and second array using merge sort\n\n");
   
   printArray(sort->inpArr3 , sort->array3Size);
   printf("\n");
    fprintf(rp,"\n");
    
   bsIndex = binarySearch(sort,sort->target , 0,sort->array3Size-1);
   if(bsIndex == -1){
       printf("The target value %d not found\n" ,sort->target);
       fprintf(rp,"The target value %d not found\n" ,sort->target);
       
       }
   else
       {
    printf("The target value %d found at index: %d\n" ,sort->target,bsIndex);
   fprintf(rp,"The target value %d found at index: %d\n" ,sort->target,bsIndex);
       }
    fclose(rp);
         }
/********************************************************************************
 *** FUNCTION mergSort                                                          ***
 *********************************************************************************
 *** DESCRIPTION : This function  mergr element from from array 1 and array 2. *** 
Then it store the megre element  in array 3.                                   ***                 
 *** INPUT ARGS  : integer, integer *  integer, integer *                                          ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/

      void  mergSort(struct Sort *sort){

         int i =0;
         int j =0;
         int l;
         int k;
         int maxarray3Size;
          int *tempArray1;
               int *tempArray2 ;
          sort-> array3Size = 0;
         tempArray1 =(int*) malloc((sort->array1Size +1)*sizeof(int)); 
         tempArray2 = (int*) malloc((sort->array2Size +1)*sizeof(int));
          sort->inpArr3 =(int*) malloc(sort->maxsize*sizeof(int));
         
          for(l = 0; l<sort->array1Size ;l++)
              {
              tempArray1[l] =sort->inpArr1[l];
             
              }
          for(l = 0; l<sort->array2Size ;l++)
              {
              tempArray2[l] =sort->inpArr2[l];
              }

         tempArray1[sort->array1Size] = 1000;
         
          tempArray2[sort->array2Size] = 1000;

          maxarray3Size = sort->array1Size + sort->array2Size;
         
        
         for(k =0; k< maxarray3Size; k++)
             {

             if(tempArray1[i] < tempArray2[j])
                 {
                 if(sort->inpArr3[k-1] ==tempArray1[i])
                     {
                     maxarray3Size--;
                     k--;
                     i++;
                     }
                 else {
                 sort->inpArr3[k] = tempArray1[i];
                 i++;
                 sort->array3Size++;
                     }
                 }
             else if(tempArray1[i] == tempArray2[j])
                 {
                  if(sort->inpArr3[k-1] ==tempArray1[i])
                     {
                     maxarray3Size--;
                      k--;
                      i++;
                   j++; 
                     }

                  else{
                 sort->inpArr3[k] = tempArray1[i];
                 i++;
                   j++;  
                   sort->array3Size++;
                   maxarray3Size--;
                 }
                 }
             else{
                 if(sort->inpArr3[k-1] ==tempArray2[j])
                     {
                     maxarray3Size--;
                      k--;
                      j++;
                     }
                 else{
                 sort->inpArr3[k] = tempArray2[j];
                 j++;
                 sort->array3Size++;
                 }
                 }
             }
         free (tempArray1);
         free (tempArray2);
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

     int  binarySearch(struct Sort *sort, int key, int left,int right){

            int m = 0;
            m = (left + right)/2;
            if(left > right)
                {
            return -1;
                }
            if( sort->inpArr3[m] == key)
                {
                return m;
                }

            else if(key <  sort->inpArr3[m])
                {
                return binarySearch(sort, key, left, m-1);
                }
            else
                {
                return binarySearch(sort, key, m+1, right);
                }
            }