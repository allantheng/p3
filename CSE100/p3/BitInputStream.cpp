/*
 * Name: Angelique De Castro
 * login: ajdecast
 * 
 * Filename: BitinputStream.cpp
 * Description: This file makes use of the existing C++ IOstream library class
 * ifstream to write files by use of inheritance or composition for bitwise
 * functionality.
 */

#include "BitInputStream.hpp"
#include <cstdio>
#include <iostream>
#include <bitset>

  /** Initialize a BitInputStream that will use
  * the given istream for input.
  */

  BitInputStream::BitInputStream(std::istream & is) : in(is)
  {
    buf = 0; // clear buffer
    nbits = 0; // initialize bit index for big endian.
  }

  /** Fill the buffer from the input */
  void BitInputStream::fill()
  {
    buf = in.get();
    nbits = 0;
  }
  
  /**
   * Return the value -- 1 or 0 -- of the nth bit from the right of a byte
   * argument and return the result.
   */
  char BitInputStream::bitVal(char b, int n)
  {
    char c = b & (1 << (n-1));
    return c;
  }
  
  /** Read the next bit from the bit buffer.
  * Fill the buffer from the input stream first if needed.
  * Return 1 if the bit read is 1;
  * return 0 if the bit read is 0.
  */
  int BitInputStream::readBit()
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
