//Create a readable file that contains 10 words
//Create a readable file that the program scans
//create a readable file that the program outputs with the word counts listed

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Creating a constant integer to create the 'library' of results
const int WORD_LIB = 1024;

int main()
{
	//Listing out the files to be read and scanned
	ifstream inputFile01("inputFile01.txt");
	ifstream inputFile02("inputFile02.txt");
	//Listing out the file that will ultimately result
	ofstream outputFile01("outputFile01.txt");

	//Arrays needed to maintain the data
	string word01[WORD_LIB];
	string word02[WORD_LIB];

	//Creating a variable for tracking instances of matching cases
	int numFound = 0;

	//Creating the function for comparing keywords to file
	//'i' will be the word being searched by succession as referred to within the first file
	for (int i = 0; i < WORD_LIB; i = i + 1)
	{
		//using End of File
		if (!inputFile01.eof())
		{
			inputFile01 >> word01[i];
			//'j' will be the word being searched as referred to within the second file
			for (int j = 0; j < WORD_LIB; j = j + 1)
			{
				if (!inputFile02.eof())
				{
					inputFile02 >> word02[j];
					if (word01[i] == word02[j])
					{
						numFound = numFound + 1;
					}
				}
			}
			//'clear' basically telling the program to stop reading and clear flags
			//'seekg' basically telling the program to start over from the top
			inputFile02.clear();
			inputFile02.seekg(0, ios::beg);
			// writing to output file and resetting the counter
			outputFile01 << word01[i] << " was found " << numFound << " times.\n";
			numFound = 0;
		}
	}
	//for some reason, I had put the instructions for resetting the files and outputting here...
	//the only error it gave me to clue me in on why it wasn't working was that [i] didn't have an identifier
	//that by itself gave me about an hours worth of trouble.

    return 0;
}

