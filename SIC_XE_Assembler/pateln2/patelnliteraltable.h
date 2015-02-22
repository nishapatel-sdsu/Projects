/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 2                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class implement the Linked List for        ***
storing the literals.                                             ***
It provides the functionality to create and                       ***
destroy a linked. It also allows to append,                       ***
retrieve a literal from the list and display                      ***
the contents of the list                                          ***
********************************************************************/
# include<iostream>
# include <string>
#include<iomanip>
# include <stdio.h>
#include "patelnlinkedlistnode.h"
#include "patelnliterals.h"
#include"patelnerr.h"
using namespace std;
/**
* Nisha Patel
*/
// Node in the linklist

//static ofstream cout;
#ifndef Literallist_H_
#define Literallist_H_
// A template linklist class. Type is the datatype of the node and KType is the datatype of one of the keys used to order data.

template<class Type, class KType>
class Linklist
    {
    private:
        node<Type>  *s;

    public:
        Linklist();
        ~Linklist();
        void append(Type);
        bool add(node<Type> *,Type);
        int insert(Type);
        //void remove(int);
        void display();
        bool search(node<Type> **, node<Type> ** , KType);
        bool retrieve(KType ,Type &);
        //void deleteinner(node<Type> *, node<Type> *, Type*);
        //bool remove(KType , Type*);

        int count();
    };
/********************************************************************
*** FUNCTION  Linklist                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the expression file ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

// Constructor for the linklist
template <class Type,class KType>
Linklist<Type,KType>::Linklist()
    {
    s = NULL;

    }

/********************************************************************
*** FUNCTION  ~Linklist                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the expression file ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

//Destructor for the linklist
template <class Type, class KType>
Linklist<Type,KType>::~Linklist()
    {
    node<Type> *m;
    while(s!=NULL)
        {
        m = s;
        s = s ->link;
        delete m;
        }
    }

/********************************************************************
*** FUNCTION  append                                              ***
*********************************************************************
*** DESCRIPTION :The function is used to append the node literal 
                 in the list                                      ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

// Append function is used to append the node at the end of the list.
template <class Type, class KType>
void Linklist<Type,KType>::append(Type value)
    {
    node<Type> *m,*n;
    if(s == NULL)
        {
        s=new node<Type>;
        s->data = value;
        s->link = NULL;
        }

    else
        {
        m=s;
        while(m ->link != NULL)
            m = m ->link;
        n = new node<Type>;
        n->data = value;
        n->link = NULL;
        m ->link = n;
        }


    }

/********************************************************************
*** FUNCTION  insert                                         ***
*********************************************************************
*** DESCRIPTION :The function is outer wrapper function to 
insert a node in the list 
*** INPUT ARGS  :Type value                                       *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

template<class Type, class KType>
int Linklist<Type, KType>::insert(Type value)
    {
    bool statussearch;
    bool statusinsert;

    node<Type> *ppre;
    node<Type> *ploc;

    statussearch =	search(&ppre, &ploc, value.name);

    // The node will be inserted at the location so that the linklist remains ordered.

    if (statussearch)
        return 1;

    statusinsert = add(ppre,value);

    if (!statusinsert)
        return -1;
    return 0;
    }

/********************************************************************
*** FUNCTION  add                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to add a node in the list   ***
*** INPUT ARGS  :node<Type> *ppre
Type value  : The node to be inserted            *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

// Add function is the inner function called by the insert function.
template<class Type, class KType>
bool Linklist<Type,KType>::add(node<Type> *ppre,Type value)
    {
    node<Type> *p;
    if(! (p =  new node<Type>))
        return false;
    p->data = value;
    p->link = NULL;

    if(ppre == NULL)
        {
        p->link = s;
        s = p;
        }
    else
        {
        p->link = ppre->link;
        ppre->link = p;

        }
    return true;


    }

/********************************************************************
*** FUNCTION  display                                             ***
*********************************************************************
*** DESCRIPTION :The function is used to display the conents of 
the list                                         ***
*** INPUT ARGS  : -                                               *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

// Display function is used to display the link list.
template<class Type,class KType>
void Linklist<Type,KType>::display()
    {
    node<Type> *m;
    cout<<setw(15)<<"Name"<<setw(15)<<"Value"<<setw(10)<<"Address"<<setw(10)<<"Length"<<endl;
    tocontinue();
    cout<<endl;

    for(m=s;m!=NULL;m=m->link)
        cout<<m->data<<endl;
    tocontinue();
    }

/********************************************************************
*** FUNCTION  retrieve                                         ***
*********************************************************************
*** DESCRIPTION :The function is the outer wrapper function to 
search a node in the list                        ***
*** INPUT ARGS  :KType value, Type& poutdata    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns true if the node is in the list else
returns false.                                  ***
********************************************************************/

// Retrieve function is used to fetch a partuclar node form the linklist.
template<class Type, class KType>

bool Linklist<Type,KType>::retrieve( KType value, Type& poutdata){

    bool searchstatus;
    node<Type> *ppre;
    node<Type> *ploc;

    searchstatus = search(&ppre,&ploc,value);

    if(searchstatus) poutdata = ploc->data;

    return searchstatus;

    }


// Search function is used to search a particular node.

/********************************************************************
*** FUNCTION  search                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to search the node in a list***
*** INPUT ARGS  :node<Type> **ppre 
node<Type> **ploc 
KType value   *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : Returns true if the node is in the list else
returns false.                                  ***
********************************************************************/

template<class Type, class KType>
bool Linklist<Type,KType>::search(node<Type> **ppre, node<Type> **ploc, KType value)

    {
    node<Type> *p,*q;
    *ppre = NULL;
    *ploc = s;

    if (count() == 0)
        return false;

    p = NULL;

    for(q = s; q != NULL; q = q->link)
        {

        p = q;

        }

    if (value > p->data.name)
        {
        *ppre = p;
        *ploc = NULL;

        return false;
        }

    while (value > (*ploc)->data.name) {
        *ppre = *ploc;
        *ploc = (*ploc)->link;

        }
    if (value == (*ploc)->data.name)
        return true;
    else
        return false;


    }


/********************************************************************
*** FUNCTION  count                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to count the no of elements 
in the list                                      ***
*** INPUT ARGS  : -                                               *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The integer value of the number of elements 
in the list                                     ***
********************************************************************/

template<class Type, class KType>
int Linklist<Type,KType>::count()
    {
    node<Type> *t;
    int c = 0;
    for(t = s; t != NULL; t = t->link)
        c++;
    return(c);
    }



#endif 