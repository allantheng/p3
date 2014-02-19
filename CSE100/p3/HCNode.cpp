/*
 * Name: Angelique De Castro
 * login: ajdecast
 * 
 * Filename: HCNode.cpp
 * Description: This file contains definitions of the huffman compression
 * tries' nodes.
 */

#include "HCNode.hpp"

/** Less-than comparison, so HCNodes will work in std::priority_queue
   *  We want small counts to have high priority.
   *  And we want to break ties deterministically.
   */
bool HCNode::operator<(const HCNode & other)
{
  
}
