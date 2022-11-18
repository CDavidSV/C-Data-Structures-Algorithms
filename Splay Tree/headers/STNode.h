#pragma once
#include <iostream>

class STNode {
   public:
    // Constructor.
    STNode(int iValue) {
        value = iValue;
    }

    // Variables.
    int value = 0;
    int acceses = 0;
    STNode* progenitore = nullptr;
    STNode* left = nullptr;
    STNode* right = nullptr;
};