//Function defintion

#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"

using namespace std;

//*************************************************************************************
//Name: default constructor
//Precondition: none.
//Postcondition: initialize state variables. Front of linked stack is set to 0.
//Description: initializes the state variables.
//*************************************************************************************
Stack::Stack()
{
	myTop = 0;
}


//*************************************************************************************
//Name: destructor
//Precondition: memory allocated was not deleted.
//Postcondition: allocated memory deleted.
//Description: de-allocates memory allocated
//*************************************************************************************
Stack::~Stack()
{
	while (!empty())
	{
		pop();
	}
}


//*************************************************************************************
//Name: empty
//Precondition: 
//Postcondition:
//Description: 
//*************************************************************************************
bool Stack::empty() const
{
	return myTop == 0;
}


//*************************************************************************************
//Name: top
//Precondition: the stack was not checked whether it is empty.
//Postcondition: the stack is checked whether it is empty.
//Description: check whether the stack is empty.
//*************************************************************************************
StackElement Stack::top() 
{
	if (empty())
	{
		exit;
	}
	else
	{
		return myTop->data;
	}
}


//*************************************************************************************
//Name: pop
//Precondition: value at the top of stack was not removed.
//Postcondition: value at the top of stack is removed.
//Description: removes value at the top of stack.
//*************************************************************************************
void Stack::pop()
{
	if (!empty())
	{
		StackNode *p = myTop;
		myTop = myTop->next;
		delete p;
	}
}


//*************************************************************************************
//Name: push
//Precondition: value was to be added to the top of stack.
//Postcondition: value is added to the top of stack.
//Description: add a value to a stack.
//*************************************************************************************
void Stack::push(StackElement & value)
{
	StackNode *p = new StackNode;

	p->data = value;
	p->next = myTop;
	myTop = p;

}