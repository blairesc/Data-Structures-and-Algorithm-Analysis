// Function Definition

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "vlist.h"

using namespace std;

//*************************************************************************************
//Name: vlist
//Precondition: constructor has not been invoked. 
//Postcondition: count = 0, vector size is 9.
//Description: constructs an instance of a vlist object.
//*************************************************************************************
vlist::vlist()
{
	cout << "Default Constructor Invoked." << endl;
	count = 0;
	size = 9;
	vector<string> DB(size);
}

//*************************************************************************************
//Name: vlist
//Precondition: a vlist object is being passed by reference. 
//Postcondition: count = a hard copy of a vlist object has been created.
//Description: creates a hard copy of vlist object
//*************************************************************************************
vlist::vlist(const vlist & Org)
{
	cout << "Copy Constructor Invoked." << endl;
	DB = Org.DB; 
}


//*************************************************************************************
//Name: ~vlist
//Precondition: destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: deallocates memory of a vlist object.
//*************************************************************************************
vlist::~vlist()
{
	cout << "Destructor Invoked." << endl;
    DB.clear();
}


//*************************************************************************************
//Name: Is_Empty
//Precondition:  whether the vector was empty or not was not determined.
//Postcondition: it is determined whether the vector is empty or not.
//Description: returns true if vector is empty, false if not.
//*************************************************************************************
bool vlist::Is_Empty()
{
	return DB.empty();
}


//*************************************************************************************
//Name: Search
//Precondition:  unknown whether item is in vector o not.
//Postcondition: it is known whether or  not the item is in the vector.
//Description: uses a vector iterator to search vector for item. If item is found 
//             the iterator is return and a message stating that it was found is printed
//             If it was not a message stating that it was not found is printed.
//*************************************************************************************
vector<string>::iterator vlist::Search(const string & key)
{	if (!Is_Empty())	{		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)		{			if ((*i) == key)			{				cout << "Item, " << key << ",Found." << endl;				return i;			}		}		cout << "Item " << key << " Not Found." << endl;		return DB.end();
	}
	else
	{
		cout << "Vector is empty, can not be searched." << endl;
	}
}


//*************************************************************************************
//Name: Insert
//Precondition:  item entered by user is to be inserted into vector.
//Postcondition: item is inserted into the vector.
//Description: inserts item into the vector.
//*************************************************************************************
void vlist::Insert(const string & key)
{
	DB.push_back(key);
	count++;
	sort(DB.begin(), DB.end());

}

//*************************************************************************************
//Name: Remove
//Precondition:  item in vector is to be removed.
//Postcondition: if item is in vector it is removed.
//Description: item to be removed is searched for and if found is removed.
//*************************************************************************************
void vlist::Remove(const string & key)
{
	if (!Is_Empty())
	{
		vector<string>::iterator i = Search(key);
		DB.erase(i);
		count--;
		cout << "Item Removed." << endl;
	}
	else
	{
		cout << "Item cannot be removed, vector is already empty." << endl;
	}
}


//*************************************************************************************
//Name: Print
//Precondition:  items in the vector was not displayed.
//Postcondition: items in the vector has been displayed.
//Description: displays the items in the vector to the user.
//*************************************************************************************
void vlist::Print()
{
	if (!Is_Empty())
	{
	    for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
		{
		  cout << (*i) << endl;
		}
	}
	else
	{
		cout << "This vector is empty" << endl;
	}

}
