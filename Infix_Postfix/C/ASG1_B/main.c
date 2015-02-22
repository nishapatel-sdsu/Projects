/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1_B  C                                      ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This is the main function. This function call 
 InputFile function.
 ********************************************************************/



#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "infixtopostfix.h"



void main(int argc, char *argv[])
    {
   // template<class Type>
    char * inputFilename ;
    char ch;
    struct Stack newstack= {0,0} ;
      int   status ;
     
    char *i = (char*) malloc(200);
    char *j = (char*) malloc(200);
    //char datapop[200];
    inputFilename =(char*) malloc(20);
     newstack.top = NULL;
    if(argc<2)
        {
                printf("Please enter the file name\n");
        scanf("%s",inputFilename);
        printf("%s", inputFilename);
        }
    else
        {
        inputFilename = argv[1];

        }
  
    /*    i="a";
      pushstack(i,&newstack);
      i="b";
      pushstack(i,&newstack);
        i="c";
      pushstack(i,&newstack);
        i="d";
      pushstack(i,&newstack);
        i="e";
      pushstack(i,&newstack);
     
     
    printStack(&newstack);
    
    
    popstack(j,&newstack);
    printf("Value popped : %s\n", j);
    printStack(&newstack);
    popstack(j,&newstack);
    printf("Value popped : %s\n", j);
    printStack(&newstack);
    popstack(j,&newstack);
    printf("Value popped : %s\n", j);
    printStack(&newstack);
     popstack(j,&newstack);
    printf("Value popped : %s\n", j);
    printStack(&newstack);
     popstack(j,&newstack);
    printf("Value popped : %s\n", j);
    printStack(&newstack);
    if(stacktop(j,&newstack)) 
      printf("Top of the stack : %s\n", j);
    else
  printf("stack is empty");
     printStack(&newstack);
     status =  emptystack(&newstack);
             printf("stack status : %d\n",status);    
   */
    processInputFile(inputFilename);
    

    
    scanf("%c" ,&ch);
   
    
    
    // char addData  = '';
   
   ////newstack.printStack();
   // //newstack.pushstack('f');
   //newstack.printStack();
   //char e;
   //newstack.popstack(e);
   //cout<<"The value remove is "<< e << endl;
   //newstack.printStack();

   //newstack.stacktop(e);
   //cout<<"Top of the element is"<< e << endl;
   //newstack.printStack();
   //newstack.emptystack();
   //newstack.fullstack();
   //// newstack.printStack();
   
  
    }