/*
 * Name: Angelique De Castro
 * login: ajdecast
 * 
 * Filename: BitOutputStream.hpp
 * Description: This file makes use of the existing C++ IOstream library class
 * ofstream to write files by use of inheritance or composition for bitwise
 * functionality.
 */

#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP
#include <iostream>
#include <fstream>
#include <ostream>
#include <ios>

class BitOutputStream
{
private:
    char buf; // one byte buffer of bits
    int nbits; // how many bits have been written to buf
    std::ostream & out; // reference to the output stream to use
    
public:
  BitOutputStream(std::ostream & os);

  void flush();

  char setBit(char b, int bit, int n);

  void writeBit(int i);
};

#endif // BITOUTPUTSTREAM_HPP