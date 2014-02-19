/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#include "HCTree.hpp"
#include "HCNode.hpp"
#include <cstdio>

/** Use the Huffman algorithm to build a Huffman coding trie.
     *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
     *  the frequency of occurrence of byte i in the message.
     *  POSTCONDITION:  root points to the root of the trie,
     *  and leaves[i] points to the leaf node containing byte i.
     */
     //TODO
    void HCTree::build(const vector<int>& freqs)
    {
      root = nullptr; // root of trie is null

    }

    /** Write to the given BitOutputStream
     *  the sequence of bits coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    //TODO
    void HCTree::encode(byte symbol, BitOutputStream& out) const
    {
      
    }

    /** Return symbol coded in the next sequence of bits from the stream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    //TODO
    int HCTree::decode(BitInputStream& in) const
    {
      
    }
