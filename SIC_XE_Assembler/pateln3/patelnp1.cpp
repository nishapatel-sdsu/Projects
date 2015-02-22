/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This assignment implements a module that is used to 
evaluate the expressions and create a literal list.
********************************************************************/
# include<iostream>

# include <string>
# include <stdio.h>
#include <fstream>
#include <fstream>
#include "patelnopcodetable.h"
#include "patelnerr.h"
#include<sstream>
#include"pass1.h"
using namespace std;
ofstream outf;

// The main function is the driver function. It creates a opcode table from the opcode file.
//Then reads the program source code and geneterates the intermediate .int file
    
int main(int argc, char *argv[])
    {
    
    
    cout << "--------------------- Program Started  ----------------------" << endl << endl;
     outf << "--------------------- Program Started  ----------------------" << endl << endl;


    string programfilename= "";
    //Read the name of the expression file.
    if(argc <2){
        cout<<"Please enter the name of the program file"<<endl;
        cin>>programfilename;
        }
    else{
        programfilename = argv[1] ;
        }
    //extract the program file name

    int length = programfilename.length();
    int pos = 0;
      for(int i =0;i<length;i++){
          if(programfilename[i] == '.'){
               pos = i;
               break;
              }
          }
      string intfileename = "program.int";
      if(pos != 0){
           intfileename = programfilename.substr(0,pos) + ".int";
          }
     outf.open(intfileename.c_str());
     outf.setf(ios::left);

     // Pass 1 Assembler called
    Pass1Assembler pass1assembler;
    pass1assembler.init();

    // Reda the program file and assemble the program. Generate the .int file.
    pass1assembler.readprogramFile(programfilename);
 cout <<"--------------------- Program Completed ----------------------" <<endl ;
   
     outf.close();
    return 1;
   
    }