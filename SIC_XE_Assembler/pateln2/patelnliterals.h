/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class implement the Literal object.It is   ***
                  used to store the name,value,length and address ***
                  of a literal.                                   ***
********************************************************************/

# include<iostream>
# include <string>
# include <stdio.h>
using namespace std;
#ifndef Literal_H_
#define Literal_H_

class literals
    {
    private:

    public:

        /**
        ** name : The name of the literal
        **/
        string name;
         /**
        ** name : The value of the literal
        **/
        string value;
         /**
        ** name : The length of the literal
        **/
        int length;
         /**
        ** name : The address of the literal
        **/
        string address;


/********************************************************************
*** FUNCTION literals                                           
*********************************************************************
*** DESCRIPTION :This is the default constructor of Literals class***
*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/
literals();

/********************************************************************
*** FUNCTION literals                                           
*********************************************************************
*** DESCRIPTION :This is the parameterized constructor of the     ***
                 literals class. It creates a new literal object
                 and initializes its members with the passed 
                 parameters                                       ***

*** INPUT ARGS  : string name1    : The name of the literal       ***
                  string value1   : The value of the literal      ***
                  string address1 : The address of the literal    ***
                  int length1     : The length of the literal     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/
        literals(string name1, string value1,string address1, int length1);

/********************************************************************
*** FUNCTION displayliterals                                           
*********************************************************************
*** DESCRIPTION :This function is used to display the members of  ***
                 the literals object                              ***
*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/

        void displayliterals();

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

        friend ostream& operator<<(ostream& o,literals& s);

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