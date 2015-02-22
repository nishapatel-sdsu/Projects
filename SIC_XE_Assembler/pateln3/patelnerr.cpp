/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to print the error.
********************************************************************/
#include<iostream>
#include <string>
#include<stdio.h>
#include<algorithm>
#include <sstream>
#include "patelnsymbolattribute.h"
#include "patelnst.h"

int linesPrinted = 0;
using namespace std;

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

void tocontinue(){
    linesPrinted++;
    if(linesPrinted==19){
        char m;
        cout<<"\nDo you want to continue?y/n ";
        linesPrinted=0;
        cin>>m;
        if(m=='n')
            exit(1);
        }

    }
/********************************************************************************
*** FUNCTION validateRflag                                                    ***
*********************************************************************************
*** DESCRIPTION : This function validates the RFlag value.Rflag is valid if
it is 1,True or 0,False.                                                      ***                 
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
        tocontinue();
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
    char invalidchar = ' ';
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
        cout <<"ERROR:symbol has invalid value:" +orgvalue + " Value starts with ";
        cout << firstChar;
        cout <<" which is not valid: "+symbol<<endl;
        tocontinue();

        }

    // Check if the other characters are 0-9
    if(isValid){

        for(int i=0; i<value.length();i++){
            if( !(value[i] >= '0' && value[i] <= '9')){
                isValid = false;
                invalidchar = value[i];
                cout <<"ERROR:Symbol has invalid value: " +orgvalue + " Value has ";
                cout << invalidchar;
                cout <<" which is not valid : "+ symbol<<endl;
                tocontinue();
                break;
                }
            }
        }


    return isValid;
    }

/********************************************************************
*** FUNCTION validateSymbol                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to validate a symbol.     ***
A symbol is valid if                                              ***
- starts with a letter (A..Z, a..z).                              ***
- followed by letters (A..Z, a..z),                               ***
digits (0..9),and the colon (:).                                  ***
- maximum of 16 characters in length                              ***
*** INPUT ARGS  : string symbol : The symbol to be validated      ***
*** OUTPUT ARGS : A boolean value                                 ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a boolean value either true or false    ***
********************************************************************/
bool validateSymbol(string symbol)
    {
    char invalidchar = ' ';
    bool isValid = true;
    for(int i=0;i<symbol.length();i++)
        {                               
        symbol[i]=tolower(symbol[i]);
        }

    int length = symbol.size();
    if(length > 16)
        {
        isValid = false;	
        cout <<"ERROR:Length of the symbol is greater than 16 : " +symbol  <<endl;
        tocontinue();
        }

    else if(!(symbol[0]>= 'a' && symbol[0]<= 'z')){
        invalidchar = symbol[0];
        cout <<"ERROR:Symbol start with " ;
        cout << invalidchar ;
        cout <<" It must start with A-Za-z : "	+ symbol	<<endl;
        tocontinue();
        isValid = false;
        }

    else {	
        for(int i = 0; i<symbol.length(); i++)
            {
            if(!((symbol[i]>= 'a' && symbol[i]<= 'z') ||(symbol[i]>= '0' && symbol[i]<= '9') ||(symbol[i] == ':')))
                {
                invalidchar = symbol[i];
                cout <<"ERROR : Symbol contains the char ";
                cout <<invalidchar;
                cout <<" which is not valid. it contain only A-Za-z0-9,':' : " +symbol  <<endl;
                isValid = false;
                tocontinue();
                break;
                }

            }
        }
    return isValid;
    }

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

int getintValue(string symbol)
    {
    int value = 0;
    char firstChar = symbol[0];
    if( firstChar == '-' || firstChar == '+' )
        {
        int length = symbol.length(); //  
        symbol = symbol.substr(1, length-1 );
        value = atoi(symbol.c_str());
        if(firstChar == '-')
            {
            value = -value;
            }
        }
    else
        {
        value = atoi(symbol.c_str());
        }

    return value;
    }


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

bool isconst(string symbol)
    {
    bool isValid = true;
    // Check if the first Char is '-' or '+' . Then check if it is 0-9. If it is not than it is invalid.
    char firstChar = symbol[0];

    if( firstChar == '-' || firstChar == '+' ){

        int length = symbol.length(); //  
        symbol = symbol.substr(1, length-1 );	//
        //isValid = true;
        }

    for(int i=0; i<symbol.length();i++){
        if( !(symbol[i] >= '0' && symbol[i] <= '9')){
            isValid = false;
            break;
            }
        }
    return isValid;
    }


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

int calculateValue(string symbol, SymbolTable &symboltable )
    {
    int value = 0;
    if(isconst(symbol))  //check to see if the symbol is a number
        {
        value = getintValue(symbol);
        }
    else
        {
        if(symbol.length() > 0){
            SymbolAttribute* data = symboltable.searchSymbol(symbol); // Fetch the symbol vale from the symbol table
            if(data!=NULL)
                {
                value = data->getValue();
                }
            else {
                throw symbol;   // Throw an exception if the symbol is not found in the symbol table
                }
            }
        }
    return value;
    }
/********************************************************************
*** FUNCTION calculateValue                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to calculate the combine 
value for the two symbol                                          ***
*** INPUT ARGS  : string symbol1 : The first operand              ***
string symbol2 : The second operand                               ***
char op : Denoting '+' or '-'                                     ***
SymbolTable &symboltable : The reference to                       ***
the symbol table                                                  ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a integer value of the combined symbols ***
********************************************************************/
int calculateValue(string symbol1,string symbol2,char op,SymbolTable &symboltable )
    {
    int value1 = 0;
    int value2 = 0;
    int value = 0;
    if(isconst(symbol1))
        {

        value1 = getintValue(symbol1);
        }
    else {
        if(symbol1.length() > 0){
            SymbolAttribute* data = symboltable.searchSymbol(symbol1); // Search the symbol1 in the symbol table
            if(data!=NULL)
                {
                value1 = data->getValue();
                }
            else throw symbol1;      // Throw an exception if the symbol is not found in the symbol table
            }
        }
    if(isconst(symbol2))
        {
        value2 = getintValue(symbol2);
        }
    else
        {
        if(symbol2.length() > 0){
            SymbolAttribute* data = symboltable.searchSymbol(symbol2); // Search the symbol3 in the symbol table
            if(data!=NULL)
                {
                value2 = data->getValue();
                }
            else throw symbol2;     // Throw an exception if the symbol is not found in the symbol table
            }
        }
    //cout<<symbol1<<":"<<value1<<":"<<symbol2<<":"<<value2<<endl;
    if(op == '+')
        {
        value = value1 + value2;
        }
    else if (op == '-')
        {
        value =value1 - value2;
        }

    return value;
    }


/********************************************************************
*** FUNCTION calculateRflag                                       ***
*********************************************************************
*** DESCRIPTION : This function is used to calculate the RFlag  
for the symbol                                                    ***
*** INPUT ARGS  : string symbol : The symbol whose value
is to be calculated                                               ***
SymbolTable &symboltable : The reference to                       ***
the symbol table  
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a integer Rflag of the symbol           ***
********************************************************************/

int calculateRflag(string symbol, SymbolTable &symboltable)
    {
    int rflag =0;
    if(isconst(symbol))
        {
        rflag = 0;
        }
    else
        {
        if(symbol.length() > 0){
            SymbolAttribute* data = symboltable.searchSymbol(symbol);  // Search the symbol in the symbol table
            if(data!=NULL)
                {
                rflag =data->getRflag();
                }
            else throw symbol;     // Throw an exception if the symbol is not found in the symbol table
            }
        }
    return rflag;
    }

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

int calculateRflag(string symbol1,string symbol2,char op,SymbolTable &symboltable)
    {
    int rflag = -1;
    int rflag1 = 0;
    int rflag2 = 0;
    if(isconst(symbol1))
        {
        rflag1 = 0;
        }
    else
        {
        if(symbol1.length() > 0){
            SymbolAttribute* data = symboltable.searchSymbol(symbol1); // Search the symbol1 in the symbol table
            if(data!=NULL)
                {
                rflag1 =data->getRflag();
                }
            else throw symbol1;  // Throw an exception if the symbol is not found in the symbol table
            }
        }
    if(isconst(symbol2))
        {
        rflag2 = 0;
        }
    else
        {
        if(symbol2.length() > 0){
            SymbolAttribute* data = symboltable.searchSymbol(symbol2); // Search the symbol2 in the symbol table
            if(data!=NULL)
                {
                rflag2 = data->getRflag();
                }
            else throw symbol2;    // Throw an exception if the symbol is not found in the symbol table
            }
        }
    if(op == '+')
        {
        if((rflag1 ==0) && (rflag2 == 0))   
            rflag  = 0;
        else if((rflag1 ==0) && (rflag2 == 1))
            rflag = 1;
        else if((rflag1 ==1) && (rflag2 == 0))
            rflag = 1;
        else if((rflag1 ==1) && (rflag2 == 1))   // Invalid combination
            rflag = -1;
        }
    else if(op == '-')
        {
        if((rflag1 ==0) && (rflag2 == 0))
            rflag  = 0;
        else if((rflag1 ==0) && (rflag2 == 1))   // Invalid combination
            rflag = -1;
        else if((rflag1 ==1) && (rflag2 == 0))
            rflag = 1;
        else if((rflag1 ==1) && (rflag2 == 1))
            rflag = 0;
        }
    else 
        {
        rflag = -1;
        }
    return rflag;
    }

