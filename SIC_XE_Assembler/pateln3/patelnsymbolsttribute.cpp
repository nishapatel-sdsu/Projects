/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to create a object to hold the  
symbol attributes 
********************************************************************/
#include<stdio.h>
#include <iostream>
#include "patelnsymbolattribute.h"
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

    rflag = 0;
    iflag = 0;
    mflag = 0;
    value = 0;
    symbol = "";
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
SymbolAttribute:: SymbolAttribute(int rflag1,int iflag1,int mflag1,int value1,string symbol1)
    {

    rflag = rflag1;
    iflag = iflag1;
    mflag = mflag1;
    value = value1;
    symbol = symbol1;
    }


/********************************************************************************
*** FUNCTION getRflag                                                        ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the Rflag.                     ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS :-                                                            ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the Rflag                                           ***
*********************************************************************************/
int SymbolAttribute:: getRflag()
    { 
    return rflag;
    }


/********************************************************************************
*** FUNCTION getIflag                                                         ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the Iflag.                     ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the Iflag                                           ***
*********************************************************************************/
int SymbolAttribute:: getIflag()
    { 
    return iflag;
    }


/********************************************************************************
*** FUNCTION getMflag                                                    ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the Mflag.                     ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the Mflag                                           ***
*********************************************************************************/
int SymbolAttribute:: getMflag()
    { 
    return mflag;
    }


/********************************************************************************
*** FUNCTION getValue                                                         ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the symbol.                    ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS :                                                             ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the int Value                                       ***
*********************************************************************************/
int SymbolAttribute:: getValue()
    { 
    return value;
    }


/********************************************************************************
*** FUNCTION getSymbol                                                       ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the symbol.                    ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the symbol                                          ***
*********************************************************************************/
string SymbolAttribute:: getSymbol()
    { 
    return symbol;
    }


/********************************************************************************
*** FUNCTION setMflag                                                         ***
*********************************************************************************
*** DESCRIPTION : This function is use to set the Mflag value                 ***                 
*** INPUT ARGS  : int mflag1:                                                 ***
*** OUTPUT ARGS :                                                             ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/
void SymbolAttribute:: setMflag(int mflag1)
    { 
    mflag = mflag1;

    }
