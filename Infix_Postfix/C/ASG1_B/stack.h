/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1_B  C                                      ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This the header file for stack
 ********************************************************************/

#include<stdio.h>

#ifndef STACK_H_
#define STACK_H_

//static ofstream outf;
/*=============Template class====================
 * =============Node Declaration=================
 */

struct Node {
	char data[200];
	struct Node *next;

};


struct Stack {
	
	int count;
	struct Node *top;
};

 int pushstack(char * datain,struct Stack *stack);
 void  printStack(struct Stack *stack);
int popstack(char* dataout,struct Stack *stack);
	int stacktop(char *dataout,struct Stack *stack);
	int emptystack(struct Stack *stack);
	
   
#endif
