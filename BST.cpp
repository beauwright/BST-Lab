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
    return remove(data, this->root);
}

bool BST::remove(int data, Node *& node) {
    cout << "remove helper activated, data is " << data << endl;
    if (node == nullptr) {
        return false;
    } else {
        if (data < node->getData()) {
            return remove(data, node->getLeft());
        } else if (data > node->getData()) {
            return remove(data, node->getRight());
        } else {
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


    /*
    if (node == nullptr) {
        return false;
    }
    if (node->getData() == data) {
        if (node->getLeft() == nullptr) {
            Node *tmp = node;
            node = node->getRight();
            delete tmp;
            cout << data << " is deleted via left" << endl;
            return true;
        }
        else if (node->getRight() == nullptr) {
            cout << "@ removehelper right side" << endl;
            Node *tmp = node;
            node = node->getLeft();
            delete tmp;
            cout << data << " is deleted via right" << endl;
            return true;
        }
        else {
            cout << "calling getIOR with data value of " << data <<endl;
            //if(data == root->getData()) {
            //    cout << "we be returning without doing anything" << endl;
            //    return true;
            //}
            Node *iOP = getIOP(node->getLeft(), root->getData());
            node->setData(iOP->getData());
            remove (iOP->getData(), node->getLeft());
            return true;
        }
    }
    if (node->getData() > data) {
        return remove(data, node->getLeft());
    } else {
        return remove(data, node->getRight());
    } */
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
/*
Node* BST::getIOP(Node * node, int previous) {
Node * prev = node;
Node * pos = root;
Node * parent = nullptr;
    while (pos->getLeft() != nullptr) {
        parent = pos;
        pos = pos->getLeft();
        //pos->setParent = parent;
    }

    /*
    cout << "reached get IOP, node is " << node->getData() << endl;
    Node * tmp = node;
    while (tmp->getLeft() != nullptr) {
        if(node >)
        tmp = tmp->getLeft();
    }
    cout << "passed while loop" << endl;
    if(tmp->getRight() != nullptr) {
        tmp = tmp->getRight();
    }
    cout << "tmp value prior to return is: " << tmp->getData();
    return tmp;
*/
    /*
    cout << "getParent activated, data value is " << data << endl;
    Node * currentNode = root;
    Node * parentNode = root;
    if (currentNode == nullptr) {
        return nullptr;
    }
    for(int i = 0; i < currentPos; i++) {
        //cout << "iterating currentNode" << endl;
        if (currentNode->getLeft() != nullptr) {
            currentNode = currentNode->getLeft();
        } else if (currentNode->getRight() != nullptr) {
            currentNode = currentNode->getRight();
        }
    }
    for(int i = 0; i < parentPos; i++) {
        cout << "iterating parentNode" << endl;
        if (parentNode->getLeft() != nullptr) {
            parentNode = parentNode->getLeft();
        } else if (parentNode->getRight() != nullptr) {
            parentNode = parentNode->getRight();
        }
    }
    if (currentNode->getLeft() != nullptr) {
        cout << "@ getLeft not null" << endl;
            getIOP(data, currentPos + 1, parentPos);
    } else {
        cout << "@ else" << endl;
        parentNode++;
        if (currentNode->getData() == data) {
            cout << "node of value " << data << " found, data is "<< currentNode->getData() << " parent is " << parentNode->getData() << endl;
            return parentNode;
        }
        if (currentNode->getRight() != nullptr) {
            cout << "@ getRight not null" << endl;
            if (currentNode->getRight()->getData() == data) {
                cout << "@ node found right!!!!!!!!!!" << endl;
                return parentNode;
            }
            getIOP(data, currentPos + 1, parentPos);
        }
    }
    cout << "Houston, we have a problem" << endl;
    return nullptr;
    */
    /*
    cout << "getParent activated" << endl;
    if (node == nullptr) {
        return nullptr;
    }
    if (node->getLeft() != nullptr) {
        if (node->getLeft()->getData() == data) {
            return node;
        }
    }
    if (node->getRight() != nullptr) {
        if (node->getRight()->getData() == data) {
            return node;
        }
    }
    if (node->getData() > data) {
        return getParent(data, node->getLeft());
    } else {
        return getParent(data, node->getRight());
    }
    */

/*
    Node *nullNode = nullptr;
    if (node != nullptr) {
        if (node->getData() != data) {
            if (node->getLeftChild() != nullptr) {
                if (node->getLeft()->getData() == data) {
                    return node;
                } else {
                    getParent(data, node->getLeft());
                }
            }
            if (node->getRight() != nullptr) {
                if (node->getRight()->getData() == data) {
                    cout << "the parent node has been found. It's value is: " << node->getData() << endl;
                    return node;
                } else {
                    getParent(data, node->getRight());
                }
            }
        } else {
            return this->root;
        }
    }
    return nullNode;
    */

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