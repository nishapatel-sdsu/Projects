/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 1                                            ***
*** DUE DATE   : 09/19/2012                                       ***
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

	SymbolAttribute data;

	};
#endif 
