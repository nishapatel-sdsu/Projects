/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This structure implement the Node of the        ***
                  Linked List.                                    ***
********************************************************************/
#include <string>
#ifndef LinkedListNode_H_
#define LinkedListNode_H_

template<class Type>

struct node
    {
    Type  data;
    node *link;
    } ;



#endif 