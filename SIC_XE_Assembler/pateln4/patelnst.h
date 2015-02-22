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
#include <vector>
#include "patelnbinarysearch.h"

using namespace std;
extern ofstream outflst;

#ifndef SymbolTable_H_
#define SymbolTable_H_
class SymbolTable
    {
    vector<string>lines;
    BST bsttree;
    vector<string>searchsymbols;
    void searchSymbol();
    void readFile(string fileName);
    void insertData();
    void validateAndInsert(string line);

    public:
        SymbolTable();
/********************************************************************************
*** FUNCTION searchSymbol                                                   ***
*********************************************************************************
*** DESCRIPTION : This function is used to search the Symbol in symbol table  ***                 

*** INPUT ARGS  : -  string symbol : The symbol to search                     ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : The symbol in the symbol tree                               ***
                                                               
*********************************************************************************/


        SymbolAttribute* searchSymbol(string symbol);
        /********************************************************************************
        *** FUNCTION  createSymbolTable                                             ***
        *********************************************************************************
        *** DESCRIPTION : This is a wrapper function.It is read the symbole file and  ***
        then insert the data in the symbole table.                  ***                 
        *** INPUT ARGS  : string filename: The name of the file to be read            ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : void                                                        ***
        *********************************************************************************/
        void createSymbolTable(string fileName);


        /********************************************************************************
        *** FUNCTION readsearchfile                                                   ***
        *********************************************************************************
        *** DESCRIPTION : This function is used to read the search file.The search    ***         
        file contains the symbol which need to be search in the symbole table.        ***                 
        *** INPUT ARGS  : string filename : The name of the file to be read           ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : void                                                        ***
        *********************************************************************************/

        void readsearchfile(string fileName);

        /********************************************************************************
        *** FUNCTION viewSymbolTable                                                  ***
        *********************************************************************************
        *** DESCRIPTION : This is a wrapper function.It perrforms inodrder traversal  ***
        of the symbole table.                                       ***                 
        *** INPUT ARGS  : -                                                           ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : void                                                        ***
        *********************************************************************************/

        void viewSymbolTable();

        /********************************************************************************
        *** FUNCTION calculaterflag                                                   ***
        *********************************************************************************
        *** DESCRIPTION : This function is used to calculate the rflag value          ***                 
        *** INPUT ARGS  : -  string rflag : The rflag as a string                     ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : Return 1 if rflag is true/1 or returns 0 if rflag is        ***
                  false/0                                                
        *********************************************************************************/

        int calculaterflag(string rflag);

        void insertSymbol(string symbol,SymbolAttribute &data);

    };


#endif