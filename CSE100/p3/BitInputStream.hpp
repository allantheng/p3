/*
 * Name: Angelique De Castro
 * login: ajdecast
 * 
 * Filename: BitInputStream.hpp
 * Description: A class which makes use of the existing C++ IOstream library
 * class ifstream to write files by use of inheritance or composition for
 * bitwise functionality.
 */

#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP
#include <iostream>

class BitInputStream
{
private:

  char buf; // one byte buffer of bits
  int nbits; // how many bits have been read from buf
  std::istream & in; // the input stream to use
  
public:
  BitInputStream(std::istream & is);

  void fill();

  char bitVal(char b, int n);

  int readBit();
};

#endif // BITINPUTSTREAM_HPP
