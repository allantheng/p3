/*
 * Name: Angelique De Castro, Robert Massingill
 * login: ajdecast, rmassing
 */

#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include "HCTree.hpp"
#include "HCNode.hpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

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
  
  HCTree tree = HCTree(); // init new tree to build
  FILE *datfile;
  long lsize;
  char *buffer;

  cout << "reading from file \"" << argv[1] << "\"... ";

  ifstream is(argv[1]); // open files for reading (2 ways for useful methods)
  datfile = fopen(argv[1], "r");

  // obtain file size
  fseek(datfile, 0, SEEK_END);
  lsize = ftell(datfile);
  rewind(datfile);

  // allocate memory to contain the whole file
  buffer = (char*)malloc(sizeof(char)*lsize);
  if(buffer == NULL) {cerr << "Error opening \"0\"" << endl; return -1;} 

  // copy file into buffer
  fread(buffer, 1, lsize, datfile);

  vector<int> frequency = vector<int>(256, 0); // create vector of char freqs

  while(is.good()) // loop while extraction from files is possible
    frequency[is.get()] += 1; // go to corresponding index and inc count

  cout << "done." << endl;

  tree.build(frequency);

  cout << "Found " << is.gcount() << 
  " unique symbols in the input file of size " << lsize  << " bytes." << endl;
}
