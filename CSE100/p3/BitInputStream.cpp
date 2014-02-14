/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#include 'BitInputStream.hpp'
#include <cstdio>
#include <iostream>

class BitInputStream
{

private:

  char buf; // one byte buffer of bits
  int nbits; // how many bits have been read from buf
  std::istream & in; // the input stream to use

public:

  /** Initialize a BitInputStream that will use
  * the given istream for input.
  */

  BitInputStream(std::istream & is) : in(is)
  {
    buf = 0; // clear buffer
    nbits = 0; // initialize bit index
  }

  /** Fill the buffer from the input */
  void fill()
  {
    buf = in.get();
    nbits = 0;
  }
  
  /**
   * Return the value -- 1 or 0 -- of the nth bit from the right of a byte
   * argument and return the result.
   */
  char bitVal(char b, int n)
  {
    char c = b & (1 << n-1);
    return c;
  }
  
  /** Read the next bit from the bit buffer.
  * Fill the buffer from the input stream first if needed.
  * Return 1 if the bit read is 1;
  * return 0 if the bit read is 0.
  */
  int readBit()
  {
    // If all bits in the buffer are read, fill the buffer first
	if( nbits == 8 ) fill();
	
    // Get the bit at the appropriate location in the bit
    // buffer, and return the appropriate int
	int v = bitVal(buf, nbits+1);

    // Increment the index
    nbits++;
    
    // return bit value
    return v;
  }
}