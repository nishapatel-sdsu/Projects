/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to create a object to hold the  
symbol attributes 
********************************************************************/
#include<stdio.h>
#include "patelnsymbolattribute.h"
# include<iostream>
# include <string>
#include<iomanip>
#include <fstream>
#include "pass1loader.h"
using namespace std;


/********************************************************************************
*** FUNCTION SymbolAttribute                                                  ***
*********************************************************************************
*** DESCRIPTION : Constructor to craete a symbol attribute object             ***
and initialize its members                                  ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : -                                                           ***
*********************************************************************************/
SymbolAttribute:: SymbolAttribute()
    {


    csect = "";
    addr = "";
    csaddr = "";
    ldaddr = "";
    length = "";
    symbol = "";
    name = "";
    }


/********************************************************************************
*** FUNCTION SymbolAttribute                                                  ***
*********************************************************************************
***                                                                           ***                 
*** INPUT ARGS  :  int rflag1: The RFlag value of this symbol attribute       ***
int iflag1: The iflag value of this symbol attribute       ***
int mflag1: The mflag value of this symbol attribute       ***
int value1: The symbol value of this symbol attribute      ***
string symbol1:                                            ***
*** OUTPUT ARGS :                                                             ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : -                                                           ***
*********************************************************************************/
SymbolAttribute:: SymbolAttribute(string name1 ,string symbol1,string csect1,string addr1,string csaddr1,string ldaddr1,string length1)
    {


    csect = csect1;
    addr = addr1;
    csaddr = csaddr1;
    ldaddr = ldaddr1;
    length = length1;
    symbol = symbol1;
    name  = name1;
    }



int  operator > (string& s, string& t)
    {
    int diff  = s.compare(t);
    if (diff > 0)
        return 1;
    else
        return 0;

    }

/********************************************************************
*** FUNCTION operator ==                                          
*********************************************************************
*** DESCRIPTION :This function is the overloaded function for the ***
== operator on string class.                      ***
*** INPUT ARGS  : - string& s : Reference to the first string     ***
operand                                         ***         
*** OUTPUT ARGS : - string& t : Reference to the second string    ***
operand                                         ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : - Returns 1 if the two strings are equal else 
returns 0.                                    ***
********************************************************************/

int operator == (string &s, string &t)
    {
    int diff  = s.compare(t);
    if (diff == 0)
        return 1;
    else
        return 0;
    }


/********************************************************************
*** FUNCTION operator <<                                          
*********************************************************************
*** DESCRIPTION :This function is the overloaded function for the ***
<< operator on string class.                     ***
*** INPUT ARGS  : - ostream& o : Reference to the first string    ***
operand                                         ***         
*** OUTPUT ARGS : - literals& s : Reference to the literal        ***
to be outputted                                 ***

*** IN/OUT ARGS : -                                               ***
*** RETURN      : - Returns the reference to the stream           ***
********************************************************************/

//Overloaded << operator for student structure

ostream& operator << (ostream& o,SymbolAttribute& s)
    {
    s.displayliterals();

    return o;
    }

ofstream& operator << (ofstream& o,SymbolAttribute& s)
    {
    s.displayliterals1();

    return o;
    }
void SymbolAttribute:: displayliterals()
    {

    cout<<left<<setw(10)<<csect<<setw(10)<<symbol
        <<setw(10)<<addr<<setw(10)<<csaddr
        <<setw(10)<<ldaddr<<setw(10)<<length<<endl;


    tocontinue();
    }

void SymbolAttribute:: displayliterals1()
    {

    cout<<left<<setw(10)<<csect<<setw(10)<<symbol
        <<setw(10)<<addr<<setw(10)<<csaddr
        <<setw(10)<<ldaddr<<setw(10)<<length<<endl;

    tocontinue();
    }

