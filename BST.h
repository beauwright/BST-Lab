//
// Created by beau1 on 11/4/2021.
//

#ifndef LAB7_BST_H
#define LAB7_BST_H

#include "BSTInterface.h"
#include "Node.h"


class BST: public BSTInterface {
public:
    BST() {};
    ~BST();
    NodeInterface * getRootNode() const;
    bool add(int data);
    bool remove(int data);
    void clear();

private:
    bool add(int data, Node *&node);
    bool remove(int data, Node *node);
        protected:
    Node *root = nullptr;
    Node *parent = nullptr;
    void recursiveClear(Node *node);
    Node* getParent(int data, Node *node);
};


#endif //LAB7_BST_H
