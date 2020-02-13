//**********************************************************************************************************************************************************/
//PROGRAM HEADER
/***********************************************************************************************************************************************************
Name: Blaire Swaby-Clacken Z#: Z23431348
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: July 23, 2018     Due Time: 11:59 pm
Total Points: 25
Assignment 8: Module 10 - Recursion
Description: This is a program that prompts the user for a string and test whether it is a palindrome as well as prints the string in reverse twice.
It was three functions. palindrome which uses recursion to test whether the string is a plaindrome. printReversel which uses recursion to print the string 
in reverse and printIterReversel which prints the string in reverse without the use of recursion.
************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std; 

bool palindrome(string & s);
string printReversel(string & s);
string printIterReverse(string & s);

int main()
{
	string s;
	int option = 0;

	cout << "**************************************************" << endl;
	cout << "Welcome!" << endl;
	
	while (true)
	{
		cout << "*********************************************************" << endl;
		cout << "1. Palindrome-ing and printing in reverse with strings." << endl;
		cout << "2. Exit." << endl;
		cout << "*********************************************************" << endl;
		cout << "Enter the number for your selection: ";
		cin >> option;

		if (option == 1)
		{
			cout << endl << endl << "**************************************************" << endl;
			cout << "Enter a string: ";
			cin.get();
			getline(cin, s);

			if (palindrome(s))
			{
				cout << "The string " << s << " is a palindrome." << endl;
			}
			else
			{
				cout << "The string " << s << " is NOT a palindrome." << endl;
			}

			cout << "The string, " << s << " reversed using recursion is " << printReversel(s) << "." << endl;
			cout << "The string " << s << " reversed without using recursion is " << printIterReverse(s) << "." << endl << endl << endl;
		}

		else if (option == 2)
		{
			cout << endl << "Thank you for using this program ! :) " << endl << endl;
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

//*************************************************************************************
//Function name: palindrome
//Precondition: unknown whether the string was a palindrome. 
//Postcondition: it is known whether the string is a palindrome.
//Description: has one argument which is a string passed by reference. The determines
//whether a string is a palindrome using recursion. 
//**************************************************************************************
bool palindrome(string & s)
{
	if (s.length() == 0 || s.length() == 1)
	{
		return true;
	}
	else if (s[0] != s[s.length() - 1])
	{
		return false;
	}
	else
	{
		string str = s.substr(1, s.length() - 2);
		return palindrome(str);
	}
}


//*************************************************************************************
//Function name: printReversel
//Precondition: the string was not printed in reverse.
//Postcondition: prints the string in reverse. 
//Description: has one argument which is a string passed by reference. The function 
//prints the string in reverse using recursion.
//**************************************************************************************
string printReversel(string & s)
{
	if (s.length() == 0 || s.length() == 1)
	{
		return s;
	}
	else
	{
		string s2 = s.substr(0, s.length() - 1);
		return s[s.length() - 1] + printReversel(s2);
	}
}


//*************************************************************************************
//Function name: printIterReverse
//Precondition: the string was not printed in reverse.
//Postcondition: prints the string in reverse.
//Description: has one argument which is a string passed by reference. The function
//prints the string in reverse without the use of recursion.
//**************************************************************************************
string printIterReverse(string & s)
{
	string str;
	int j = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (j == 0)
		{
			str = s[i];
		}
		else
		{
			str = str + s[i];
		}
		j++;
	}
	return str;

}