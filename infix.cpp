//*****************************************************************************************************************************************************************/
//PROGRAM HEADER
/******************************************************************************************************************************************************************
Name: Blaire Swaby-Clacken Z#: Z23431348
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: July 5, 2018     Due Time: 11:59 pm
Total Points: 25
Assignment 5: Module 7 - Stacks
Description: This is a program that asks the user to enters a postfix, reads the input and converts to infix using
// singly link list stack and output the expression. An error is printed to the screen if there are too many operands
// or too many operators in the postfix expression entered by the users.
*******************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "stack.h"

using namespace std;


int main()
{
	int countl = 0, counts = 0;
	Stack s;
	string operand1, operand2, optor, postfix, infix, expr;
	char answer;

	cout << "Notes: " << endl;
	cout << "1. Include one space between operands ( eg. a b c d ) ";
	cout << "and operator (eg. + -*/ ) in your input to the program." << endl;
	cout << "2. The only operators to consider are + , -, *and / ." << endl << endl;

	do {	
		countl = 0;
		counts = 0;
		cout << "Enter a postfix expression: ";
		getline(cin, postfix);
	
	    for (int i = 0; i < postfix.length(); i++)
		{
			string c = postfix.substr(i, 1);
			if (c == " ")
			{
				continue;
			}
			else if (c == "+" || c == "-" || c == "*" || c == "/")
			{
				counts++;
				operand2 = s.top();
				s.pop();
				operand1 = s.top();
				s.pop();
				expr = "(" + operand1 + " " + c + " " + operand2 + ")";
				s.push(expr);	
			}
			else
			{
				countl++;
				s.push(c);
			}

		}

		if (countl == 0 && counts >= 1)
		{
			cout << "Too many operators and not enough operands" << endl;
		}
		if (countl == counts)
		{
			cout << "Too many operators and not enough operands" << endl;
		}
		if (countl - 1 > counts)
		{
			cout << "Too many operands and not enough operators" << endl;
		}
		if (countl - 1 == counts)
		{
			infix = s.top();
			s.pop();
			cout << "The infix expression is " << infix << endl;
		
		}

		cout << endl << endl << "Would you like to convert another? [ Y for yes and N for no]: ";
		cin >> answer;
		answer = toupper(answer);
		getchar();
	} while (answer == 'Y');

	cout << "Thank You" << endl << endl;
	return 0;
}
