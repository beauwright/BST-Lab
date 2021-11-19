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

Node *& Node::getLeft() {
    return leftChild;
}
Node *& Node::getRight() {
    return rightChild;
}

void Node::setData(int data) {
    this->data = data;
}
