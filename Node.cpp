//
// Created by Beau Wright on 11/4/21.
//

#include "Node.h"

Node::Node(int data) {
    //cout << "constructor reached" << endl;
    setData(data);
}
Node::~Node(){
    //cout << "deconstructor reached" << endl;
}
int Node::getData() const {
    //cout << " getData" << endl;
    return (data);
}
NodeInterface *Node::getLeftChild() const {
    //cout << "getLeftChild" << endl;
    return leftChild;
}
NodeInterface *Node::getRightChild() const {
    //cout << "getRightChild" << endl;
    return rightChild;
}
// make get helper functions work
Node *& Node::getLeft() {
    return leftChild;
}
Node *& Node::getRight() {
    return rightChild;
}

void Node::setData(int data) {
    this->data = data;
}

// eval C & P
void Node::setParent(Node* parent) {
    if(parent != NULL && parent->getLeftChild() != this && parent->getRightChild() != this)
        throw std::runtime_error("Cannot set parent if this is not set as child of parent");

    this->parent = parent;
}

bool Node::setLeftChild(Node* leftChild) {
    this->leftChild = leftChild;
    if(leftChild != NULL)
        leftChild->setParent(this);
    return true;
}

bool Node::setRightChild(Node* rightChild) {
    this->rightChild = rightChild;
    if(rightChild != NULL)
        rightChild->setParent(this);
    return true;
}