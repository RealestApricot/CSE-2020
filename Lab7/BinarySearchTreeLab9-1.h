// PARTIAL implementation of BinarySearchTree
// insert and printing only
// version for Lab9, 2024 ... to be completed

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cassert>
#include "Vector-2.h"
using namespace std;


template <typename T>
class BinarySearchTree
{
private:
    struct BinaryNode
    {
        T element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(theElement), left(lt), right(rt)
        {}

        BinaryNode(const T&& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(std::move(theElement)), left(lt), right(rt)
        {}
    };

    void insertHelper(const T & x, BinaryNode * & t)
    {
	if (t == nullptr)
	{
		t = new BinaryNode{x, nullptr, nullptr};
	}
	else if (x < t->element)
	{
		insertHelper(x, t->left);
	}
	else if (t->element < x)
	{
		insertHelper(x, t->right);
	}
	else
	{
		// duplicate; do nothing
	}
    };

    void printElementsHelper(BinaryNode *t) const
    {
	if (t == nullptr)
	{
		return;
	}

	printElementsHelper(t->left);
	cout << t->element << " ";
	printElementsHelper(t->right);
    }

    int sizeHelper(BinaryNode * t) const
    {
	if (t == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + sizeHelper(t->left) + sizeHelper(t->right);
	}
    };

    void removeHelper(const T& x, BinaryNode*& t)
    {
	if (t == nullptr)
	{
		return;
	}
	if (x < t->element)
	{
		removeHelper(x, t->left);
	}
	else if (t->element < x)
	{
		removeHelper(x, t->right);
	}
	else
	{
		if (t -> right != nullptr)
		{
			t->element = findMin(t->right)->element;
			removeHelper(t->element, t->right);
		}
		else
		{
			BinaryNode * oldNode = t;
			if (t->left != nullptr)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
			delete oldNode;
		}
	}
    };	

public:

    BinarySearchTree() : root(0) {}

    ~BinarySearchTree()
    {
        makeEmpty();
    }

    bool isEmpty() const
    {
        return root == 0;
    }

    void insert(const T& x)
    {
        // calls private insert ...
	insertHelper(x, root); // ==> LAB 10: add private fct from Module 6.2
    }

    // LAB 10: print all elements (values) in line

    void printElements() const
    {
	printElementsHelper(root); // LAB 10: define private fct below
    }

    // LAB 10: returns number of elements in BST 

    int size() const
    {
	return sizeHelper(root); // LAB 10: define private fct below
    }


    // for destructor to call...
    void makeEmpty()
    {
        makeEmpty(root);
    }

    const T& findMin() const
    {
	assert(!isEmpty());
	return findMin(root)->element;
    }

    void remove(const T& x)
    {
	removeHelper(x, root);
    }

private:

    BinaryNode* root;


    //the private member fcts that do all the work...

    void insert(const T& x, BinaryNode*& t)
    {
        // LAB 10: COMPLETE 
    }

    void makeEmpty(BinaryNode*& t)
    {
        if (t != 0)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = 0;
    }

    void printInternal(BinaryNode* t, int offset) const
    {
        for (int i = 1; i <= offset; i++)
            cout << "..";
        if (t == 0)
        {
            cout << "#" << endl;
            return;
        }
        cout << t->element << endl;
        printInternal(t->left, offset + 1);
        printInternal(t->right, offset + 1);
        return;
    }


    // LAB 10: COMPLETE; returns the number of elements  stored in BST 
    //         rooted in t;

    int size(BinaryNode* t) const
    {
        return -1; // temp PLACE HOLDER for the actual code
    }

    BinaryNode* findMin(BinaryNode* t) const
    {
	if (t == 0)
	    return 0;
	if (t->left == 0)
	    return t;
	return findMin(t->left);
    }

};





#endif