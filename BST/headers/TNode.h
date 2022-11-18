#pragma once
#include <iostream>

class TNode {
   public:
    // Constructores.
    TNode(int dataValue) {
        data = dataValue;
        left = NULL;
        right = NULL;
    }
    TNode() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    // Getters.
    TNode* getRight() {
        return right;
    }

    TNode* getLeft() {
        return left;
    }
    int getData() {
        return data;
    }

    // Setters.
    void setRight(TNode* rightNode) {
        right = rightNode;
    }

    void setLeft(TNode* leftNode) {
        left = leftNode;
    }
    void setData(int dataValue) {
        data = dataValue;
    }

   private:
    // Variables.
    int data;
    TNode* left;
    TNode* right;
};
