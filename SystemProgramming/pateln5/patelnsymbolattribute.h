/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 12/07/2012                                       ***
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
extern ofstream outf; // output file
class SymbolAttribute {

private:
     


public:
    string symbol;
     string csect;
     string addr;
     string csaddr;
     string ldaddr;
     string length;
     string name;
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

     void displayliterals();

          void displayliterals1();
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
   // SymbolAttribute (int rflag,int iflag,int mflag,int value,string symbol);
    SymbolAttribute(string name,string symbol1,string csect1,string addr1,string csaddr1,string ldaddr1,string length1);


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

        friend ostream& operator<<(ostream& o,SymbolAttribute& s);
         
        friend ofstream& operator<<(ofstream& o,SymbolAttribute& s);
        /********************************************************************
*** FUNCTION operator >                                           
*********************************************************************
*** DESCRIPTION :This function is the overloaded function for the ***
                 > operator on string class.                      ***
*** INPUT ARGS  : - string& s : Reference to the first string     ***
                  operand                                         ***         
*** OUTPUT ARGS : - string& t : Reference to the second string    ***
                  operand                                         ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : - Returns 1 if first string is greater than the ***
                  second  else returns zero.                      ***
********************************************************************/

        friend int operator > ( string& , string&);

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

        friend int operator == ( string&, string&);

    };

#endif 