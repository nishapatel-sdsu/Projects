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
extern ofstream outf; // output file
extern ofstream outflst;

// Node in the linklist


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
        bool sequentialsearch(node<Type> **, KType);
         void display();
         int count();
        bool retrievedata( KType, Type&);
        node<Type> * getrootNode();
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
    outflst<<setw(15)<<"Name"<<setw(15)<<"Value"<<setw(10)<<"Address"<<setw(10)<<"Length"<<endl;
    tocontinue();
    cout<<endl;
    //outf <<endl;

    for(m=s;m!=NULL;m=m->link){
        cout<<m->data<<endl;
        outflst<<m->data<<endl;
        }
    tocontinue();
    }

template<class Type, class KType>

bool Linklist<Type,KType>::retrievedata( KType value, Type& poutdata){

    bool searchstatus;
    
    node<Type> *ploc;

    searchstatus = sequentialsearch(&ploc,value);

    if(searchstatus) poutdata = ploc->data;

    return searchstatus;

    }
template<class Type, class KType>
bool Linklist<Type,KType>::sequentialsearch(node<Type> **ploc, KType value)

    {
      *ploc = s;

    if (count() == 0)
        return false;

    while ((*ploc) != NULL) {
        
        if (value == (*ploc)->data.name)
                        return true;
        *ploc = (*ploc)->link;

        }
    return false;
}

template<class Type, class KType>
node<Type>  * Linklist<Type,KType>::  getrootNode(){

      return s;
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