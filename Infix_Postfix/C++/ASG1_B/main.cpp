/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1_B  C++                                      ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This is the main function. This function call 
 InputFile function.
 ********************************************************************/



#include<stdio.h>
#include<string>
#include<iostream>
#include "stack.h"
#include "infixtopostfix.h"
using namespace std;

int main(int argc, char *argv[])
    {
   
    string inputFilename = "";
    if(argc<2)
        {
                cout<<"Please enter the file name"<<endl;
        cin >> inputFilename;
        }
    else
        {
        inputFilename = argv[1];

        }
    
    InfixToPostFix  infix(inputFilename);
    infix.processInputFile();// calling input file
    //char c;
   //cin>> c;


    }


