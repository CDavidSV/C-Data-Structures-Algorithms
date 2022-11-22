#pragma once
#include <iostream>

template <class T>
class DNode {
   public:
    // Variables.
    T data;
    DNode<T>* nextNode;
    DNode<T>* prevNode;

    // Constructores.
    DNode(T dataValue) {
        data = dataValue;
        nextNode = nullptr;
        prevNode = nullptr;
    }
    DNode() {
        data = "Na";
        nextNode = nullptr;
        prevNode = nullptr;
    }
};