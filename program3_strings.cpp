//***************************************************************************************************/
//PROGRAM HEADER
/****************************************************************************************************
Name: Blaire Swaby-Clacken Z#: Z23431348
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: June 7, 2018     Due Time: 11:59 pm
Total Points: 100
Assignment 5: Strings
Description: This is a program which uses a while loop to ask users for their input. Option 1 asks the
user to enter a string ( white spaces are accepted) which then calls the palindrome function. The
palindrome function is of bool typw which takes the const string reference as its argument and test
whether it is a palindrome. If the function returns true then a statement stating that the string
is a plaindrome is displayed to the user and likewie if the palindrome returns false then a statement
is dislayed to the user that the string is not a palindrome. Option 2 asks the user the original string
which he/she would like to modify. They are then asked to enter the old substring and the new substring,
and the replace_all function is then called. This function takes three const string references. The 
original string is copied then the occurrence of old substring is located and replaced with the new 
substring and the modified string returned. The modified string is then displayed to the user. Option 3 
displays a thank you note and exit the loop. If a number is entered other than 1,2 or 3 an invalid error 
is displayed and the loop exited.
******************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

//Functions Prototype 
bool palindrome(const string &);
string replace_all(const string & original_string, const string & old_substring, const string & new_substring);

//*************************************************************************************
//Function name: palindrome
//Precondition: String was not determined whether it was a palindrome.
//Postcondition: String is determined whether it is a palindrome or not.
//Description: Function of bool return type that takes one const string reference
//argument. Checks whether a string is a palindrome or not. Return true if string is 
//palindrome and return false if it is not.
//*************************************************************************************
bool palindrome(const string & s)
{
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		if (s[i] != s[len - i - 1])
		{
			return false;
		}
	}
	return true;
}


//*************************************************************************************
//Function name: replace_all
//Precondition: Orginal string was not copied or modified.
//Postcondition: A copy of original string is modified. The old substrings are located
//and replaced with the new substring.
//Description: Function of string return type that takes three const string reference
// arguments. Copies the orginal string, finds the old substring and replaces the 
//occurence with the new substring. The modified string is returned.
//**************************************************************************************
string replace_all(const string & original_string, const string & old_substring, const string & new_substring)
{
	string copy;
	copy = original_string;
	int pos = 0;
	int o_len = old_substring.length();
	int n_len = new_substring.length();

	while ((pos = copy.find(old_substring, pos)) != -1)
	{
		copy.replace(pos, o_len, new_substring);
		pos += n_len;
	}

	return copy;
}


int main()
{
	string s, s1, s2, s3;
	int option = 0;

	while (true)
	{
		cout << "**************************************************" << endl;
		cout << "Welcome!" << endl;
		cout << "**************************************************" << endl;
		cout << "1. Palindrome-ing with Strings." << endl;
		cout << "2. String Replacement." << endl;
		cout << "3. Exit." << endl;
		cout << "**************************************************" << endl;
		cout << "Enter the number for your selection: ";
		cin >> option;

		if (option == 1)
		{
			cout << endl << "**************************************************" << endl;
			cout << "Palindrome-ing with Strings" << endl;
			cout << "**************************************************" << endl;
			cout << "Enter a string: ";
			cin.get();
			getline(cin, s);

			if (palindrome(s))
			{
				cout << "The string " << s << " is a palindrome." << endl << endl << endl;
			}
			else
			{
				cout << "The string " << s << " is not a palindrome." << endl << endl << endl;
			}
		}

		else if (option == 2)
		{
			cout << endl << "**************************************************" << endl;
			cout << "String Replacement" << endl;
			cout << "**************************************************" << endl;
			cout << "Enter the original string: " ;
			cin.get();
			getline(cin, s1);
			cout << "Enter the old substring you would like to replace: ";
			cin.get();
			getline(cin, s2);
			cout << "Enter the new substring you would like to put in place: ";
			cin.get();
			getline(cin, s3);
			cout << "The modified string is " << replace_all(s1, s2, s3) << endl << endl << endl;
		}
		else if (option == 3)
		{
			cout << "Thank you for using this program ! :) " << endl << endl;
			break;
		}
		else
		{
			cout << "Invalid input !" << endl << endl;
			break;
		}
	}
	return 0;
}