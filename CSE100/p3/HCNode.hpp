/*
 * Name: Angelique De Castro
 * login: ajdecast
 * 
 * Filename: HCNode.hpp
 * Description: This file contains declarations of the huffman compression
 * tries' nodes.
 */

#ifndef HCNODE_HPP
#define HCNODE_HPP

#include <iostream>

#define NOT_SET 0xFF

typedef unsigned char byte;

using namespace std;

/** A class, instances of which are nodes in an HCTree.
 */
class HCNode {
  friend bool comp(HCNode* one, HCNode* other);

public:
  int count;
  byte symbol;   // byte in the file we're keeping track of
  HCNode* c0;    // pointer to '0' child
  HCNode* c1;    // pointer to '1' child
  HCNode* p;     // pointer to parent
  byte isChild0; // boolean if it is 0 child

  HCNode(int count,
   byte symbol,
   HCNode* c0 = 0,
   HCNode* c1 = 0,
   HCNode* p = 0,
   byte isChild0 = NOT_SET)
    : count(count), symbol(symbol), c0(c0), c1(c1), p(p), isChild0(isChild0) { }

  // Constructor for making new root node to join two roots of subtrees
  HCNode( HCNode* node1, HCNode* node2)
    : count(node1->count+node2->count), symbol(0), c0(node1), c1(node2), 
    p(nullptr), isChild0(NOT_SET) { }

  /** Less-than comparison, so HCNodes will work in std::priority_queue
   *  We want small counts to have high priority.
   *  And we want to break ties deterministically.
   */
  bool operator<(const HCNode& other);

  HCNode* successor() const
  {
    HCNode* successor = nullptr;
    const HCNode* currentNode = this;
   
    if(currentNode == NULL)
      return 0;

    /*First need to check if c0 child is the successor */
    if(currentNode->c0 != NULL)
    {
      /*Move to c0 */
      successor = currentNode->c0;
      
      /*Move to the farthest c1*/
      while(successor->c1 != NULL)
      {
          successor=successor->c1;
      }
        return successor;
     }

    if(p == NULL)
      return nullptr;

   /*The next node could also be in a parent */
  HCNode *par = currentNode->p;
    
   /*Search for the inorder parent */
    while(par != NULL && currentNode != NULL && par->c0 == currentNode)
    {
     currentNode = par;
     par = par->p;
    }
    return par;
  } 
}; 

/** For printing an HCNode to an ostream
 *  Possibly useful for debugging.
 */
ostream& operator<<(ostream&, const HCNode&) __attribute__((weak)); // shut the linker up
ostream& operator<<(ostream& stm, const HCNode& n) {
    stm << "[" << n.count << "," << (int) (n.symbol) << "]";
    return stm;
}

bool comp(HCNode* one, HCNode* other);


#endif // HCNODE_HPP
