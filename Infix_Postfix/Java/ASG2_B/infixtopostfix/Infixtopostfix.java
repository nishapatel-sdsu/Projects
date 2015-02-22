/********************************************************************
 *** NAME       : NISHA PATEL                                      
 *** CLASS      : CSc 710                                          
 *** ASSIGNMENT : Asg2_B  java                                         
 *** DUE DATE   : 09/23/2012                                       
 *** INSTRUCTOR : Dr.Shin                                          
 *********************************************************************
 *** DESCRIPTION : This module convert Infix  string too PostFix and
 convert postfixnotation to evaluate.
 ********************************************************************/


package infixtopostfix;

import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Infixtopostfix {

	Writer output;
	/*
	 * =============Constructor for the Class===========
	 */
	Infixtopostfix() {
output = null;
	}

	/********************************************************************
	 *** FUNCTION operatorf 
	 ********************************************************************* 
	 *** DESCRIPTION : This function check the operator
	 *** INPUT ARGS :- char c
	 *** OUTPUT ARGS : None 
	 *** IN/OUT ARGS : None
	 **** RETURN : - boolean 
	 ********************************************************************/
	boolean operatorf(char c) {

		if (c == '+' || c == '*' || c == '-' || c == '/') {
			return true;
		}

		else
			return false;
	}

	/********************************************************************
	 *** FUNCTION prority 
	 ********************************************************************* 
	 *** DESCRIPTION : This function check the prority for the  operator 
	 *** INPUT ARGS :- char c 
	 *** OUTPUT ARGS : None
	 *** IN/OUT ARGS : None
	 *** RETURN :boolean
	 ********************************************************************/

	int prority(char c) {

		if (c == '+' || c == '-') {
			return 1;
		} else if (c == '*' || c == '/') {
			return 2;
		} else
			return -1;
	}

	/********************************************************************
	 *** FUNCTION infixtopostfix 
	 ********************************************************************* 
	 *** DESCRIPTION : This function convert infix string to postfix 
	       string.
	 ***INPUT ARGS :- string 
	 *** OUTPUT ARGS : None
	 *** IN/OUT ARGS : None
	 * RETURN : postfix string 
	 * @throws IOException 
	 ********************************************************************/

	String infixtopostfix(String formula) throws IOException {
		Stack mystack = new Stack();
		String postfix = "";
		int valLoop = 0;
		char token = ' ';

		String stoken = "";

		System.out.println("The formula length is " + formula.length());
		output.write("The formula length is " + formula.length() +"\n");
		for (valLoop = 0; valLoop < formula.length(); valLoop++) {
			token = formula.charAt(valLoop);

			if (token == ' ')
				continue;
			if (token == '\n')
				continue;
			if (token == '\r')
				continue;

			// check it is open parenthesis
			if (token == '(')

				mystack.pushstack(token + "");
			// check it is close parenthesis
			else if (token == ')') {
				stoken = mystack.popstack();

				while (stoken.charAt(0) != '(') {
					postfix = postfix + stoken;
					stoken = mystack.popstack();
				}
			}

			// check if it is a operator

			else if (operatorf(token)) {
				String toptoken = "";
				toptoken = mystack.stacktop();
				while (!mystack.emptystack()
						&& (prority(token) <= prority(toptoken.charAt(0)))) {

					String tokenout;
					tokenout = mystack.popstack();
					postfix = postfix + tokenout;
					toptoken = mystack.stacktop();
				}

				mystack.pushstack(token + "");

			} else {

				postfix = postfix + token;
			}

		}
		while (!mystack.emptystack()) {
			stoken = mystack.popstack();
			postfix = postfix + stoken;
		}
		return postfix;
	}

	/********************************************************************
	 *** FUNCTION calculate 
	 ********************************************************************* 
	 *** DESCRIPTION : This function calculate the value.evaluate. 
	 *** INPUT ARGS :- string operand1, char operatorc,string operand2 
	 *** OUTPUT ARGS : None
	 *** IN/OUT ARGS : -  None
	 *** RETURN : - integer value 
	 ********************************************************************/

	int calculate(String operand1, char operatorc, String operand2) {

		int result = 1;
		int opera1;
		int opera2;

		opera1 = Integer.parseInt(operand1);

		opera2 = Integer.parseInt(operand2);

		if (operatorc == '+') {
			result = (opera1 + opera2);
		} else if (operatorc == '-') {
			result = (opera1 - opera2);
		} else if (operatorc == '*') {
			result = (opera1 * opera2);
		} else if (operatorc == '/') {
			if (opera2 == 0)
				result = 0;
			else
				result = (opera1 / opera2);
		}

		return result;

	}

	/********************************************************************
	 *** FUNCTION postfixtoevaluate 
	 ********************************************************************* 
	 *** DESCRIPTION : This function convert postfix string to evaluate. 
	 *** INPUT ARGS : string
	 *** OUTPUT ARGS : None
	 *** IN/OUT ARGS : None
	 *** RETURN : evaluate integer 
	 ********************************************************************/

	int postfixtoevaluate(String exp) {
		int exprsize = exp.length();
		Stack mystack = new Stack();
		int index = 0;
		// check the expration size
		while (index < exprsize) {
			char ctoken = exp.charAt(index);
			String stoken = ctoken + "";
			// check operator is a token

			if (operatorf(ctoken)) {
				String operand2;
				String operand1;
				operand2 = mystack.popstack();
				operand1 = mystack.popstack();
				// call calculate function

				int value = calculate(operand1, ctoken, operand2);

				String svalue = Integer.toString(value);

				mystack.pushstack(svalue);

			}
			// check if it is a operand than push into a stack

			else {
				mystack.pushstack(stoken);

			}
			index = index + 1;

		}
		String result;
		result = mystack.popstack();
		int finalresult;
		// convert final result string to integer
		finalresult = Integer.parseInt(result);

		return finalresult;

	}

	/********************************************************************************
	 *** FUNCTION processInputFile 
	 ********************************************************************************* 
	 *** DESCRIPTION : This function read the input file.
	 *** INPUT ARGS : None
	 *** OUTPUT ARGS : None 
	 *** IN/OUT ARGS : - 
	 *** RETURN : void 
	 *********************************************************************************/

	void processInputFile(String fileName) throws IOException {
		String line;
		FileReader fin;

		fin = new FileReader(fileName);
		BufferedReader br = new BufferedReader(fin);
		output = new BufferedWriter (new FileWriter(new File("output.txt")));
		// read characters until Eof is encountered
		System.out.println();
		while ((line = br.readLine()) != null)

		{
			
			System.out.println("The infix notation: " + line);
			output.write("The infix notation: " + line + "\n");
			// call infixtopostfix function
			String postfixnotation = infixtopostfix(line);
			
			System.out.println("The postfix notation is " + postfixnotation);
			output.write("The postfix notation is " + postfixnotation + "\n");
			// call postfixtoevalute function
			int finalresult = postfixtoevaluate(postfixnotation);

			System.out.println("The postfix evaluation is : " + finalresult);
			output.write("The postfix evaluation is : " + finalresult + "\n");
			System.out.println();
			output.write("\n");

		}
		System.out.println("Program completed");
		output.write("Program completed");
		fin.close();
		output.close();// closing output file

	}

}
