/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to create a object to hold the  
symbol attributes 
********************************************************************/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

#ifndef SymbolAttribute_H_
#define SymbolAttribute_H_

class SymbolAttribute {

private:
    int rflag ;
    int iflag ;
    int mflag ;
    int value ;
    string symbol;

public:
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
    SymbolAttribute ();


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
    SymbolAttribute (int rflag,int iflag,int mflag,int value,string symbol);


    /********************************************************************************
    *** FUNCTION getRflag                                                        ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the Rflag.                     ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS :-                                                            ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the Rflag                                           ***
    *********************************************************************************/
    int getRflag();


    /********************************************************************************
    *** FUNCTION getIflag                                                         ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the Iflag.                     ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the Iflag                                           ***
    *********************************************************************************/
    int getIflag();


    /********************************************************************************
    *** FUNCTION getMflag                                                    ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the Mflag.                     ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the Mflag                                           ***
    *********************************************************************************/
    int getMflag();


    /********************************************************************************
    *** FUNCTION getValue                                                         ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the symbol.                    ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS :                                                             ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the int Value                                       ***
    *********************************************************************************/
    int getValue();


    /********************************************************************************
    *** FUNCTION setMflag                                                         ***
    *********************************************************************************
    *** DESCRIPTION : This function is use to set the Mflag value                 ***                 
    *** INPUT ARGS  : int mflag1:                                                 ***
    *** OUTPUT ARGS :                                                             ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : void                                                        ***
    *********************************************************************************/
    void setMflag(int mflag1);


    /********************************************************************************
    *** FUNCTION getSymbol                                                    ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the symbol.                    ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the symbol                                          ***
    *********************************************************************************/
    string getSymbol();

    };

#endif 