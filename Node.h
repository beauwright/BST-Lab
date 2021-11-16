//
// Created by Beau Wright on 11/4/21.
//

#ifndef LAB7_NODE_H
#define LAB7_NODE_H
#include "NodeInterface.h"

using namespace std;

class Node: public NodeInterface {
public:
    Node(int data);
    ~Node();
    int getData() const;
    NodeInterface * getLeftChild() const;
    NodeInterface * getRightChild() const;
    Node *&getLeft();
    Node *&getRight();

    bool setLeftChild(Node* leftChild);
    bool setRightChild(Node* rightChild);
protected:
    int data;
    Node* parent = nullptr;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    void setData(int data);
    void setParent(Node* parent);
};


#endif //LAB7_NODE_H
