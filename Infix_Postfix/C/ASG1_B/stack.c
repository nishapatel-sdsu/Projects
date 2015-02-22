/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1_B  C                                      ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This implement pushStack, Pop stack,stack top
 and empty stack function.

 ********************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include "stack.h"
#include "string.h"

/*============PushStack=======================
 *This function pushes an item onto the stack
 */

int pushstack(char * datain,struct Stack *stack) {

	int success;
	struct Node *newptr;
    if(!(newptr = (struct Node*) malloc(sizeof(struct Node))))
	//if (!(newptr = new Node ))
	success = 0;
	else {
		strcpy(newptr->data, datain);
        //newptr->data = datain;
		newptr->next = stack->top;
		stack->top = newptr;
		stack->count++;
		success = 1;

	}

	return success;

}


/*=================PopStack=================
 *This function pop the item on the top of
 *the stack
 */

int popstack(char* dataout,struct Stack *stack) {
struct 	Node *dltptr;
	int success;

	if (stack->count == 0)
		success = 0;
	else {
		dltptr = stack->top;
		strcpy(dataout,stack->top->data);
		stack->top = stack->top->next;
		stack->count--;
		free(dltptr);
		success = 1;

	}
	return success;
}


/*==============StackTop=====================
 * This function retrieves the data from the
 * top of the stack without changing the stack
 */

int stacktop(char * dataout,struct Stack *stack) {
	int success;

	if (stack->count == 0)
		success = 0;
	else {
        strcpy(dataout,stack->top->data);
		dataout = stack->top->data;
		success = 1;
	}
	return success;

}

/*================emptystack==================
 * This function determines if a stack is empty
 */

int emptystack(struct Stack *stack) {
  
	if(stack->count == 0)
    return 1; 
    else 
        return 0;
}



/*================printstack==================
 * This function print stack
 */

void  printStack(struct Stack *stack){
struct  Node *temp;
    temp = stack->top;
    printf("Stack Contents: [");
    while (temp != NULL) {
        //cout<<"hello:";
       printf("%s",temp->data);
        
		
		temp = temp->next;
		

	}
    printf("]\n");

    }
 