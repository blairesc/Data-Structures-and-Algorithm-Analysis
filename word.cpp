//Function definition

#include <iostream>
#include <string>
#include "word.h"

using namespace std;


//*************************************************************************************
//Name: default constructor
//Precondition: None.
//Postcondition: initialize state variables, front of linked list is intiallay set to 0
//               implementation of linked list.
//Description: initializes the state variables.
//*************************************************************************************
WORD::WORD()
{
	cout << "The default constructor has been called." << endl;
	front = back = 0;
}


//*************************************************************************************
//Name: explicit value constructor
//Precondition: word is not created.
//Postcondition: word is created using the argument given.
//Description: one argument of C++ type string passed by reference, of which a word is created.
//*************************************************************************************
WORD::WORD(const string & s)
{
	front = 0;
	create_list(s);
		
}


//*************************************************************************************
//Name: copy constructor
//Precondition: current object was not copied.
//Postcondition: deep copy of current object is done.
//Description: does a deep copy of current object. The overloaded assignment operator is used
// to deep copy.
//*************************************************************************************
WORD::WORD(const WORD & org)
{
	front = 0;
	*this = org;
}


//*************************************************************************************
//Name: destructor
//Precondition: memory allocated was not deleted.
//Postcondition: memory allocates is deleted.
//Description: de-allocated memory allocated.
//*************************************************************************************
WORD::~WORD()
{
	while (front != 0)
	{
		character *p = front; 
		front = front->next;
		delete p;
	}
}

//*************************************************************************************
//Name: IsEmpty
//Precondition: did not know whether the word was empty.
//Postcondition: the state of the word is known.
//Description: check if the word is empty,
//*************************************************************************************
bool WORD::IsEmpty() 
{ 
	return front == 0;
}


//*************************************************************************************
//Name: create_list
//Precondition: a list was not created.
//Postcondition: a list of the current object is created.
//Description: has one argument of constant string type passed by reference, which a 
// created a singly linked list is 
//*************************************************************************************
void WORD::create_list(const string & s) 
{
	if (front == 0)
	{
		for (int i = 0; i < s.length(); i++)
		{
			insert_back(s[i]);
		}
	}
}


//*************************************************************************************
//Name: insert_back
//Precondition: data was not added to the back of the list.
//Postcondition: data is added to the back of the list.
//Description: has one argument of constant char passed by reference which is added to
//to the back of the linked list.
//*************************************************************************************
void WORD::insert_back(const char & key) 
{
	if (front == 0)
	{
		front = new character;
		front->symbol = key;
		front->next = 0;
		back = front;
	}
	else
	{
		character *p = new character;
		p->next = 0;
		p->symbol = key;
		back->next = p;
		back = p;
	}
}

//*************************************************************************************
//Name: length
//Precondition: the lenght of the word was unknown.
//Postcondition: the length of the word is determined.
//Description: determines the length of the current object.
//*************************************************************************************
int WORD::Length()
{
	string s;
	//in>>s;

	if (front == 0)
	{
		return 0;
	}
	else
	{
		character *p = front;
		int count = 0;

		while (p != 0)
		{
			count++;
			p = p->next;
		}
		return count;
	}
}


//*************************************************************************************
//Name: operator<<
//Precondition: current object was not printed to the screen.
//Postcondition: current object is printed to the screen.
//Description: has two arguments, ostream and constant WORD, both passed by reference.
//Overloaded to print the current object with chaining.
//*************************************************************************************
ostream & operator<<(ostream & out, const WORD & Org)
{
	character *p = Org.front;
	while (p != 0)
	{
		out << p->symbol;
		p = p->next;
	}

	return out; 
}

//*************************************************************************************
//Name: operator=
//Precondition: current object did not have value assigned to it.
//Postcondition: value is assigned to current object.
//Description: one argument which is a constant string passed by reference which 
//value is assigned to the current object.
//*************************************************************************************
void WORD::operator=( const string & s) 
{
	front = 0;
	for (int i = 0; i < s.length(); i++)
	{
		insert_back(s[i]);
	}
}


//*************************************************************************************
//Name: operator=
//Precondition: value was not assigned to current object.
//Postcondition: value was assignt to current object.
//Description: one argument which is a constant WORD passed by reference which 
//value is assigned to the current object with chaining.
//*************************************************************************************
WORD & WORD::operator =(const WORD & w)
{
	if (w.front == 0)
	{
		return *this;
	}

	if (this != &w)
	{
		front = 0;
		character *p = w.front;

		while (p != 0)
		{
			insert_back(p->symbol);
			p= p->next;
		}
	}
	return *this;
} 


//*************************************************************************************
//Name: operator+
//Precondition: word was not added tp the back of current object.
//Postcondition: word is added to the back of current object.
//Description: has one argument which is a constant WORD passed by reference. overloaded
// to add word to the back of current object.
//*************************************************************************************
void WORD::operator+(const WORD & B) //CB
{
	character *p = B.front;
	while (p != 0)
	{
		insert_back(p->symbol);
		p = p->next;

	}
}  

//*************************************************************************************
//Name: IsEqual
//Precondition: did not know if two word objects were equal.
//Postcondition: determined is two word object are equal.
//Description: of bool return type and one constant WORD argument passed by reference.
//checks if two word objects are equal
//*************************************************************************************
bool WORD::IsEqual(const WORD & B) 
{
	character *p = front;
	while (p != 0)
	{
		if (p->symbol == B.front->symbol)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

