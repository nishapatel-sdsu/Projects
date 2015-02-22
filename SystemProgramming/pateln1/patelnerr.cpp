/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 1                                            ***
*** DUE DATE   : 09/19/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to print the error.
********************************************************************/
#include<iostream>
#include <string>
#include<stdio.h>
#include<algorithm>

using namespace std;
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
bool validateRflag(string rflag, string symbol)
	{

	transform(rflag.begin(), rflag.end(),rflag.begin(), ::tolower);
	//cout<< "The flag is"<<rflag;

	if((rflag.compare("1")==0 )|| (rflag.compare("0")==0 )||(rflag.compare("true")==0 )|| (rflag.compare("false")==0 ))

		{
		return true;
		}
	else 
		{
		cout <<"ERROR : symbol "+ symbol + 
			" invalid RFlag: " +rflag <<endl;
		return false;
		}
	}

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
bool validateValue(string value,string symbol)
	{
	string orgvalue = value;
    if(value.length() == 0) return false;	

	bool isValid = true;

	// Check if the first Char is '-' or '+' . Then check if it is 0-9. If it is not than it is invalid.
	char firstChar = value[0];

	if( firstChar == '-' || firstChar == '+' ){

		int length = value.length(); //  
		value = value.substr(1, length-1 );	//
		isValid = true;
	}

	else if (firstChar >= '0' && firstChar <= '9') {
		  isValid = true;
		}
	else {
		    isValid = false;
		}
	
	// Check if the other characters are 0-9
	if(isValid){
	
		for(int i=0; i<value.length();i++){
		if( !(value[i] >= '0' && value[i] <= '9')){
			isValid = false;
			break;
		}
	  }
   }

    if(!isValid) 
	cout <<"ERROR : symbol "+ symbol + 
			" invalid value: " +orgvalue <<endl;

	return isValid;
	}

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
bool validateSymbol(string symbol)
	{

	bool isValid = true;
	for(int i=0;i<symbol.length();i++)
		{                               
	symbol[i]=tolower(symbol[i]);
     }

	int length = symbol.size();
		if(length > 16)
		{
		isValid = false;	
		cout <<"ERROR : The length of the symbol is greater than 16 : " +symbol  <<endl;
		}
	else if(!(symbol[0]>= 'a' && symbol[0]<= 'z')){

		cout <<"ERROR : The symbol must start with a letter: " +symbol  <<endl;
		
	isValid = false;
   }
		
	else {	
		for(int i = 0; i<symbol.length(); i++)
			{
			if(!((symbol[i]>= 'a' && symbol[i]<= 'z') ||(symbol[i]>= '0' && symbol[i]<= '9') ||(symbol[i] == ':')))
				{

				cout <<"ERROR : Symbol does not contain only letter,digit or ':' : " +symbol  <<endl;
				isValid = false;	
				break;
			}
		
		}
		}
		return isValid;
		}
	

