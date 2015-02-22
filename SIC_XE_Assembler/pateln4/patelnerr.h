/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to print the eroor.
********************************************************************/


#include <string>
#include "patelnst.h"

using namespace std;

#ifndef Eroor_H_
#define Eroor_H_


/********************************************************************************
*** FUNCTION validateRflag                                                    ***
*********************************************************************************
*** DESCRIPTION : This function validates the RFlag value.Rflag is valid if
it is 1,True or 0,False.                                    ***                 
*** INPUT ARGS  : String rflag : This is the string which would be validated  ***
*** OUTPUT ARGS : Returns a boolean value either true or false.               ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns a boolean value either true or false                ***
*********************************************************************************/
bool validateRflag(string rflag, string symbol);

/********************************************************************************
*** FUNCTION validateValue                                                    ***
*********************************************************************************
*** DESCRIPTION : This function validates the value. Value is valid if
it is signed integer value (+,–, 0..9)                      ***                 
*** INPUT ARGS  : string value : This is the value  which would be validated  ***
*** OUTPUT ARGS : A boolean value, either true or false.                      ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns a boolean value either true or false                ***
*********************************************************************************/
bool validateValue(string value,string symbol);

/********************************************************************
*** FUNCTION validateSymbol                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to validate a symbol.     ***
A symbol is valid if                            ***
- starts with a letter (A..Z, a..z).            ***
- followed by letters (A..Z, a..z),             ***
digits (0..9),and the colon (:).              ***
- maximum of 16 characters in length            ***
*** INPUT ARGS  : string symbol : The symbol to be validated      ***
*** OUTPUT ARGS : A boolean value                                 ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a boolean value either true or false    ***
********************************************************************/
bool validateSymbol(string symbol);



/********************************************************************
*** FUNCTION getintValue                                          ***
*********************************************************************
*** DESCRIPTION : This function is used to convert the number from***
                  string to int                                   ***

*** INPUT ARGS  : string symbol : The number in string format     ***
*** OUTPUT ARGS : A boolean value                                 ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a int value of the number               ***
********************************************************************/

int getintValue(string symbol);


/********************************************************************
*** FUNCTION isconst                                          ***
*********************************************************************
*** DESCRIPTION : This function is used to find if the symbol is a 
                  number or not                                   ***
                 

*** INPUT ARGS  : string symbol : The symbol to be tested         ***
*** OUTPUT ARGS : A boolean value                                 ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns true if the symbol is a number          ***
********************************************************************/

bool isconst(string symbol);

/********************************************************************
*** FUNCTION calculateValue                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to calculate the value 
for the symbol                                                    ***
*** INPUT ARGS  : string symbol : The symbol whose value
is to be calculated                                               ***
SymbolTable &symboltable : The reference to                       ***
the symbol table                                                  ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a integer value of the symbol           ***
********************************************************************/

int calculateValue(string symbol, SymbolTable &symboltable);

/********************************************************************
*** FUNCTION calculateValue                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to calculate the combine 
value for the two symbol                        ***
*** INPUT ARGS  : string symbol1 : The first operand              ***
string symbol2 : The second operand             ***
char op : Denoting '+' or '-'                   ***
SymbolTable &symboltable : The reference to     ***
the symbol table                                ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a integer value of the combined symbols ***
********************************************************************/

int calculateValue(string symbol1,string symbol2,char op,SymbolTable &symboltable);

/********************************************************************
*** FUNCTION calculateRflag                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to calculate the RFlag  
for the symbol                                  ***
*** INPUT ARGS  : string symbol : The symbol whose value
is to be calculated                             ***
SymbolTable &symboltable : The reference to     ***
the symbol table  
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a integer Rflag of the symbol           ***
********************************************************************/

int calculateRflag(string symbol, SymbolTable &symboltable);

/********************************************************************
*** FUNCTION calculateRflag                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to calculate the combine 
R flag value for the two symbol                                   ***
*** INPUT ARGS  : string symbol1 : The first operand
string symbol2 : The second operand                               ***
char op : Denoting '+' or '-'                                     ***
SymbolTable &symboltable : The reference to 
the symbol table
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a integer R flag value of the symbol    ***
********************************************************************/

int calculateRflag(string symbol1,string symbol2,char op,SymbolTable &symboltable);


/********************************************************************************
*** FUNCTION tocontinue                                                      ***
*********************************************************************************
*** DESCRIPTION : This function is used to determine if the user
                  wants to continue the program
*** INPUT ARGS  : String rflag : This is the string which would be validated  ***
*** OUTPUT ARGS : Returns a boolean value either true or false.               ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : -                                                           ***
*********************************************************************************/

void tocontinue();
#endif 