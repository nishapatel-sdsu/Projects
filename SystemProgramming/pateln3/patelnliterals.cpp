/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class implement the Literal object.It is   ***
                  used to store the name,value,length and address ***
                  of a literal.                                   ***
********************************************************************/
# include<iostream>
# include <string>
#include<iomanip>
# include <stdio.h>
#include <fstream>
#include "patelnliterals.h"
#include "patelnerr.h"
using namespace std;

/********************************************************************
*** FUNCTION literals                                           
*********************************************************************
*** DESCRIPTION :This is the default constructor of Literals class***
*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/
literals :: literals(){

    }

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

literals :: literals(string name1, string value1,int address1, int length1) {
  
    name = name1;
    value = value1;
    address = address1;
    length = length1;
    }

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
void literals:: displayliterals()
    {
    cout<<setw(15)<<name<<setw(15)<<value<<setw(10)<<address<<setw(10)<<length;
   
    tocontinue();
    }

void literals:: displayliterals1()
    {
    
    outf<<setw(15)<<name<<setw(15)<<value<<setw(10)<<address<<setw(10)<<length;

    tocontinue();
    }


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

ostream& operator << (ostream& o,literals& s)
    {
    s.displayliterals();

    return o;
    }

ofstream& operator << (ofstream& o,literals& s)
    {
    s.displayliterals1();

    return o;
    }

