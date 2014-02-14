/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#include 'BitInputStream.hpp'
#include 'BitOutputStream.hpp'
#include <iostream>

using namespace std;

// Main method of the program to do runtime based on user input.
int main(int argc, char** argv)
{
  	// check for correct number of args from user input
	if( argc != 3 )
	{
		cerr << "./compress called with incorrect arguments." << endl;
		cerr << "Usage: ./compress infile outfile" << endl;
	}
}