//Function Definition

#include <iostream>
#include <string>
#include "BQUEUE.h"

using namespace std;

//*************************************************************************************
//Name: default constructor
//Precondition: none.
//Postcondition: initialize state variables. front is set to 0.
//Description:  initilizes state variables
//*************************************************************************************
BQUEUE::BQUEUE()
{
	front = 0;
}


//*************************************************************************************
//Name: destructor
//Precondition: memory allocated was not deleted.
//Postcondition: memory allocated is deleted.
//Description: deletes memory allocated.
//*************************************************************************************
BQUEUE::~BQUEUE()
{
	cout << "~BQUEUE has been called" << endl;
	if (!front)
	{
		return;
	}
	bqnode *p = front->next;
	while (p != front)
	{
		bqnode *q = p;
		p = p->next;
		delete q;
	}
	delete front;
	

}


//*************************************************************************************
//Name: copy constructor
//Precondition: current object was not copied.
//Postcondition: deep copy of current object is done.
//Description: does a deep copy of current object.
//*************************************************************************************
BQUEUE::BQUEUE(const BQUEUE & Org)
{
	cout << "Copy constructor is invoked." << endl;
	if (!Org.front)
	{
		return;
	}

	front = new bqnode;
	front->time = Org.front->time;
	front->next = front->prev = front;
	bqnode *p = Org.front->next;

	while (p != Org.front)
	{
		bqnode *q = new bqnode;
		q->time = p->time;
		q->next = front;
		q->prev = front->prev;
		front->prev->next = q;
		front->prev = q;
		p = p->next;
	}
}



//*************************************************************************************
//Name: Enqueue
//Precondition: data needs to be entered into the list.
//Postcondition: data is inserted at the back of the list.
//Description: has one argument of int data type which is the item to be inserted
//at the back of the list.
//*************************************************************************************
void BQUEUE::Enqueue(int item)
{
	if (front == 0)
	{
		front = new bqnode;
		front->time = item;
		front->next = front;
		front->prev = front;
	}
	else
	{
		bqnode *p = new bqnode;
		p->time = item;
		p->prev = front->prev;
		front->prev->next = p;
		p->next = front;
		front->prev = p;
	}
}

//*************************************************************************************
//Name: Dequeue
//Precondition: data from the front of the list needed to be deleted.
//Postcondition: data from the front of the list was deleted.
//Description: deletes the data from the front of the list
//*************************************************************************************
void BQUEUE::Dequeue()
{
	cout << "Dequeue function invoked." << endl;
	if (front->next == front)
	{
		delete front;
		front = 0;
	}
	if (front != 0)
	{
		bqnode *p = front;
		bqnode *back = front->prev;
		front = front->next;
		if (front != 0)
		{
			front->prev = back;
			back->next = front;
		}
		delete p;
	}
	else
	{
		cout << "Cannot deQueue because queue is empty\n";
	}
}


//*************************************************************************************
//Name: Print
//Precondition: data in the list was not displayed to the user.
//Postcondition: data in the list is displayed to the user.
//Description:  displays data in the list to the user.
//*************************************************************************************
void BQUEUE::Print()
{
	cout << "Print function invoked." << endl;
		bqnode *p = front;
		bqnode *back = front->prev;
		if (p == back)
		{
			cout << p->time << endl;
		}
		else
		{
			while (p != back)
			{
				cout << p->time << endl;
				p = p->next;
			}
			cout << p->time << endl;
		}

}