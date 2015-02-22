#include<stdio.h>
#include<iostream>
#ifndef INFIX_H_
#define INFIX_H_

using namespace std;



  
class InfixToPostFix {
    private:
    string fileName;
public:
    InfixToPostFix(string);
    bool operatorf(char c);
    int prority(char c);
    string infixtopostfix(string &formula);
    int calculate(string operand1, char operatorc, string operand2);
    int postfixtoevaluate(string exp);
    void processInputFile();
    };
#endif