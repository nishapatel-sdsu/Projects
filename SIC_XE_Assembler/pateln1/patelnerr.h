/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 1                                            ***
*** DUE DATE   : 09/19/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to print the eroor.
********************************************************************/


#include <string>



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

	#endif 