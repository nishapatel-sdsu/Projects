
/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg1_A  C                                        ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : Header file for sort class.
 ********************************************************************/

#include<stdio.h>

#ifndef ALGORITHM_H_
#define ALGORITHM_H_


struct Sort
    {
char * fileName;
 int array1Size;
  int array2Size;
  int  array3Size ;
    int *inpArr1;
   int *inpArr2;
   int *inpArr3;
    int maxsize ;
    int target;
    };

  
   void readInputFile(struct Sort *sort);
   void printArray(int*,int);
   void insertionSort(int * , int);
   void selectionSort(int * ,int);
   void sortingArray(struct Sort *sort);
   void mergSort(struct Sort *sort);
   int binarySearch(struct Sort *sort, int , int,int);
    
#endif