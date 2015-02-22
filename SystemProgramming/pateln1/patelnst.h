/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 1                                            ***
*** DUE DATE   : 09/19/2012                                       ***
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

	};


#endif