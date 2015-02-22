/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DES`CRIPTION : This module implement the Expression Evaluation.
********************************************************************/
#include<stdio.h>
#include <iostream>
#include<string>
#include<vector>
#include "patelnst.h"
#include "patelnliteraltable.h"

using namespace std;
#ifndef ExpressTable_H_
#define ExpressTable_H_
class Expression {

public: 
    string expname;
    int value;
    int relocatableFlag;
    int indirectFlag ;
    int immediateFlag ;
    int indexFlag;

    Expression();
    
    };
class ExpressTable{
    vector<string> lines;
    
    SymbolTable	*symboltable ;
    Linklist<literals,string> *literallist;

    void validateExp(string exp,Expression* expptr);
    void evaluateImmediateExp(string exp,Expression* expptr);
    void evaluateIndirectExp(string exp,Expression* expptr);
    void evaluateIndexExp(string exp,Expression* expptr);
    void evaluateSimpleSumExp(string orgexp,string exp,int indirect,int immediate, int indexed,Expression* expptr);
    void evaluateSimpleDiffExp(string orgexp,string exp,int indirect,int immediate, int indexed,Expression* expptr); 
    void  evaluateNumber(string exp , Expression* expptr);
    void evaluateSymbol(string exp , Expression* expptr);
    void  validateLiteral(string literl);
    bool checkValidExp(string exp);
    void  evaluateNumberOrSymbol(string orgexp,string exp,int indirect,int immediate, int indexed,Expression* expptr);

public:


  void  setSymboltable(SymbolTable * symboltable1);
  void setliterallist(Linklist<literals,string> *literallist1);
 void evaluatesingleExpression(string exp,Expression *);
   Linklist<literals,string>   * getliterallist();
/********************************************************************
*** FUNCTION ExpressTable                                             
*********************************************************************
*** DESCRIPTION :This is the constructor of ExpressionTable class ***
                 It assigns the references for symbol table and   ***
                 literal list                                     ***

*** INPUT ARGS  :SymbolTable &symboltable1S: The reference of     ***
                 symbol table.                                    *** 
                 Linklist<literals,string> &literalist1:The       ***
                 reference of the literal list.                   ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/
    ExpressTable();
   // ExpressTable(SymbolTable &symboltable1,Linklist<literals,string> &literalist);


/********************************************************************
*** FUNCTION  readexpfile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the expression file ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

    void readexpfile(string filename);

/********************************************************************
*** FUNCTION  evaluateExpression                                  ***
*********************************************************************
*** DESCRIPTION :The function is used to read the expression file ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
    void  evaluateAllLiterals(string exp);


    };


#endif