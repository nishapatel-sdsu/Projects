/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1  C++                                          ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This is the main function. This function call 
 readInputFile function.
 ********************************************************************/



#include<stdio.h>
#include<iostream>
#include <string>
#include<fstream>
#include "Algorithm.h"

using namespace std;
ofstream outf;
int main(int argc, char *argv [])
    {
    string inputFilename = "";
    

    
    //Read the name of the expression file.
    if(argc <2){
        cout<<"Please enter the file name"<<endl;
        cin >> inputFilename;
        }
    else{
        inputFilename = argv[1] ;
        }
      Sort sort(inputFilename);
       sort.readInputFile();// reading input file 
      sort.sortingArray();

  // char c;
   //cin>>c;
 
    }