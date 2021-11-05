//
// Created by beau1 on 11/4/2021.
//

#include "BST.h"

BST::BST() {
    cout << "constructor reached" << endl;
}
BST::~BST() {
    cout << "deconstructor reached" << endl;
}
NodeInterface * BST::getRootNode() const{
    cout << "make getRootNode" << endl;
}
bool BST::add(int data) {
    cout << "add"<<endl;
    Node *ptr = new Node(data);
    ptr->leftChild = NULL; // To test that the friend relationship works
    NodeInterface *rval = ptr->getLeftChild();
    long value = (long)rval;
    cout << "Added "<<value<<endl;
    root = ptr;
    return true;
}
bool BST::remove(int data) {
    cout << "make remove" << endl;
    return false;
}

void BST::clear() {
    cout << "make clear" << endl;
}