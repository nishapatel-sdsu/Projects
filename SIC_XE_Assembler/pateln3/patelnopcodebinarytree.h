/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module implement the Opcode Binary search tree.
********************************************************************/
#include<stdio.h>
#include <iostream>
//#include ".h"

using namespace std;
#ifndef opcodeBST_H_
#define opcodeBST_H_
class OpcodeValue {

private:
   string  mnemonic;
   int format; 
   string opcode;

  
public:
    /********************************************************************************
    *** FUNCTION SymbolAttribute                                                  ***
    *********************************************************************************
    *** DESCRIPTION : Constructor to craete a symbol attribute object             ***
    and initialize its members                                  ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : -                                                           ***
    *********************************************************************************/
   OpcodeValue ();


    /********************************************************************************
    *** FUNCTION SymbolAttribute                                                  ***
    *********************************************************************************
    ***                                                                           ***                 
    *** INPUT ARGS  :  int rflag1: The RFlag value of this symbol attribute       ***
    int iflag1: The iflag value of this symbol attribute       ***
    int mflag1: The mflag value of this symbol attribute       ***
    int value1: The symbol value of this symbol attribute      ***
    string symbol1:                                            ***
    *** OUTPUT ARGS :                                                             ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : -                                                           ***
    *********************************************************************************/
    OpcodeValue ( string  mnemonic,int format,string opcode);


    /********************************************************************************
    *** FUNCTION getmnemonic                                                      ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the mnemonic.                  ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS :-                                                            ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the mnemonic                                        ***
    *********************************************************************************/
    string getmnemonic();


    /********************************************************************************
    *** FUNCTION getformat                                                        ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the format.                    ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the format                                          ***
    *********************************************************************************/
    int getformat();


    /********************************************************************************
    *** FUNCTION getopcode                                                       ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the opcode.                    ***                 
    *** INPUT ARGS  : -                                                           ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : Returns the opcode                                           ***
    *********************************************************************************/
    string getopcode();


    

    /********************************************************************************
    *** FUNCTION setmnemonic                                                       ***
    *********************************************************************************
    *** DESCRIPTION : This function is use to set the mnemonic                  ***                 
    *** INPUT ARGS  : string mnemonic1:                                          ***
    *** OUTPUT ARGS :                                                             ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      : void                                                        ***
    *********************************************************************************/
    void setmnemonic (string mnemonic1);


    /********************************************************************************
    *** FUNCTION setformat                                                    ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the format.                    ***                 
    *** INPUT ARGS  : -    int format                                                       ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      :                                                             ***
    *********************************************************************************/
    void setformat (int format);
	/********************************************************************************
    *** FUNCTION setopcode                                                    ***
    *********************************************************************************
    *** DESCRIPTION : This function is used to get the opcode.                    ***                 
    *** INPUT ARGS  : -  string opcode                                                          ***
    *** OUTPUT ARGS : -                                                           ***
    *** IN/OUT ARGS : -                                                           ***
    *** RETURN      :       void                                                      ***
    *********************************************************************************/
    void setopcode(string opcode);

    };

struct OpNode {
    string key;
    OpNode *left;
    OpNode *right;
    //string data;

    OpcodeValue data;

    };
class OpBST {
    OpNode *tree;
    int inordercount ;
    bool inorderstop;
    // function declaration
    void BST_insert(OpNode * &root, OpNode *newptr);
    void BST_inorder(OpNode *root);
    void process(OpNode *root);
    OpNode* BST_search(OpNode *root, string key);
    void destroy(OpNode *root);
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
    OpBST(void);

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
    ~OpBST();

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
    bool insert(string, OpcodeValue);



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

    OpcodeValue* search(string);

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