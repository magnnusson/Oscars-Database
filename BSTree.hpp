//
// Created by Alen Handukic on 2019-03-18.
//

//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.h"
#include <vector>
using namespace std;

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
    root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
    //Student must fill in
    //if the root is the leaf, delete that leaf
    // otherwise if the leaf is not null
    //recursive call of the leaf's left
    //recursive call of the leaf's right
    //now delete the leaf

    if(root == leaf)
    {
        delete leaf;
    }
    else
        {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
        }

}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
    if (Root() == nullptr)
    {
        Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);

    }
    else
        addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
    if(!leaf == NULL)
    {
        if(leaf->Key() > key)
        {
            if (leaf->Left() != nullptr)
                addNode(key, leaf->Left(), data);
            else {
                Node<DATATYPE, KEYTYPE> *newNodePtr = new Node<DATATYPE, KEYTYPE>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setLeft(newNodePtr);
                 }

        }
        else
            {
            if(leaf->Right() != nullptr)
                addNode(key, leaf->Right(), data);
            else
                {
                Node<DATATYPE,KEYTYPE>* newNodePtr = new Node<DATATYPE,KEYTYPE>;
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                leaf->setRight(newNodePtr);
                }
            }


    }



}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
    return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in
    // trap nullptr first in case we've hit the end unsuccessfully.
    // success base case
    //Greater than (Right), Less than (Left)
    if(node != nullptr)
    {
        if(node->Key() == key)
        {
            return node;
        }
        else
        {
            Node<DATATYPE, KEYTYPE> *tempNode = new Node<DATATYPE, KEYTYPE>;
            tempNode = findNode(key, node->Left());
            if(tempNode == nullptr)
            {
                tempNode = findNode(key, node->Right());
            }
            return tempNode;

        }
    }
    else
        {
        return nullptr;
        }


}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
    printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{

    //Student must fill in.  Use recursive algorithm.
    //Note that this prints using an Inorder, Depth-first search
    //but you may want to do something else when "visiting" the node....
    //like moving visited data to another datastructure
    //Don't forget your base case!

    if(node != nullptr)
    {
        printInorder(node->Left());
        cout << node->Key() << endl;
        printInorder(node->Right());

    }


}



template <typename DATATYPE, typename KEYTYPE>
vector<DATATYPE> BSTree<DATATYPE, KEYTYPE>::TreeToVec(vector<DATATYPE> &sortvec) //ADDED FUNCTION TO TRANSFER DATA TO ANOTHER DATA STRUCTURE
{
    TreeToVec(sortvec, root);
    return sortvec;
}

template <typename DATATYPE, typename KEYTYPE> //PRIVATE FUNCTION FOR TreeToVec
vector<DATATYPE> BSTree<DATATYPE,KEYTYPE>::TreeToVec(vector<DATATYPE> &sortvec, Node<DATATYPE, KEYTYPE> *node)
{
    if(node != nullptr)
    {
        TreeToVec(sortvec, node->Left());
        sortvec.push_back(node->Data());
        TreeToVec(sortvec, node->Right());
    }
    return sortvec;

}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
    out << data.number << "\t" << data.name << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
    setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{

    /* Given a binary search tree and a key, this function deletes the key
    and returns the new root */

    // base case
    if (aRoot == nullptr) return aRoot;

    // If the key to be deleted is smaller than the aRoot's key,
    // then it lies in left subtree
    if (value < aRoot->Key())
        aRoot->setLeft(deleteNode(aRoot->Left(), value));

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (value > aRoot->Key())
        root->setRight(deleteNode(aRoot->Right(), value));

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (aRoot->Left() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
            delete aRoot;
            return temp;
        }
        else if (aRoot->Right() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
            delete aRoot;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

        // Copy the inorder successor's content to this node
        aRoot->setKey(temp->Key());
        aRoot->setData(temp->Data());

        // Delete the inorder successor
        aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
    }
    return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * current = node;

    /* loop down to find the leftmost leaf */
    while (current->Left() != nullptr)
        current = current->Left();

    return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * tempNode = node;
    if (node == nullptr)
        tempNode = nullptr;
    else if (node->Right())
        tempNode = max(node->Right());
    else
        tempNode = node;

    return tempNode;
}
