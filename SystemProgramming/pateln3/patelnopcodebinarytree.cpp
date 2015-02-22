/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module implement the Binary search tree.
********************************************************************/
#include<stdio.h>
#include<iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "patelnopcodebinarytree.h"
#include "patelnerr.h"
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

OpBST::OpBST(void) {
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
OpBST::~OpBST() {
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
void OpBST::destroy(OpNode *root)
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

void OpBST::BST_insert(OpNode * &root,OpNode *newptr) {
    OpNode *pwalk, *parent;
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
void OpBST::BST_inorder(OpNode *root) {
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
void OpBST::process(OpNode *root) {


    cout<<setw(10)<<root->data.getmnemonic()<<setw(10)<<root->data.getformat()
        <<setw(10)<<root->data.getopcode()<<endl;
    tocontinue();

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

bool OpBST::insert(string datain,OpcodeValue data) {
   OpNode *newptr;
    if (!(newptr = new OpNode))
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
void OpBST::inorder() {
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
OpNode* OpBST::BST_search(OpNode *root, string key)
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
OpcodeValue* OpBST::search(string key)
    {
    OpNode* node = BST_search(tree, key);
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
bool OpBST::contains(string key)
    {
   OpNode *node = BST_search(tree, key);
    if(node == NULL)
        {
        return false;
        }
    else
        {
        return true;
        }
    }



/********************************************************************************
*** FUNCTION OpcodeValue                                                  ***
*********************************************************************************
*** DESCRIPTION : Constructor to craete a opcode attribute object             ***
and initialize its members                                  ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : -                                                           ***
*********************************************************************************/
OpcodeValue:: OpcodeValue ()

    {

    mnemonic  = "";
    format = 0;
    opcode = "";
    
    }


/********************************************************************************
*** FUNCTION OpcodeValue                                                 ***
*********************************************************************************
 *** DESCRIPTION : parameterized Constructor use to  initialize its members   ***                 
*** INPUT ARGS  :  string  mnemonic_1                
                   int format_1,                                              ***
                   string opcode_1                                            ***
*** OUTPUT ARGS :                                                             ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : -                                                           ***
*********************************************************************************/
OpcodeValue:: OpcodeValue ( string  mnemonic_1,int format_1,string opcode_1)

    {

   mnemonic  = mnemonic_1;
    format = format_1;
    opcode = opcode_1;
    
    }
/********************************************************************************
*** FUNCTION getmnemonic                                                     ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the mnemonic.                  ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS :-                                                            ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the mnemonic                                          ***
*********************************************************************************/
string OpcodeValue:: getmnemonic()

    { 
    return mnemonic;
    }


/********************************************************************************
*** FUNCTION getformat                                                       ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the format.                     ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the format                                           ***
*********************************************************************************/
int OpcodeValue::getformat()
    { 
    return format;
    }


/********************************************************************************
*** FUNCTION getopcode                                                   ***
*********************************************************************************
*** DESCRIPTION : This function is used to get the opcode.                     ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Returns the opcode                                           ***
*********************************************************************************/
string OpcodeValue:: getopcode()
    { 
    return opcode;
    }

/********************************************************************************
*** FUNCTION setMflag                                                         ***
*********************************************************************************
*** DESCRIPTION : This function is use to set the Mflag value                 ***                 
*** INPUT ARGS  : int mflag1:                                                 ***
*** OUTPUT ARGS :                                                             ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/
//void SymbolAttribute:: setMflag(int mflag1)
//    { 
//    mflag = mflag1;
//
//    }
