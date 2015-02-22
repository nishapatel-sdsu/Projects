/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This assignment implements a module that is used to 
evaluate the expressions and create a literal list.
********************************************************************/
# include<iostream>
# include <string>
# include <stdio.h>
#include "patelnst.h"
#include <fstream>
#include "patelnexp.h"
#include "patelnliterals.h"
#include "patelnerr.h"
#include<sstream>
using namespace std;

// The main function is the driver function which creates the link list and demonstrates the  insert,add,remove,append and display function on the link list.
int main(int argc, char *argv[])
    {

    cout << "--------------------- Program Started  ----------------------" << endl << endl;

    string searchfilename = "";
    //Read the name of the expression file.
    if(argc <2){
        cout<<"Please enter the name of search file"<<endl;
        cin>>searchfilename;
        }
    else{
        searchfilename = argv[1] ;
        }
    SymbolTable symboltable;
    Linklist<literals,string> literalist;
    ExpressTable express (symboltable,literalist);

    string filename = "SYMBOLS.DAT";
    cout <<"----  Step 1 : ------ START : SYMBOL TABLE CREATION -----"<<endl;
    symboltable.createSymbolTable(filename);
    cout <<"\n------ COMPLETE : SYMBOL TABLE CREATION  --------------"<<endl;
    tocontinue();
    //cout <<"------ Step 2 : ----- START : Read Expression ------------"<<endl <<endl;
    express.readexpfile(searchfilename);
    //symboltable.readsearchfile(searchfilename);
    cout <<"\n------------- COMPLETE : Read Expression  ---------------"<<endl;
    tocontinue();
    cout <<"---  Step 3 : ----  START : INORDER TRAVERSAL  ----------"<<endl;
    symboltable.viewSymbolTable();
    cout <<"\n----------   COMPLETE : INORDER TRAVERSAL -------------"<<endl;
    tocontinue();
    cout <<"---  Step 4: ----  START : EVALUATE EXPRESSION  ----------"<<endl;
    express.evaluateExpression();
    cout <<"\n---------    COMPLETE : EVALUATE EXPRESSION  ----------"<<endl;
    cout <<"---  Step 5: ----  START : LITERALIST DISPLAY  ----------"<<endl;
    tocontinue();
    literalist.display();
    cout <<"\n-----------  COMPLETE : LITERALIST DISPLAY  ----------"<<endl <<endl;
    cout <<"--------------------- Program Completed ----------------------" <<endl ;
   
    return 1;
    }