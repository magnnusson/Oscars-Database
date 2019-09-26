//
// Created by Alen Handukic on 2019-03-18.
//
//To be used in conjunction with Node.h and BSTree<DATATYPE, KEYTYPE>.cpp
//If you modify this, please add your name and list any changes that you made

#ifndef DSFINALPROJECT_BSTREE_H
#define DSFINALPROJECT_BSTREE_H
#include <iostream>
#include <vector>
using namespace std;
#include "Node.h"

// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BSTree {
private:
    Node<DATATYPE, KEYTYPE> * root;
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
    void printInorder(Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);

    vector<DATATYPE> TreeToVec(vector<DATATYPE> &sortvec, Node<DATATYPE, KEYTYPE> * node); //PRIVATE FUNCTION FOR SORTTREE

public:
    BSTree<DATATYPE, KEYTYPE>();
    ~BSTree<DATATYPE, KEYTYPE>();
    Node<DATATYPE, KEYTYPE> * Root() { return root; }
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;}
    void addNode(KEYTYPE key, DATATYPE &data);
    Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
    void printInorder();
    void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key);
    Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
    Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);

    std::vector<DATATYPE> TreeToVec(vector<DATATYPE> &sortvec); //ADDED FUNCTIONALITY TO TRANSFER TREE CONTENTS TO DATA STRUCTURE FOR SORTING
};
#endif  //DSFINALPROJECT_BSTREE_H

