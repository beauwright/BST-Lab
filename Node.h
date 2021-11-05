//
// Created by Beau Wright on 11/4/21.
//

#ifndef LAB7_NODE_H
#define LAB7_NODE_H
#include "NodeInterface.h"

using namespace std;

class Node: public NodeInterface {
    Node();
    ~Node();
    int getData() const;
    NodeInterface * getLeftChild() const;
    NodeInterface * getRightChild() const;
};


#endif //LAB7_NODE_H
