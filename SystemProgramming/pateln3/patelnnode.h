/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CS C354                                          ***
*** ASSIGNMENT : Asg 23                                           ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : Structure of the Node in the Binary search tree.Each 
node has key,value,left pointer and the right pointer.
********************************************************************/
#include<stdio.h>
#include <iostream>
#include "patelnsymbolattribute.h"

using namespace std;

#ifndef Node_H_
#define Node_H_

struct Node {
    string key;
    Node *left;
    Node *right;
    //string data;

    SymbolAttribute data;

    };
#endif 
