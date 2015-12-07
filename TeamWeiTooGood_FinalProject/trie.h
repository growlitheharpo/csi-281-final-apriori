#ifndef TRIE_H
#define TRIE_H

#include "basefunctions.h"
#include "dynamicarray.h"

class Trie
{
	//private:
  public:
		struct Node
		{
			DynamicArray<Node*> mChildren;
      DynamicArray<int>   mPath;
      bool                mHasMinSupport;
      int                 mItemId;


			/*     Pre:  None
			*     Post:  This object is initialized using default values
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node()
			{
				mItemId = int();
        mHasMinSupport = false;
        mPath = NULL;
			}

			/*     Pre:  None
			*     Post:  This object is initialized using specified data
			*  Purpose:  To initialize date object
			*************************************************************************/
			Node(int itemId)
			{
				mItemId = itemId;
        mHasMinSupport = false;
        mPath = NULL;
			}
		};
  private:

		Node *mRootNode;

		void destroySubtrie(Node *node);
		bool isLeaf(Node *node);
		void traverseTrie(int path[], Node *&someNode);

	public:
		Trie();
		~Trie();

    void setMinSupport(int path[], bool hasMinSupport);
    bool getHasMinSupport(int path[]);

    void getAllPaths(DynamicArray<DynamicArray<int>> &allPaths); 

		bool addNode(int path[]);
		bool isEmpty();
		bool removeNode(int path[]);

};

#endif