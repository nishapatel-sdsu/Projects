/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to create a Opcode table using 
binary search tree.
********************************************************************/
#include<stdio.h>
#include <iostream>
#include<string>
#include <vector>
#include "patelnopcodebinarytree.h"

using namespace std;

#ifndef Opcodetable_H_
#define Opcodetable_H_
class OpcodeTable
    {
    vector<string>lines;
    OpBST opbsttree;
    vector<string>searchsymbols;
 void readFile(string fileName);
    void insertData();
    void validateAndInsert(string line);

    public:

/********************************************************************************
*** FUNCTION searchOpcodeValue                                                ***
*********************************************************************************
*** DESCRIPTION : This function is used to calculate the rflag value          ***                 

*** INPUT ARGS  : -  string mnemonic : The mnemonic to search                 ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      :    OpcodeValue*                                            ***
                                                               
*********************************************************************************/


        OpcodeValue* searchOpcodeValue(string mnemonic);
        /********************************************************************************
        *** FUNCTION createOpcodeTable                                            ***
        *********************************************************************************
        *** DESCRIPTION : This is a wrapper function.It is read the opcode file and  ***
        then insert the data in the opcode table.                  ***                 
        *** INPUT ARGS  : string filename: The name of the file to be read            ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : void                                                        ***
        *********************************************************************************/
        void createOpcodeTable(string fileName);


      

        /********************************************************************************
        *** FUNCTION viewOpcodeTable                                                 ***
        *********************************************************************************
        *** DESCRIPTION : This is a wrapper function.It perrforms inodrder traversal  ***
        of the opcode table.                                       ***                 
        *** INPUT ARGS  : -                                                           ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : void                                                        ***
        *********************************************************************************/

        void viewOpcodeTable();

      
    };


#endif