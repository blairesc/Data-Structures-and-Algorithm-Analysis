//Function Defintion

#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;

//*************************************************************************************
//Name: default constructor
//Precondition:  state class members was not initialized.
//Postcondition: state class members initialized with data file in bst.
//Description: stores data file into intial bst.
//*************************************************************************************
bst::bst()
{ 
	cout << "Defualt Constructor Invoked " << endl;
	string county_name;
	double population_size = 0;
	root = 0;
	string s;

	ifstream in;
	in.open("county_data-4.txt");
	while (in)
	{
		in >> county_name >> population_size;
		insert(county_name, population_size);
	}
	in.close();
}


//*************************************************************************************
//Name: destructor
//Precondition:  dynamic memory has not be de-allocated.
//Postcondition: de-allocates dynamic memory.
//Description: de-allocates dynamic memory allocated for tree.
//*************************************************************************************
bst::~bst()
{
	while (root != 0) 
	{ 
		del_name(root->county_name);
	}
}


//*************************************************************************************
//Name: empty
//Precondition:  unknown whether the tree is empty.
//Postcondition: known whether the tree is empty.
//Description: checks to see if tree is empty.
//*************************************************************************************
bool bst::empty()
{
	return (root == 0);
}

//*************************************************************************************
//Name: insert
//Precondition: county record was not entered into the bst.
//Postcondition: county record is entered into the bst.
//Description: inserts a county record into bst based on county_name. This is a helper 
//             function as it calls another function that accesses the state members. 
//*************************************************************************************
void bst::insert(const string & item, const double & population)
{
	insert(root, item, population);
}


//*************************************************************************************
//Name: insert
//Precondition: county record was not entered into the bst.  
//Postcondition: county record is entered into the bst.
//Description: inserts a county record into bst based on county_name.  
//*************************************************************************************
void bst::insert(treenode * & loc_ptr, string item, double population)
{
	if (loc_ptr == 0)
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->county_name = item;
		loc_ptr->population_size = population;
	}
	else if (loc_ptr->county_name > item)
	{
		insert(loc_ptr->lchild, item, population);
	}
	else if (loc_ptr->county_name < item)
	{
		insert(loc_ptr->rchild, item, population);
	}
	else
	{
		cout << "The item is already in the tree\n";
	}
}


//*************************************************************************************
//Name: del_name
//Precondition:  county record was not deleted.
//Postcondition: county record deleted.
//Description: deletes a county record based on county_name. This a helper function
//             as it calls another function that accesses the state members.
//*************************************************************************************
void bst::del_name(string item)
{
	del_name(root, item);
}


//*************************************************************************************
//Name: del_name
//Precondition: county record was not deleted. 
//Postcondition: county record deleted.
//Description: deletes a county record based on county_name.
//*************************************************************************************
void bst::del_name(treenode * & loc_ptr, string item)
{
	if (loc_ptr == 0)
		cout << "Item not in tree" << endl;

	else if (loc_ptr->county_name > item)
		del_name(loc_ptr->lchild, item);

	else if (loc_ptr->county_name < item)
		del_name(loc_ptr->rchild, item);

	else
	{
		treenode * ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}
}


//*************************************************************************************
//Name: search_tree
//Precondition:  unknown whether the county_name is in the bst.
//Postcondition: known whether the county_name is in the bst.
//Description: returns pointer to node with county_name.
//*************************************************************************************
treenode * bst::search_tree(treenode * loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item)
		{
			return loc_ptr;
		}
		else if (loc_ptr->county_name > item)
		{
			return search_tree(loc_ptr->lchild, item);
		}
		else
		{
			return search_tree(loc_ptr->rchild, item);
		}
	}
	else
	{
		return loc_ptr;
	}
}


//*************************************************************************************
//Name: search_tree
//Precondition:  unknown whether the county_name is in the bst.
//Postcondition: known whether the county_name is in the bst.
//Description: returns pointer to node with county_name. This is a helper function as
//             it calls another function that accesses the state members. 
//*************************************************************************************
treenode * bst::search_tree(string item)
{
	return search_tree(root, item);
}


//*************************************************************************************
//Name: inorder_succ
//Precondition:  
//Postcondition: 
//Description: return pointer to inorder successor based on county name.
//*************************************************************************************
treenode * bst::inorder_succ(treenode * loc_ptr)
{
	treenode *ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;

}

//*************************************************************************************
//Name: county_ranges
//Precondition:  
//Postcondition: 
//Description: prints all the county names to the screen between min_name and Max_name,
//             inclusive. This is a helper function as it calls another function that
//             accesses the state members.
//*************************************************************************************
void bst::county_ranges(const string min_name, const string & max_name)
{
	county_ranges(root, min_name, max_name);
}


//*************************************************************************************
//Name: county_ranges
//Precondition:  
//Postcondition: 
//Description: prints all the county names to the screen between min_name and Max_name,
//             inclusive.
//*************************************************************************************
void bst::county_ranges(treenode * & loc_ptr, const string min_name, const string & max_name)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name >= min_name && loc_ptr->county_name <= max_name)
		{
			cout << loc_ptr->county_name << ", " << loc_ptr->population_size << endl;
			if (loc_ptr->lchild != 0)
			{
				county_ranges(loc_ptr->lchild, min_name, max_name);
			}
			if (loc_ptr->rchild != 0)
			{
				county_ranges(loc_ptr->rchild, min_name, max_name);
			}
		}
	}
}


//*************************************************************************************
//Name: print_tree
//Precondition:  county record was not displayed on the screen.
//Postcondition: county record sorted by county_name is displayed on the screen.
//Description: prints each county record to the screen sorted by county_name. This is 
//             a helper function as it calls another function that accesses the state
//             members. 
//*************************************************************************************
void bst::print_tree()
{
	print_tree(root);
}


//*************************************************************************************
//Name: print_tree
//Precondition:  county record was not displayed on the screen.
//Postcondition: county record sorted by county name is displayed on the screen.
//Description: prints each county record to the screen sorted by county_name.
//*************************************************************************************
void bst::print_tree(treenode * loc_ptr)
{
	if (loc_ptr != 0)
	{
		print_tree(loc_ptr->lchild);
		cout << loc_ptr->county_name << ", " << loc_ptr->population_size << endl;
		print_tree(loc_ptr->rchild);
	}
}


//*************************************************************************************
//Name: sorted_info
//Precondition:  
//Postcondition: 
//Description: prints each county record to a file called "county_info.txt" sorted by 
//             county_name. This is a helper function as it calls another function that
//accesses the state members. 
//*************************************************************************************
void bst::sorted_info()
{
	ofstream out("county_info.txt");
	sorted_info(root, out);
	out.close();
}


//*************************************************************************************
//Name: sorted_info
//Precondition:  county record was not printed displayed to a file.
//Postcondition: county record is printed to a file.
//Description: prints each county record to a file called "county_info.txt" sorted by 
//             county_name.
//*************************************************************************************
void bst::sorted_info(treenode * loc_ptr, ofstream & out)
{
	if (loc_ptr != 0)
	{
		sorted_info(loc_ptr->lchild, out);
		out << loc_ptr->county_name << ", " << loc_ptr->population_size << endl;
		sorted_info(loc_ptr->rchild, out);
	}
}