#pragma once
#include <iostream>
#include "Ip.h"

class BSTNode {
   public:
    // Constructores.
    BSTNode(Ip newIp) {
        ip = newIp;
        left = NULL;
        right = NULL;
    }
    BSTNode() {
        left = NULL;
        right = NULL;
    }

    // Getters.
    BSTNode* getRight() {
        return right;
    }

    BSTNode* getLeft() {
        return left;
    }
    Ip getData() {
        return ip;
    }

    // Setters.
    void setRight(BSTNode* righBSTNode) {
        right = righBSTNode;
    }

    void setLeft(BSTNode* lefBSTNode) {
        left = lefBSTNode;
    }
    void setData(Ip ipValue) {
        ip = ipValue;
    }

   private:
    // Variables.
    Ip ip;
    BSTNode* left;
    BSTNode* right;
};
