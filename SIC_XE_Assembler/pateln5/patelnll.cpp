/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 5                                            ***
*** DUE DATE   : 12/07/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This assignment implements the linker and loader.
                  It has two passes. Pass1 is used to create a 
                  symbol table. Pass two is used to relocate and load 
                  the data in memory.
********************************************************************/
# include<iostream>

# include <string>
# include <stdio.h>
#include <fstream>
#include <fstream>
#include<sstream>
#include "pass1loader.h"
using namespace std;
ofstream outf;

// The main function is the driver function. It creates a opcode table from the opcode file.
//Then reads the program source code and geneterates the intermediate .int file

int main(int argc, char *argv[])
    {


    cout << "--------------------- Program Started  ----------------------" << endl << endl;
    outf << "--------------------- Program Started  ----------------------" << endl << endl;
    Pass1loader pass1loader;

    string programfilename= "";
    //Read the name of the input files 
    // Create the symbol table
    
    for (int i =1; i<argc; i++){ //Pass 1
        programfilename = argv[i] ;
        pass1loader. readFile(programfilename);
    }
    outf.open("LAYOUT.DAT");
   
    pass1loader.initializeCSAddr();
    //Pass 2
    for (int i =1; i<argc; i++){ 
        programfilename = argv[i] ;
        pass1loader.pass2Loader(programfilename);
    }

    cout <<"SYMBOL TABLE"<<endl;
    pass1loader.showSymbolTable();
    pass1loader.printMemory();
    outf.close();

    cout <<endl<<"--------------------- Program Completed ----------------------" <<endl ;
  //  char c;
   // cin >> c;
    return 1;

    }