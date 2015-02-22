/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg1_A  C                                        ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This is the main function. This function call 
 readInputFile function.
 ********************************************************************/


#include<stdio.h>
#include "Algorithm.h"
void main(){
   
   int c;
    struct Sort sort;
   c= 0;
   
    

   readInputFile(&sort);// input file
   sortingArray(&sort);
   scanf("%d",&c);

    }