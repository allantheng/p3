/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// Main method of the program to do runtime based on user input.
int main(int argc, char** argv)
{
  // check for correct number of args from user input
  if( argc != 3 )
  {
    cerr << "./compress called with incorrect arguments." << endl;
    cerr << "Usage: ./compress infile outfile" << endl;

    return -1;
  }
  
  /**
   * Open the input file for reading.
   * Read bytes from the file, counting the number of occurrences of each byte value; then close the file.
   * Use these byte counts to construct a Huffman coding tree.
   * Open the output file for writing.
   * Write enough information (a "file header") to the output file to enable the coding tree to be reconstructed when the file is read by your uncompress program.
   * Open the input file for reading, again.
   * Using the Huffman coding tree, translate each byte from the input file into its code, and append these codes as a sequence of bits to the output file, after the header.
   * Close the input and output files.
   */
  
  FILE *datfile; // pointer to file
  char *ptr = nullptr; // pointer for fopen 
  size_t result;
  long lsize;
  
  cout << "reading from file \"" << argv[1] << "\"... ";
  
  datfile = fopen( argv[1], "r" ); // open input file for reading
  
  lsize = ftell(datfile); // get size of the file
  
  if( lsize < 0)
    exit(1); //TODO errno stuff
  
  result = fread( ptr, 1, lsize, datfile); // save result to compare to lsize
  
  if( result != (unsigned long)lsize )
    fputs("EOF error", stderr); // TODO see if error should be thrown for EOF and return??
  
  cout << "done." << endl;

  // 
  
  cout << "Found " << /*number*/"3" << 
  " unique symbols in the input file of size " << lsize << " bytes." << endl;
  
  
  fclose( datfile );
}
