/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#ifndef HCTREE_HPP
#define HCTREE_HPP

#include <queue>
#include <vector>
#include "HCNode.hpp"
#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"

using namespace std;

/** A 'function class' for use as the Compare class in a
 *  priority_queue<HCNode*>.
 *  For this to work, operator< must be defined to
 *  do the right thing on HCNodes.
 */
class HCNodePtrComp
{
public:
    bool operator()(HCNode*& lhs, HCNode*& rhs) const
    {
        return *lhs < *rhs;
    }
};

/** A Huffman Code Tree class.
 *  Not very generic:  Use only if alphabet consists
 *  of unsigned chars.
 */
class HCTree
{
private:
    HCNode* root;
    vector<HCNode*> leaves;

public:
    explicit HCTree() : root(0)
    {
        leaves = vector<HCNode*>(256, (HCNode*) 0);
    }

    // Constructor for joining two trees
    explicit HCTree(HCNode* node1, HCNode* node2)
      : root( new HCNode(node1->count+node2->count, 0,
         node1, node2, 0, NOT_SET))
    {
      /*leaves = vector<HCNode*>(256, (HCNode*) 0); // create new leaves vector

      HCNode* upCurr; // HCNode* for upwards traversal for setting isChild0

      //Traversing all nodes to add to leaves vector and set isChild0 field
      for( HCNode* curr = root; curr!=nullptr; curr=curr->successor() )
      {
        leaves[curr->symbol] = curr;
        upCurr = curr;
      }
      */
    }


    ~HCTree()
      {}

    /** Use the Huffman algorithm to build a Huffman coding trie.
     *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
     *  the frequency of occurrence of byte i in the message.
     *  POSTCONDITION:  root points to the root of the trie,
     *  and leaves[i] points to the leaf node containing byte i.
     */
    void build(const vector<int>& freqs);

    /** Write to the given BitOutputStream
     *  the sequence of bits coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    void encode(byte symbol, BitOutputStream& out) const;

    /** Return symbol coded in the next sequence of bits from the stream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    int decode(BitInputStream& in) const;
};

#endif // HCTREE_HPP
