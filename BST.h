//
// Created by beau1 on 11/4/2021.
//

#ifndef LAB7_BST_H
#define LAB7_BST_H

#include "BSTInterface.h"


class BST: public BSTInterface {
protected:
    Node *root;
public:
    BST();
    ~BST();
    NodeInterface * getRootNode() const;
    bool add(int data);
    bool remove(int data);
    void clear();
};


#endif //LAB7_BST_H
