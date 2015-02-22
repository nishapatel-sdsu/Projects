/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1  C++                                          ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This module convert Infix  string too PostFix and
 convert postfixnotation to evaluate.
 ********************************************************************/



#include<stdio.h>
#include<iostream>
#include<sstream>
#include<fstream>
#include "infixtopostfix.h"
#include "stack.h"
static ofstream outf;


/********************************************************************
 *** FUNCTION InfixToPostFix                                      ***
 *********************************************************************
 *** DESCRIPTION : This is the constructor for the  sort          ***
 *** INPUT ARGS  :- string filename                                ***
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : -                                               ***
 ********************************************************************/

InfixToPostFix :: InfixToPostFix(string fileName){
   
    this->fileName = fileName;
    }


/********************************************************************
 *** FUNCTION operatorf                                            ***
 *********************************************************************
 *** DESCRIPTION : This function check the operator                ***
 *** INPUT ARGS  :- char c                                         ***
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : -  boolean                                      ***
 ********************************************************************/

bool  InfixToPostFix :: operatorf(char c){

    if(c=='+' || c == '*' || c == '-' || c== '/')
        {
        return true;
        }

    else
        return false;
    }

/********************************************************************
 *** FUNCTION prority                                            ***
 *********************************************************************
 *** DESCRIPTION : This function check the prority for the         ***
 operator                                                          ***
 *** INPUT ARGS  :- char c                                         ***
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : -  boolean                                      ***
 ********************************************************************/
int InfixToPostFix :: prority(char c){

    if( c== '+' || c == '-')
        {
        return 1;
        }
    else if( c== '*' || c == '/')
        {
         return 2;
        }
    else
        return -1;
    }


/********************************************************************
 *** FUNCTION infixtopostfix                                            ***
 *********************************************************************
 *** DESCRIPTION : This function convert infix string to postfix   ***
 string.                                                           ***
 *** INPUT ARGS  :- string                                         ***
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : - postfix string                                ***
 ********************************************************************/

string InfixToPostFix ::  infixtopostfix(string &formula)
    {
    stack<char> mystack;
    string postfix = "";
    int valLoop = 0;
    char token = ' ';
    
	cout <<"The formula length is "<< formula.length() << "\n";
    for( valLoop = 0; valLoop<formula.length(); valLoop++)
        {
        token = formula[valLoop];

        if(token == ' ')
            continue;
        if(token == '\n')
			continue;
		if(token == '\r')
			continue;

// check it is open parenthesis
        if(token == '(')

            mystack.pushstack(token);
        // check it is close parenthesis
        else if(token == ')')
            {
            mystack.popstack(token);
            while(token != '(')
                {
                postfix.append(1, token);
				mystack.popstack(token);
                }
            }

        // check if it is a operator

        else if(operatorf(token)){
            char toptoken;
            mystack.stacktop(toptoken);
            			while (!mystack.emptystack()
					&& (prority(token) <= prority(toptoken))) {

                        char tokenout;
                        mystack.popstack(tokenout);
                            postfix.append(1,tokenout);
                            mystack.stacktop(toptoken);
                            }

                        mystack.pushstack(token);
        
            }
        else {

            postfix.append(1, token);
            }
      
        }
     while (!mystack.emptystack()) {
		mystack.popstack(token);
		postfix.append(1, token);
	}
    return  postfix;
    }
/********************************************************************
 *** FUNCTION calculate                                           ***
 *********************************************************************
 *** DESCRIPTION : This function calculate the value.              ***
 evaluate.                                                         ***
 *** INPUT ARGS  :- string operand1, char operatorc,               ***
                    string operand2                                ***
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : -  integer value                                ***
 ********************************************************************/

int   InfixToPostFix :: calculate(string operand1, char operatorc, string operand2){


    int result = 1;
	int opera1 ;
	int opera2;
	stringstream ss1(operand1);
    ss1 >> opera1;

    stringstream ss2(operand2);
        ss2 >> opera2;

	if (operatorc == '+') {
		result = (opera1 + opera2);
	} else if (operatorc == '-') {
		result = (opera1 - opera2);
	} else if (operatorc == '*') {
		result = (opera1 * opera2);
	} else if (operatorc =='/') {
		if(opera2 == 0) result = 0;
		else result = (opera1 / opera2);
	}

	return result;

    }

/********************************************************************
 *** FUNCTION postfixtoevaluate                                    ***
 *********************************************************************
 *** DESCRIPTION : This function convert  postfix string to        ***
 evaluate.                                                         ***
 *** INPUT ARGS  :- string                                         ***
 *** OUTPUT ARGS : -                                               ***
 *** IN/OUT ARGS : -                                               ***
 *** RETURN      : -  evaluate integer                             ***
 ********************************************************************/


    int  InfixToPostFix ::  postfixtoevaluate(string exp){
        int exprsize = exp.length();
        stack<string> mystack;
        int index = 0;
        // check the expration size
        while(index < exprsize)
            {
            char ctoken = exp[index];
            string stoken  = string(1,ctoken);
            //check operator is a token

            if(operatorf(ctoken))
                {
                string operand2;
                 string operand1;
                 mystack.popstack(operand2);
                 mystack.popstack(operand1);
                 //call calculate function

                 int value =  calculate(operand1, ctoken, operand2);

                 stringstream out;
			out << value;
			string svalue  = out.str();
			mystack.pushstack(svalue);

                }
            //check if it is a operand than push into a stack

            else
                {
                mystack.pushstack(stoken);

                }
            index = index +1;

            }
        string result;
        mystack.popstack(result);
        int finalresult;
        // convert final result string to integer
        stringstream ssres(result);
        ssres >> finalresult;
        return finalresult;

        }

 /********************************************************************************
 *** FUNCTION processInputFile                                                    ***
 *********************************************************************************
 *** DESCRIPTION : This function read the input file.                           ***                 
 *** INPUT ARGS  : None                                                         ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/

    void  InfixToPostFix :: processInputFile(){

    
	ifstream inf;
	outf.open("output.txt");
	outf << "Program started Asg1_B C++\n\n";
	outf << "Reading input file for stack opteration\n\n";
    cout << "Program started Asg1_B C++\n\n";
   cout << "Reading input file for stack opteration\n\n";
//open the input file
	inf.open(fileName);
	if (!inf) {
		outf << "can't open file";
        cout << "can't open file";
	
	}

	string formula = "";
	stack<int> elemnet;

	while (!inf.eof()) {

		getline(inf, formula);

		outf << "The infix notation: "<<formula << "\n";
        cout << "The infix notation: "<<formula << "\n";
       
//call infixtopostfix function
		string postfixnotation = infixtopostfix(formula);
	    outf << "The postfix notation is " << postfixnotation << "\n";
        cout << "The postfix notation is " << postfixnotation << "\n";
//call postfixtoevalute function
		int finalresult = postfixtoevaluate(postfixnotation);
		outf <<"The postfix evaluation is : "<<finalresult << "\n\n";
        cout <<"The postfix evaluation is : "<<finalresult << "\n\n";
	}

	outf << "Program completed";
    cout << "Program completed";
    outf.close();
    }
