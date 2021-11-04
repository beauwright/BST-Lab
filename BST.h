//
// Created by beau1 on 11/4/2021.
//

#ifndef LAB7_BST_H
#define LAB7_BST_H

#include "BSTInterface.h"


class BST: public BSTInterface {
    BST();
    ~BST();
    NodeInterface * getRootNode();
    bool add(int data);
    bool remove(int data);
    void clear();
};


#endif //LAB7_BST_H
