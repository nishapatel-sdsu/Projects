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
#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
#include <stdlib.h>
#include <stdio.h>
#include "patelnbinarysearch.h"
#include "patelnsymbolattribute.h"
#include "patelnst.h"
#include"patelnerr.h"
using namespace std;


/********************************************************************************
*** FUNCTION readFile                                                         ***
*********************************************************************************
*** DESCRIPTION : This function is used to read the file used to              ***
create the symbol table.                                                      ***                 
*** INPUT ARGS  : string filename : The name of the file to be read           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/

void SymbolTable ::readFile(string filename)
	{
	ifstream inf;
	inf.open(filename.c_str(),ios::in);
	if (!inf) {
		cout << "can't open file";
		}
	else
		{
		string line = "";
		while (!inf.eof()) {
			getline(inf, line);
			lines.push_back(line);
			}
		}
	}

/********************************************************************************
*** FUNCTION insertData                                                       ***
*********************************************************************************
*** DESCRIPTION : This function is the wrapper functon for inserting          ***
the symbols and its arguments in symbol table.              ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/

void SymbolTable ::insertData()
	{
	vector<string>:: iterator itr;
	itr= lines.begin();
	while(itr != lines.end())
		{
		string line = *itr;
		itr++;
		validateAndInsert(line);
		}
	} 

/********************************************************************************
*** FUNCTION validateAndInsert                                                ***
*********************************************************************************
*** DESCRIPTION : This function first validates the symbol and its arguments. ***
Only valid symbols along with its argumnets are inserted in ***
in the symbol table.                                        ***                 
*** INPUT ARGS  : string line : The symbol and its attributes                 ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/

void SymbolTable ::validateAndInsert(string line)
	{

	string buffer = "";
	stringstream ss(line);
	vector<string> tokens;

	while (ss>>buffer)
		{
		tokens.push_back(buffer);
		}
	if(tokens.size() != 3)
		{
		cout<<"ERROR : invalid number of arguments in the input file : " + line <<endl;
		return;
		}
	string rflag = tokens[0];
	string value  = tokens[1];
	string symbol = tokens[2];

	bool validrflage = false;
	bool validvalue = false;
	bool validsymbol = false;

	validrflage = validateRflag(rflag,symbol);

	if(validrflage){
	      validvalue = validateValue(value,symbol);
	      if(validvalue){
			validsymbol = validateSymbol(symbol);
          }
	  }

	


	if(validrflage && validsymbol && validvalue ){
		int i_rflag = atoi(rflag.c_str());
		int iflag = 0;
		int mflag = 0;
		int i_value = atoi(value.c_str());
		int length = symbol.size();
		if(length>8)
			symbol = symbol.substr(0,8);
		if(bsttree.contains(symbol))
			{
			SymbolAttribute* sbAttr = bsttree.search(symbol);
			sbAttr->setMflag(1);
			cout<<"ERROR : symbol previously defined : " + symbol  <<endl;
			}
		else
			{
			iflag = 1;
			SymbolAttribute data(i_rflag, iflag, mflag, i_value, symbol);
			bsttree.insert(symbol ,data);
			}
		}
	}

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
void SymbolTable ::viewSymbolTable()
	{
	cout<<setw(10)<<"symbol"<<setw(10)<<"Rflag"<<setw(10)<<"Value"<<setw(10)<<"Mflag"<<setw(10)<<"Iflag"<<endl<<endl;
	bsttree.inorder();

	}

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
void SymbolTable ::createSymbolTable(string filename)
	{
	readFile(filename);
	insertData();
	}


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
void SymbolTable ::readsearchfile(string filename)
	{
	ifstream inf;
	inf.open(filename.c_str(), ios::in);
	if (!inf) {
		cout << "can't open file";
		}
	else
		{
		string symbol = "";
		while (!inf.eof()) {
			getline(inf, symbol);
			searchsymbols.push_back(symbol);
			}
		searchSymbol();
		}
	}

/********************************************************************************
*** FUNCTION searchSymbol                                                   ***
*********************************************************************************
*** DESCRIPTION : This function is used to search the symbol in the symbol    ***                 
table.it print the symbol attribute of the symbol          ***
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/
void SymbolTable ::searchSymbol()
	{
	vector<string>:: iterator itr;
	itr= searchsymbols.begin();
	cout<<setw(10)<<"symbol"<<setw(10)<<"Rflag"<<setw(10)<<"Value"<<setw(10)<<"Mflag"<<setw(10)<<"Iflag"<<endl<<endl;
	SymbolAttribute* data ;

	while(itr != searchsymbols.end())
		{
		string symbol = *itr;
		if(validateSymbol(symbol))
			{
			int length = symbol.size();
			if(length >8){
				symbol = symbol.substr(0,8);
				}
			data = bsttree.search(symbol);

			if(data!=NULL)
				cout<<setw(10)<<symbol<<setw(10)<<data->getRflag()<<setw(10)<<data->getValue()
				<<setw(10)<<data->getMflag()<<setw(10)<<data->getIflag()<<endl<<endl;
			else 
				cout<<"  ERROR - " +symbol +" not found in symbol table"<<endl<<endl;
			}
		else{
			cout<<"  ERROR - " +symbol +" is not valid "<<endl<<endl;
			}
		itr++;
		}
	} 
