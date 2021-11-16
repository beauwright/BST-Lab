//
// Created by beau1 on 11/4/2021.
//

#include "BST.h"

BST::~BST() {
        //cout << "deconstructor reached" << endl;
        BST::clear();
}
NodeInterface * BST::getRootNode() const {
    //cout << "make getRootNode" << endl;
    return this->root;
}

bool BST::add(int data) {
    //cout << "add"<<endl;
    return add(data, this->root);
}

bool BST::add(int data, Node *&node) {
    if (node == nullptr) {
        node = new Node(data);
        return true;
    } else if (node->getData() == data) {
        return false;
    } else if (data < node->getData()){
        return add(data, node->getLeft());
    } else {
        return add(data, node->getRight());
    }
}

bool BST::remove(int data) {
    cout << "remove" << endl;
    remove(data, this->root);
    return false;
}

bool BST::remove(int data, Node *node) {
    if (node == nullptr) {
        return false;
    } else if (node->getData() == data) {
        parent = getParent(data, root);
        if (parent->getLeftChild()->getData() == data) {
            parent->setLeftChild(nullptr);
        }
        if (parent->getRightChild()->getData() == data) {
            parent->setRightChild(nullptr);
        }
        delete node;
        return true;
    } else if (data < node->getData()){
        return remove(data, node->getLeft());
    } else {
        return remove(data, node->getRight());
    }
    return false;
}

Node* getParent(int data, Node *node) {
    Node *nullNode = nullptr;
    if (node != nullptr && node->getData() != data) {
        if (node->getLeft() != nullptr) {
            if (node->getLeft()->getData()) {
                return node;
        } else {
                getParent(data, node->getLeft());
            }
        }
        if (node->getRight() != nullptr) {
            if (node->getRight()->getData()) {
                return node;
            } else {
                getParent(data, node->getRight());
            }
        }
    }
    else if (node->getData() == data) {
        return node;
    }
    return nullNode;
}

void BST::clear() {
    cout << "clear" << endl;
    recursiveClear(this->root);
    this->root = nullptr;
}

void BST::recursiveClear(Node *node) {
    if (node != nullptr) {
        recursiveClear(node->getLeft());
        recursiveClear(node->getRight());
        delete node;
    }
}