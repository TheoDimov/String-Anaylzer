#include <iostream>
#include "colors.h"
#include <stdio.h>
#include <string.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//			Function Declarations				//
//////////////////////////////////////////////////////////////////////////

void CountCharacters (char* a, int size);
/* Precondition:  char* a is pointing to the input and size is intialized to the length of the input.
 * Postcondition: Outputs the first set of statistical measurements concerning the number of alphanumber types and their frequencies.
 * Parameters: 
 *	char* a: a pointer to the inputed text.
 *	size: the size of the input.
 */

void CountWordsnTED(char* a, int size);
/* Precondition: char* a is point to the input and size is intialized to the length of the input. 
 * Postcondition: Outputs the second set of statistical measurements concerning the number of words + number of words with
 *               'ted' and their frequencies
 * Parameters:
 *	char* a: a pointer to the inputed text.
 *	size: the size of the input. 
 */

void CountSequence (char* a, int size);
/* Precondition: char* a is point to the input and size is intialized to the length of the input. 
 * Postcondition: Outputs the last of the statistical measurements concerning the number of 'ted' sequences and their frequency to
 *		 the other amount of three character sequences.
 * Parameters:
 *	char* a: a pointer to the inputed text.
 *	size: the size of the input. 
 */


//////////////////////////////////////////////////////////////////////////
//			    Main Function				//
//////////////////////////////////////////////////////////////////////////

int main()
{

	// String declaration
	string S;
	// Decision string statement for re-do
	char  ans_prime;	

	//Loop for re-inputing sequence at end
	do
	{
		//Fancy Introduction:
		cout << BOLD(FBLU("\n\n\t///////////////////////////////////////////////\n"));
		cout << BOLD(FBLU("\t//                                           //\n"));
		cout << BOLD(FBLU("\t//")) << BOLD(FYEL("         Welcome to: String Analyzer!	     ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//                                           //\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL ("  This analyzer  will allow the user     ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL ("  to input a string of alphanumeric      ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL ("  values (letters and digits), as well   ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL ("  as special characters (spaces,symbols, ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL ("  newlines) and punctation points(,.;)   ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL ("  It's output consists of: 		     ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL ("                     		     ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" I. Number of alphanumeric characters    ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" II. Number of letters + out of total    ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" III. Number of digits + out of total    ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" IV. Total number of words               ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" V. Number of words starting with 'ted'  ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" VI. Number of words ending with 'ted'   ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" VII. Number of words with 'ted' 	     ")) << BOLD(FBLU ("//\n"));
		cout << BOLD(FBLU("\t//  ")) << BOLD(FYEL (" VIII. 'ted' out of all trisequences     ")) << BOLD(FBLU ("//\n"));	
		cout << BOLD(FBLU("\t//                                           //\n"));
		cout << BOLD(FBLU("\t///////////////////////////////////////////////\n\n"));

		cout << BOLD(FGRN("Please enter your sequence and hit '#' when done!: \n"));
		getline(cin, S, '#');
		S += '\n';

		//cin >> S; //S string input
		cout << endl;

		//Declarations of the size for the Digits array, and the array itself
		int size = S.length() + 1;
		char * Alpha = new char [size];
		strcpy(Alpha,S.c_str());

		CountCharacters(Alpha,size);
		CountWordsnTED(Alpha,size);
		CountSequence(Alpha,size);


		cout << BOLD(FYEL("\nWould you like to go again? (y/n): "));
		cin >> ans_prime;
		cin.ignore();

	}while (ans_prime == 'y' || ans_prime == 'Y');

	return 0;

}

//////////////////////////////////////////////////////////////////////////
//                      Function Definitions                            //
//////////////////////////////////////////////////////////////////////////

void CountCharacters (char* a, int size)
{
	int acount = 0;
	int bcount = 0;
	int ccount = 0;
	for (int i=0; i < size; i++)
	{
		if (isalnum(a[i]))
		{
			acount++;
		}
		if (isalpha(a[i]))
		{
			bcount++;
		}
		if (isdigit(a[i]))
		{
			ccount++;
		}
	}	
	cout << BOLD(FGRN("I. \tThe total number of alphanumeric characters (i.e., letters and digits): ")) << acount << endl;
	cout << BOLD(FGRN("II. \tThe total number of letters and their frequency with respect to the total number of alphanumeric characters: ")) << bcount << BOLD(FGRN(" letters to ")) << acount << BOLD(FGRN(" alphanumeric characters.\n"));

	cout << BOLD(FGRN("III. \tThe total number of digits and their frequency with respect to the total number of alphanumeric characters: ")) << ccount << BOLD(FGRN(" digits to ")) << acount << BOLD(FGRN(" alphanumeric characters.\n"));


}

void CountWordsnTED(char* a, int size)
{
	int j;
	int words = 0;
	int wordsstartingwted = 0;
	int wordsendingwted = 0;
	int wordswithted = 0;
	for (int i = 0; i<size; i++)
	{
		if (isalnum(a[i]))
		{
			for ( j = i; j<size; j++)
			{
				if (!isalnum(a[j]))
				{
					words++;
					break;
				}
			}
			i = j;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (!isalnum(a[i-1]) && a[i] == 't' && a[i+1] == 'e' && a[i+2] == 'd') 
		{	
			wordsstartingwted++;
		}
		else if (a[i] == 't' && a[i+1] == 'e' && a[i+2] == 'd' && !isalnum(a[i+3]))
		{	
			wordsendingwted++;
		}
		else if (isalnum(a[i-1]) && a[i] == 't' && a[i+1] == 'e' && a[i+2] == 'd' && isalnum(a[i+3]))  
		{
		 	wordswithted++;
		}
	}



	cout << BOLD(FGRN("IV. \tThe total number of words: ")) << words << endl;
	cout << BOLD(FGRN( "V. \tThe total number of words starting with 'ted': ")) << wordsstartingwted << BOLD(FGRN("\n\tTheir frequency with respect to the total number of words: ")) << wordsstartingwted <<BOLD(FGRN(" words starting with ted out of ")) << words << BOLD(FGRN(" words.\n"));
	cout << BOLD(FGRN( "VI. \tThe total number of words ending with 'ted': ")) << wordsendingwted << BOLD(FGRN("\n\tTheir frequency with respect to the total number of words: ")) << wordsendingwted << BOLD(FGRN(" words endining with ted out of ")) << words << BOLD(FGRN(" words.\n"));
	cout << BOLD(FGRN("VII. \tThe total number of words with 'ted' in the middle: ")) << wordswithted << BOLD(FGRN("\n\tTheir frequency with respect to the total number of words: ")) << wordswithted << BOLD(FGRN(" words with ted in the middle out of ")) << words << BOLD(FGRN(" words.\n"));


}


void CountSequence (char* a, int size)
{
	int count = 0;
	int ted = 0;
	int triseq;
	for (int i=0; i < size; i++)
	{
		if (isalnum(a[i]))
		{
			count++;
		}
		
		if (a[i] == 't' && a[i+1] == 'e' && a[i+2] == 'd')
		{
			ted++;
		}
	}	
	triseq = count/3;

	cout << BOLD(FGRN("VIII. \tThe total number of sequences of 'ted': ")) << ted << BOLD(FGRN("\n\tTheir frequency with respect to the total number of sequences of three alphanumeric characters: ")) << ted << BOLD(FGRN(" 'ted' sequences out of ")) << triseq << BOLD(FGRN(" sequences of three alphanumeric characters.\n")); 

}
