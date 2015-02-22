#include<stdio.h>

#ifndef INFIX_H_
#define INFIX_H_



    int operatorf(char c);
    int prority(char c);
    void processInputFile(char * fileName);
 char *infixtopostfix(char* formula);
   int calculate(char * operand1, char operatorc, char *operand2);
    int postfixtoevaluate(char * exp);
   
   
#endif