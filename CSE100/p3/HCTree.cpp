/*
 * Name: Angelique De Castro
 * login: ajdecast
 */

#include "HCTree.hpp"
#include "HCNode.hpp"
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

/** Use the Huffman algorithm to build a Huffman coding trie.
     *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
     *  the frequency of occurrence of byte i in the message and
     *  size greater than 0.
     *  POSTCONDITION:  root points to the root of the trie,
     *  and leaves[i] points to the leaf node containing byte i.
     */
    void HCTree::build(const vector<int>& freqs)
    {
      priority_queue<HCNode*> btq;
      
      //Populate priority queue with nodes
      for(int i = 0; i < (int)freqs.size(); ++i)
        if( freqs[i]!=0 )
         btq.push( new HCNode( freqs[i], i, 0, 0, 0, false) );

      HCNode *curr, *curr2;
      //Join nodes via constructor
      while( btq.size() > 1 )
      {
        //Constructor that makes a new parent node
        curr = btq.top();
        btq.pop();
        curr2 = btq.top();
        btq.pop();
        btq.push( new HCNode( curr, curr2 ) );
      }

      //Make new tree from remaining node
      this->root = btq.top();
      btq.pop();

      //Traversing all nodes to add to leaves vector
      for( curr = root; curr!=nullptr; curr=curr->successor() )
        if( !(curr->c0) ) //if current is a leaf
          leaves[curr->symbol] = curr;
    }


    /** Write to the given BitOutputStream
     *  the sequence of bits coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    void HCTree::encode(byte symbol, BitOutputStream& out) const
    {
      //If root is a leaf (special case)
      if( !(root->c0) )
      {
        out.writeBit( 0 );
        return;
      }
      
      //Traverse up and write according to isChild0 fields
      for( HCNode* curr = leaves[symbol]; curr->p; curr=(curr->p) )
        out.writeBit( !(curr->isChild0) );
      return;
    }


    /** Return symbol coded in the next sequence of bits from the stream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
    int HCTree::decode(BitInputStream& in) const
    {
      int bit;             //Read bit
      HCNode* curr = root; //Traversal pointer

      //If root is a leaf (special case)
      if(!( curr -> c0 ))
      {
        (void)in.readBit();
        return root->symbol;
      }

      else { //read input normally

        //While curr is not a leaf
        while( curr -> c0 )
        {
          bit = in.readBit();

          //Traverse either to either c0 or c1 depending on input bit
          if( bit == 0 )
            curr = (curr -> c0);
          else
            curr = (curr -> c1);
        }
      }
      return curr->symbol;
    }
