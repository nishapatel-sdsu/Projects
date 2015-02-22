/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSc 354                                          ***
*** ASSIGNMENT : Asg 1                                            ***
*** DUE DATE   : 09/19/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module implement the Binary search tree.
********************************************************************/
#include<stdio.h>
#include <iostream>
#include "patelnnode.h"

using namespace std;
#ifndef BST_H_
#define BST_H_

class BST {
	Node *tree;
	int inordercount ;
	bool inorderstop;
	// function declaration
	void BST_insert(Node * &root, Node *newptr);
	void BST_inorder(Node *root);
	void process(Node *root);
	Node* BST_search(Node *root, string key);
	void destroy(Node *root);
public:


	/********************************************************************
	*** FUNCTION BST                                                 ***
	*********************************************************************
	*** DESCRIPTION : This is the constructor for the binary search   ***
	tree                                           ***
	*** INPUT ARGS  :-                                                ***
	*** OUTPUT ARGS : -                                               ***
	*** IN/OUT ARGS : -                                               ***
	*** RETURN      : -                                               ***
	********************************************************************/
	BST(void);
	
/********************************************************************
*** FUNCTION ~BST                                          ***
*********************************************************************
*** DESCRIPTION : This is the destructor for the binary search   ***
tree                                           ***
*** INPUT ARGS  :-                                                ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/
	~BST();

	/********************************************************************
	*** FUNCTION insert                                              ***
	*********************************************************************
	*** DESCRIPTION :This function is wrapper function for BST_insert ***
	it's call BST_insert function                   ***
	*** INPUT ARGS  :string datain:  The Key of the Node              *** 
	SymbolAttribute data:The Value of the Node       ***         
	*** OUTPUT ARGS : -                                               ***
	*** IN/OUT ARGS : -                                               ***
	*** RETURN      :Returns a boolean value either true or false     ***
	********************************************************************/
	bool insert(string, SymbolAttribute);

	

	/********************************************************************
	*** FUNCTION inorder                                              ***
	*********************************************************************
	*** DESCRIPTION :his function is wrapper function for BST_inorder ***
	it's call BST_inorder function                   ***
	*** INPUT ARGS  :-                                                *** 
	*** OUTPUT ARGS : -                                               ***
	*** IN/OUT ARGS : -                                               ***
	*** RETURN      : void                                            ***
	********************************************************************/
	void inorder();

	/********************************************************************
	*** FUNCTION search                                               ***
	*********************************************************************
	*** DESCRIPTION :This function is wrapper function for BST_search ***
	it's call BST_search  function                   ***
	*** INPUT ARGS  :string key: The Key to be search in the tree     *** 
	*** OUTPUT ARGS : -                                               ***
	*** IN/OUT ARGS : -                                               ***
	*** RETURN      :SymbolAttribute* : The Value of the Node         ***
	********************************************************************/

	SymbolAttribute* search(string);

	/********************************************************************
	*** FUNCTION contains                                             ***
	*********************************************************************
	*** DESCRIPTION :This function it is use to determine the if the  ***
	tree contains the specified key                  ***
	*** INPUT ARGS  :string key:The Key to be search in the tree      *** 
	*** OUTPUT ARGS : -                                               ***
	*** IN/OUT ARGS : -                                               ***
	*** RETURN      : Returns a boolean value either true or false    ***
	********************************************************************/
	bool contains(string key);

	};

#endif