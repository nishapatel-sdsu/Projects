/********************************************************************
 *** NAME       : NISHA PATEL                                      
 *** CLASS      : CSc 710                                          
 *** ASSIGNMENT : Asg2_B  C#                                         
 *** DUE DATE   : 09/23/2012                                       
 *** INSTRUCTOR : Dr.Shin                                          
 *********************************************************************
 *** DESCRIPTION : This module convert Infix  string too PostFix and
 convert postfixnotation to evaluate.
 ********************************************************************/

using System;
using stack;
using System.IO;
namespace Infix
{

    public class InfixtoPost
    {
        StreamWriter writer; 

        public void processInputFile(String fileName)
        {


            string line;
            
            System.IO.StreamReader file = new System.IO.StreamReader(fileName);
            writer = new StreamWriter("output.txt");


            while ((line = file.ReadLine()) != null)
            {


           Console.WriteLine("The infix notation: " + line);
           writer.WriteLine("The infix notation: " + line);


			// call infixtopostfix function
			string postfixnotation = infixtopostfix(line);
			
			 Console.WriteLine("The postfix notation is: " + postfixnotation);
             writer.WriteLine("The postfix notation is: " + postfixnotation);
			// call postfixtoevalute function
			int finalresult = postfixtoevaluate(postfixnotation);

			 Console.WriteLine("The postfix evaluation is: " + finalresult);
             writer.WriteLine("The postfix evaluation is: " + finalresult);

			

                Console.WriteLine();
                writer.WriteLine();
         }


            Console.WriteLine("Program completed");
            writer.WriteLine("Program completed");
            file.Close();
            writer.Close();

	
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
        bool operatorf(char c)
        {

            if (c == '+' || c == '*' || c == '-' || c == '/')
            {
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

        int prority(char c)
        {

            if (c == '+' || c == '-')
            {
                return 1;
            }
            else if (c == '*' || c == '/')
            {
                return 2;
            }
            else
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

        string infixtopostfix(string formula) {
		Stack mystack = new Stack();
		string postfix = "";
		int valLoop = 0;
		char token = ' ';

		string stoken = "";

        Console.WriteLine("The formula length is " + formula.Length);
		for (valLoop = 0; valLoop < formula.Length; valLoop++) {
			token = formula[valLoop];

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

				while (stoken[0] != '(') {
					postfix = postfix + stoken;
					stoken = mystack.popstack();
				}
			}

			// check if it is a operator

			else if (operatorf(token)) {
				string toptoken = "";
				toptoken = mystack.stacktop();
				while (!mystack.emptystack()
						&& (prority(token) <= prority(toptoken[0]))) {

					string tokenout;
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

        int calculate(String operand1, char operatorc, String operand2)
        {

            int result = 1;
            int opera1;
            int opera2;

            opera1 = Convert.ToInt32(operand1);

            opera2 = Convert.ToInt32(operand2);

            if (operatorc == '+')
            {
                result = (opera1 + opera2);
            }
            else if (operatorc == '-')
            {
                result = (opera1 - opera2);
            }
            else if (operatorc == '*')
            {
                result = (opera1 * opera2);
            }
            else if (operatorc == '/')
            {
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

        int postfixtoevaluate(string exp)
        {
            int exprsize = exp.Length;
            Stack mystack = new Stack();
            int index = 0;
            // check the expration size
            while (index < exprsize)
            {
                char ctoken = exp[index];
                string stoken = ctoken + "";
                // check operator is a token

                if (operatorf(ctoken))
                {
                    string operand2;
                    string operand1;
                    operand2 = mystack.popstack();
                    operand1 = mystack.popstack();
                    // call calculate function

                    int value = calculate(operand1, ctoken, operand2);

                    string svalue =  value.ToString();

                    mystack.pushstack(svalue);

                }
                // check if it is a operand than push into a stack

                else
                {
                    mystack.pushstack(stoken);

                }
                index = index + 1;

            }
            String result;
            result = mystack.popstack();
            int finalresult;
            // convert final result string to integer
            finalresult =  Convert.ToInt32(result);

            return finalresult;

        }


    }
}