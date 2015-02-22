/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1  C++                                          ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : Header file for sort class.
 ********************************************************************/


#include<stdio.h>
#include<iostream>
#include<string>

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

using namespace std;

class Sort
    {

     private:
           string fileName;
           
    public:
        int array1Size;
           int array2Size;
           int  array3Size ;
           int targetval ;
    static const int maxsize ;
   Sort(string);
   int *inpArr1;
   int *inpArr2;
   int *inpArr3;
   void readInputFile();// reading file
   void printArray(int*,int);// use to print the array
   void insertionSort(int * , int);
   void selectionSort(int * ,int);
   void sortingArray();
   void mergSort(int *, int* , int, int);
   int binarySearch(int *, int , int,int);
    };

#endif