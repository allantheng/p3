/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#include 'BitOutputStream.hpp'
#include <cstdio>
#include <iostream>

class BitOutputStream
{
private:
	char buf; // one byte buffer of bits
	int nbits; // how many bits have been written to buf
	std::ostream &out; // reference to the output stream to use
	
public:

  /** Initialize a BitOutputStream that will use
   * the given ostream for output.
   */
  BitOutputStream(std::ostream & os) : out(os)
  {
  buf = nbits = 0; // clear buffer and bit counter
  }

  /** Send the buffer to the output, and clear it */
  void flush()
  {
    os.put(buf);
    os.flush();
    buf = nbits = 0;
  }
  
  /**
   * Set the value -- 1 or 0 -- of the nth bit from the 
   * right of a byte argument, leaving other bits
   * unchanged and return the result
   */
  char setBit(char b, int bit, int n)
  {
    char c;
    if( bit == 1 )
      c = b | (bit << n-1)
    else
      c = b & ~(1 << n-1);
  }
  
  /** Write the least significant bit of the argument to
  * the bit buffer, and increment the bit buffer index.
  * But flush the buffer first, if it is full.
  */
  void writeBit(int i)
  {
    // Is the bit buffer full? Then flush it
    if( nbit == 8 ) flush();
    // Write the least significant bit of i into the buffer
    // at the current index
    setBit(buf, i, nbits + 1);
    // Increment the index
    nbits++;
  }
}