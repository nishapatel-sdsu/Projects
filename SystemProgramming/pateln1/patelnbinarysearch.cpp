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
#include<iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "patelnsymbolattribute.h"
#include "patelnnode.h"
#include "patelnbinarysearch.h"
using namespace std;

/********************************************************************
*** FUNCTION BST                                          ***
*********************************************************************
*** DESCRIPTION : This is the constructor for the binary search   ***
tree                                           ***
*** INPUT ARGS  :-                                                ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/

BST::BST(void) {
	tree = NULL;
	inordercount = 0;
	inorderstop = false;
	}
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
BST::~BST() {
destroy(tree);
}

/********************************************************************
*** FUNCTION destroy                                         ***
*********************************************************************
*** DESCRIPTION : This is use to delete the nodes of the BST      ***
*** INPUT ARGS  :- Node *root: pointer to the Node to be deleted  ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -  void                                             ***
********************************************************************/
void BST::destroy(Node *root)
{ 
if ( root != NULL ) {
destroy( root->left ); 
destroy( root->right ); 
delete root; 
root = NULL;
}
return;
	}
/********************************************************************
*** FUNCTION BST_insert                                           ***
*********************************************************************
*** DESCRIPTION : This function is used to insert the node in the ***
tree                                           ***
*** INPUT ARGS  :Node * &root: The reference for the pointer to   ***
the root of the BST                *** 
Node *newptr: The pointer of the new node to     ***
be inserted                        ***          
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void BST::BST_insert(Node * &root, Node *newptr) {
	Node *pwalk, *parent;
	if (root == NULL) {
		root = newptr;
		} else {
			pwalk = root;
			while (pwalk != NULL) {
				parent = pwalk;
				if (newptr->key < pwalk->key)
					pwalk = pwalk->left;
				else
					pwalk = pwalk->right;
				}
			if (newptr->key < parent->key)
				parent->left = newptr;
			else
				parent->right = newptr;
		}
	return;
	}

/********************************************************************
*** FUNCTION BST_inorder                                          ***
*********************************************************************
*** DESCRIPTION :This function print the Binary tree in inorder   ***
*** INPUT ARGS  :Node * root:The ponter to the Node               *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void BST::BST_inorder(Node *root) {
	if(inorderstop) return;
	if (root != NULL) {
		BST_inorder(root->left);
		process(root);
		if(inorderstop) return;
		BST_inorder(root->right);
		}
	return;
	}

/********************************************************************
*** FUNCTION Process                                              ***
*********************************************************************
*** DESCRIPTION :This function display the data of the node       ***
*** INPUT ARGS  :Node * root: The pointer of the Node             *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void BST::process(Node *root) {
	inordercount ++;
	if(inordercount > 20)
		{
		inordercount = 0;
		cout<<"Please enter q/Q to quit or any other key to continue"<<endl;
		char c ;
		cin >> c;
		//cout << c;
		if(c == 'q' || c == 'Q'){
			inorderstop = true;
			//exit(1);
			return;
			}
		}
	if(!inorderstop){
	cout<<setw(10)<<root->data.getSymbol()<<setw(10)<<root->data.getRflag()
		<<setw(10)<<root->data.getValue()<<setw(10)<<root->data.getMflag()
		<<setw(10)<<root->data.getIflag()<<endl<<endl;
		}
	}
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

bool BST::insert(string datain,SymbolAttribute data) {
	Node *newptr;
	if (!(newptr = new Node))
		return false;
	newptr->right = NULL;
	newptr->left = NULL;
	newptr->key = datain;
	newptr->data = data;
	BST_insert(tree, newptr);
	return true;
	}

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
void BST::inorder() {
	BST_inorder(tree);
	}

/********************************************************************
*** FUNCTION BST_search                                           ***
*********************************************************************
*** DESCRIPTION :This function is used to serch symbole in the    ***
binary  search tree                              ***
*** INPUT ARGS  :Node *root:The Pointer to the Node.              *** 
string key:The Key to be search in the tree      *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Return the Pointer to the Node to be search     ***
********************************************************************/
Node* BST::BST_search(Node *root, string key)
	{
	if(root==NULL)
		{
		return NULL;
		}
	if (key<root->key){
		return BST_search(root->left,key);
		}

	else if(key> root->key)
		{
		return BST_search(root->right,key);
		}
	else 
		{
		return root;
		}
	}
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
SymbolAttribute* BST::search(string key)
	{
	Node* node = BST_search(tree, key);
	if(node == NULL)
		{
		return NULL;
		}
	else
		{
		return &(node->data);
		}
	}
/********************************************************************
*** FUNCTION contains                                             ***
*********************************************************************
*** DESCRIPTION :This function it is use to determine the if the  ***
tree contains the specified key                                   ***
*** INPUT ARGS  :string key:The Key to be search in the tree      *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns a boolean value either true or false    ***
********************************************************************/
bool BST::contains(string key)
	{
	Node *node = BST_search(tree, key);
	if(node == NULL)
		{
		return false;
		}
	else
		{
		return true;
		}
	}


