/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"
#include <iostream>
#include <cstdio>
#include <queue>

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

  //TODO assume everything is okay
  filebuf fb;
  BitInputStream in = BitInputStream( istream( fb.open( argv[1], ios:in ) ) );

  int extraBitCount = in.readByte();
  
  int bit;
  HCTree tree = HCTree();
  queue<**HCNode> queue;
  queue.push( &(tree.root) );
  bool isC0 = true;
  do
  {
    bit = in.readBit();
    if( bit == 0 )
    {
      
    }
    else
    {

    }
  }while( queue.size() );

}
