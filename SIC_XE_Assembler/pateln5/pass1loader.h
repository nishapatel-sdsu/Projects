/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to create a SymbolTable using 
binary search tree.
********************************************************************/
#include<stdio.h>
#include <iostream>
#include<string>
#include "patelnliteraltable.h"
#include "patelnsymbolattribute.h"


using namespace std;
extern ofstream outf;

#ifndef Pass1loader_H_
#define Pass1loader_H_
void tocontinue();
class Pass1loader{
private:
    Linklist<SymbolAttribute,string> literallist;
      string loadaddr ;
      string csaddr ;
     string memory[480];
     int maxLoc ;
     int totalproglength;
     string execaddr;
public:

/********************************************************************
*** FUNCTION  Pass1loader                                         ***
*********************************************************************
*** DESCRIPTION : *** The default constructor for the class       ***
*** INPUT ARGS  :                                                 ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      :                                                 ***
********************************************************************/

     Pass1loader();

/********************************************************************
*** FUNCTION  readFile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read thefile
                 It processes the file to generate the symbol table  
                                                                  ***
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
     void  readFile(string filename);

/********************************************************************
*** FUNCTION  processFirstline                                    ***
*********************************************************************
*** DESCRIPTION :The function is used to process the first line 
                 to extract the symbol header and length   
                                                                  ***
*** INPUT ARGS  : string line : The header line to be processed   *** 
*** OUTPUT ARGS : -string length : The length of the section      ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void processFirstline(string line,string &length);
 
/********************************************************************
*** FUNCTION  showSymbolTable                                     ***
*********************************************************************
*** DESCRIPTION :The function is used to show symbol table   
                                                                  ***
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS :                                                 ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void showSymbolTable();

/********************************************************************
*** FUNCTION  pass2Loader                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the file for pass2 
                 relocation and loading of program in memory
                 
*** INPUT ARGS  :   string filename : file to be processed        *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void pass2Loader(string filename);
/********************************************************************
*** FUNCTION  initializeCSAddr                                    ***
*********************************************************************
*** DESCRIPTION :The function is used to initialize the control 
                 section address to progaddr 
                 
*** INPUT ARGS  :   string filename : file to be processed        *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void initializeCSAddr();

/********************************************************************
*** FUNCTION  printMemory                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to print the contents of 
                 the memory 
                 
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void   printMemory();

/********************************************************************
*** FUNCTION  intialMemoryLoc                                     ***
*********************************************************************
*** DESCRIPTION :The function is used to initialize memory location 
                 
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void intialMemoryLoc();

    };
#endif