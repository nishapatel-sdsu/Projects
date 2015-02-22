/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                           ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class inpmlement pass 1 of the assmebler.This 
class is used to generate and intermediate file from the program 
source code.********
********************************************************************/
#include<stdio.h>
#include <iostream>
#include<string>
#include<vector>
#include "patelnst.h"
#include "patelnliteraltable.h"
#include "patelnopcodetable.h"
#include "patelnexp.h"

using namespace std;
extern ofstream outf; // output file
extern ofstream outflst;
extern ofstream outfobj;
#ifndef pass1_H_
#define pass1_H_
class Pass1Assembler{
    vector<string> lines;
    int programLength ;
    SymbolTable	symboltable ;
    OpcodeTable opcodetable;
    Linklist<literals,string> literallist;
    ExpressTable expresstable;
  void  appendliterals();
  void  addRegisters();

public:

  OpcodeTable*  getopcodetable();
  ExpressTable *getexpresstable();
   Linklist<literals,string> *getliterallist();
   SymbolTable	*getsymboltable();
    int	getprogramlength();
/********************************************************************
*** FUNCTION init()                                            
*********************************************************************
*** DESCRIPTION :This function is used to initialize the          ***
                 Pass1Assembler. It is used to create the opcode  ***
                 table.                                           ***
                 It then sets the references for the symbol table ***
                 and literal list for the expression table        ***
                 It is a default constructor                      ***

*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/


    void  init();
/********************************************************************
*** FUNCTION Pass1Assembler                                            
*********************************************************************
*** DESCRIPTION :This is the constructor of Pass1Assembler class ***
                 It is a default constructor                      ***

*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/
    Pass1Assembler();


/********************************************************************
*** FUNCTION  readexpfile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the program source file
                 It processes the file for Pass1 assembler. 
                 Generates the intermediate .int file             ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

    void readprogramFile(string filename);



  
};
#endif