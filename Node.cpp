//
// Created by Beau Wright on 11/4/21.
//

#include "Node.h"

Node::Node() {
    cout << "constructor reached" << endl;
}
Node::~Node(){
    cout << "deconstructor reached" << endl;
}
int Node::getData() const {
    cout << "make getData" << endl;
}
NodeInterface * Node::getLeftChild() const {
    cout << "make getLeftChild" << endl;
}
NodeInterface * Node::getRightChild() const {
    cout << "make getRightChild" << endl;
}