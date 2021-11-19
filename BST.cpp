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
    }
    else if (node->getData() == data) {
        return false;
    }
    else if (data < node->getData()){
        return add(data, node->getLeft());
    }
    else {
        return add(data, node->getRight());
    }
}

bool BST::remove(int data) {
    //cout << "remove" << endl;
    return remove(data, this->root);
}

bool BST::remove(int data, Node *& node) {
    //cout << "remove helper activated, data is " << data << endl;
    if (node == nullptr) {
        return false;
    }
    else {
        if (data < node->getData()) {
            return remove(data, node->getLeft());
        }
        else if (data > node->getData()) {
            return remove(data, node->getRight());
        }
        else {
            Node *placeholder = node;
            if (node->getLeft() == nullptr) {
                node = node->getRight();
                delete placeholder;
            } else if (node->getRight() == nullptr) {
                node = node->getLeft();
                delete placeholder;
            } else {
                replace(placeholder, node->getLeft());
            }
            return true;
        }
    }
}

void BST::replace(Node*& placeholder, Node*& node){
    if(node->getRight() == nullptr){
        placeholder->setData(node->getData());
        remove(node->getData(), placeholder->getLeft());
    }
    else{
        replace(placeholder, node->getRight());
    }
}

void BST::clear() {
    //cout << "clear" << endl;
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