/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg1_B  C                                          ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This module convert Infix  string too PostFix and
 convert postfixnotation to evaluate.
 ********************************************************************/



#include<stdio.h>
#include"infixtopostfix.h"
#include "stack.h"
#include<stdlib.h>
#include<string.h>


/********************************************************************************
 *** FUNCTION processInputFile                                                    ***
 *********************************************************************************
 *** DESCRIPTION : This function read the input file.                           ***                 
 *** INPUT ARGS  : None                                                         ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/

FILE *rp;
void  processInputFile(char * fileName){

    
	FILE *inf;
   char  postfixnotation[100];
   int finalresult =0;
    char formula [100];
	  rp = fopen("output.txt", "w");
   printf("Program started Asg1_B C\n\n");
   fprintf(rp,"Program started Asg1_B C\n\n");
   printf("Reading input file for stack opteration\n\n");
   fprintf(rp,"Reading input file for stack opteration\n\n");

   
//open the input file
   inf = fopen(fileName, "r");
  

      if(!inf)
          {
          printf("can't open the file");
          exit(1);
          }

	
	while (fgets(formula,100,inf) != NULL) {
        if (formula[strlen(formula) - 1] == '\n') 
          formula[ strlen(formula) - 1 ] = '\0';

      printf("The infix notation: %s\n" ,formula);
      fprintf(rp, "The infix notation: %s\n" ,formula);
     
//call infixtopostfix function
		strcpy(postfixnotation, infixtopostfix(formula));
      
       printf("The postfix notation is %s\n ", postfixnotation);
       fprintf(rp,"The postfix notation is %s\n ", postfixnotation);

//call postfixtoevalute function
	finalresult = postfixtoevaluate(postfixnotation);

   printf("The postfix evaluation is: %d\n\n ",finalresult);
   fprintf(rp,"The postfix evaluation is: %d\n\n ",finalresult);
	}

   printf("Program completed");
    fprintf(rp,"Program completed");
   fclose(rp);
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

int operatorf(char c){

    if(c=='+' || c == '*' || c == '-' || c== '/')
        {
        return 1;
        }

    else
        return 0;
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

int  prority(char c){

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

char * infixtopostfix(char *formula)
    {
   
    struct Stack mystack = {0,0} ;
    char postfix[100] = "" ;
    int valLoop;
    char toptoken[] ="a";
    char token[]="a";
    char tokenout[] = "a";
    mystack.count = 0;
     
   
    valLoop = 0;
     
	
    for( valLoop = 0; valLoop<strlen(formula); valLoop++)
        {
       //if(formula[valLoop] == '1'){
         
           //}
        if( formula[valLoop] == ' ')
            continue;
        if( formula[valLoop] == '\n')
			continue;
		if( formula[valLoop] == '\r')
			continue;
            token[0]=  formula[valLoop];
           

// check it is open parenthesis
        if(token[0] == '(')
            {
           pushstack(token,&mystack);
      
            }
        // check it is close parenthesis
        else if(token[0] == ')')
            {
            popstack(token,&mystack);
            while(token[0] != '(')
                {
               
                strcat(postfix, token);
                popstack(token,&mystack);
			 
                }
            }

        // check if it is a operator

        else if(operatorf(token[0])){
            
           
            stacktop(toptoken,&mystack);
            			while (!emptystack(&mystack)
					&& (prority(token[0]) <= prority(toptoken[0]))) {

                        
                      
                           popstack(tokenout,&mystack);
                        
                           strcat(postfix, tokenout);
                          
       
                            stacktop(toptoken,&mystack);
                          
                            }

                      
                         pushstack(token,&mystack);
                      
        
            }
        else {
             strcat(postfix, token);
           
       
           
            }
      
      
        }
  
     while (!emptystack(&mystack)) {
		
         popstack(token,&mystack);
          strcat(postfix, token);
		
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

int    calculate(char * operand1, char operatorc, char *operand2){


    int result = 1;
	int opera1 ;
	int opera2;
	
    opera1 = atoi(operand1);

    opera2 = atoi(operand2);
        
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


    int    postfixtoevaluate(char * exp){
        char svalue[100] = "";
        int exprsize = 0;
        int index = 0;
        char ctoken ;
         int value = 0;
       char result[100] = "";
       int finalresult = 0;
        char operand2[100] = "";
        char operand1[100]= "";
        char stoken[2] = "a";
        struct Stack mystack = {0,0};
        
        
        // check the expration size
         exprsize= strlen(exp);
        while(index < exprsize)
            {
             ctoken = exp[index];
            stoken[0]  = ctoken;
            //check operator is a token

            if(operatorf(ctoken))
                {
                
                popstack(operand2, &mystack);
               popstack(operand1, &mystack);
                 //call calculate function

                 value =  calculate(operand1, ctoken, operand2);

               
			
			
            sprintf(svalue, "%d", value);
			
             pushstack(svalue,&mystack);
           

                }
            //check if it is a operand than push into a stack

            else
                {
              
                 pushstack(stoken,&mystack);

                }
            index = index +1;

            }
       
       
         popstack(result,&mystack);
        
        // convert final result string to integer
      
        finalresult = atoi(result);
       
        return finalresult;

        }