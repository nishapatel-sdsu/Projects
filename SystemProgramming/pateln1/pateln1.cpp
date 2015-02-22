/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 1                                            ***
*** DUE DATE   : 09/19/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This assignment implements a module that is used to 
maintain the synbol table for the SIC/XE assembler
********************************************************************/
# include<iostream>
# include <string>
# include <stdio.h>
#include "patelnst.h"

using namespace std;

int main(int argc, char *argv[])
	{

	cout << "--------------------- Program Started  ----------------------" << endl << endl;

	string searchfilename = "";
	if(argc <2){
		cout<<"Please enter the name of search file"<<endl;
		cin>>searchfilename;

		}
	else{
		searchfilename = argv[1] ;
		}
	SymbolTable symboltable;
	string filename = "SYMBOLS.DAT";
	cout <<"----  Step 1 : ------ START : SYMBOL TABLE CREATION -----"<<endl <<endl;
	symboltable.createSymbolTable(filename);
	cout <<"\n------ COMPLETE : SYMBOL TABLE CREATION  --------------"<<endl <<endl;
	cout <<"------ Step 2 : ----- START : SEARCH SYMBOL  ------------"<<endl <<endl;

	symboltable.readsearchfile(searchfilename);
	cout <<"\n------------- COMPLETE : SEARCH SYMBOL  ---------------"<<endl <<endl;
	cout <<"---  Step 3 : ----  START : INORDER TRAVERSAL  ----------"<<endl <<endl;

	symboltable.viewSymbolTable();
	cout <<"\n----------   COMPLETE : INORDER TRAVERSAL -------------"<<endl <<endl;

	cout <<"--------------------- Program Completed ----------------------" <<endl ;
	
	char c;
	cin >> c;
	return 1;
	}