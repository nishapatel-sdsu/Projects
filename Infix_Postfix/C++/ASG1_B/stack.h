/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg1_B  C++                                          ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This module implement stack.
 ********************************************************************/



#include <iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include <sstream>

using namespace std;
//static ofstream outf;
/*=============Template class====================
 * =============Node Declaration=================
 */
template<class Type>
struct Node {
	Type data;
	Node<Type> *next;

};
/*=============Stack Class=======================
 * ============Class Declaration=================
 */
template<class Type>
class stack {
private:
	int count;
	Node<Type> *top;

public:
	stack(void);
	~stack(void);
	bool pushstack(Type datain);
	bool popstack(Type& dataout);
	bool stacktop(Type&dataout);
	bool emptystack(void);
	bool fullstack(void);
    void printStack();



};
/*
 * =============Constructor for the Class===========
 */
template<class Type>
stack<Type>::stack(void) {
	top = NULL;
	count = 0;

}
/*
 * ===========Destructor for the class=============
 */
template<class Type>
stack<Type>::~stack(void)

{
	Node<Type> *temp;

	while (top != NULL) {
		temp = top;
		top = top->next;
		delete temp;

	}
}
/*============PushStack=======================
 *This function pushes an item onto the stack
 */
template<class Type>
bool stack<Type>::pushstack(Type datain) {

	bool success;
	Node<Type> *newptr;

	if (!(newptr = new Node<Type> ))

		success = false;
	else {
		newptr->data = datain;
		newptr->next = top;
		top = newptr;
		count++;
		success = true;

	}

	return success;

}
/*=================PopStack=================
 *This function pop the item on the top of
 *the stack
 */
template<class Type>
bool stack<Type>::popstack(Type& dataout) {
	Node<Type> *dltptr;
	bool success;

	if (count == 0)
		success = false;
	else {
		dltptr = top;
		dataout = top->data;
		top = top->next;
		count--;
		delete dltptr;
		success = true;

	}
	return success;
}
/*==============StackTop=====================
 * This function retrieves the data from the
 * top of the stack without changing the stack
 */
template<class Type>
bool stack<Type>::stacktop(Type& dataout) {
	bool success;

	if (count == 0)
		success = false;
	else {
		dataout = top->data;
		success = true;
	}
	return success;

}
/*================emptystack==================
 * This function determines if a stack is empty
 */
template<class Type>
bool stack<Type>::emptystack(void) {
	return (count == 0);
}
/*==============fullstack===================
 * This function determines if stack is full
 */
template<class Type>
bool stack<Type>::fullstack(void) {
	Node<Type> *temp;

	temp = new Node<Type>;
	if (temp != NULL) {
		delete temp;
		return false;
	}
	return true;

}
template<class Type>
void stack<Type>:: printStack(){
    Node<Type> *temp;
    temp = top;
    while (temp != NULL) {
        cout<<"hello:";
        cout<< "The Data :"<<temp->data<< endl;
		//temp = top;
		temp = temp->next;
		

	}

    }
 