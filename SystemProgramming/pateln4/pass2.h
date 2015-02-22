/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 11/25/2012                                      ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class inpmlement pass 2 of the assmebler. ****
This class is used to generate and list file and the object code ****
file from the intermediate file from pass1                       ****
********************************************************************/

#include <stdio.h>
#include<iostream>
#include <fstream>
#include "pass1.h"
using namespace std;

#ifndef pass2_H_
#define pass2_H_
class Pass2Assembler{

    Pass1Assembler * pass1Assembler;
/********************************************************************
*** FUNCTION  assembleformat2Objectcode                           ***
*********************************************************************
*** DESCRIPTION :The function is used to assemble the object code for 
                 format 2 instruction 
*** INPUT ARGS  :OpcodeValue* data : The opcode data              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
    string  assembleformat2Objectcode(OpcodeValue* data, string operand);
/********************************************************************
*** FUNCTION  modificationRecord                                  ***
*********************************************************************
*** DESCRIPTION :The function is used to add modification 
                 record
                 It processes the line to determine if a modification 
                 record needs to be added                         ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
   void  modificationRecord(vector<string> *tokens, string opcode, string operand,string *SmodRecords,string locttr,string progName,vector<string> *exdtokens);
 public:
     
/********************************************************************
*** FUNCTION  readprogramFile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the intermediate
                 file
                 It processes the file for Pass2 assembler. 
                 Generates the list file                          ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void readprogramFile(string filename);
/********************************************************************
*** FUNCTION  processintline                                      ***
*********************************************************************
*** DESCRIPTION :The function is used to process intermediate line 
                 It extracts the opcode,operand from
                 the line.

*** INPUT ARGS  :string progline : The line to be processed    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void processintline(string progline,string &linenum,string &locttr, string &label,string &opcode,string &operand);

 void  setPass1Assembler(Pass1Assembler * pass1);

bool searchoptab( string opcode, OpcodeValue** data);
/********************************************************************
*** FUNCTION  getExpressionValue                                  ***
*********************************************************************
*** DESCRIPTION :The function is used to add modification 
                 record
                 It processes the line to determine if a modification 
                 record needs to be added                         ***
*** INPUT ARGS  :string operand : The operand to get the value    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void getExpressionValue( string operand ,Expression * expression );
/********************************************************************
*** FUNCTION  getLiteral                                          ***
*********************************************************************
*** DESCRIPTION :The function is used to get the literal from the 
                 literal table  
                 
*** INPUT ARGS  :string operand : The operand to get the value    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
bool  getLiteral(string operand ,literals &searchliteral);

/********************************************************************
*** FUNCTION  readlstfile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the list
                 file
                 It processes the file to generate the object code 
                 Generates the objcode file                       ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
 void readlstFile(string lstfileename);
/********************************************************************
*** FUNCTION  processlstline                                      ***
*********************************************************************
*** DESCRIPTION :The function is used to process list line 
                 It extracts the opcode,operand,object code from
                 the line.

*** INPUT ARGS  :string progline : The line to be processed    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

 void  processlstline(string progline,string &linenum ,string &locttr, string &label,string &opcode,string &operand,string &objectcode);
    };
#endif