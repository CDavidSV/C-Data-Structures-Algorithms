#pragma once
#include <iostream>
#include "Ip.h"

class STNode {
   public:
    // Constructor.
    STNode(Ip ipValue) {
        ip = ipValue;
    }

    // Variables.
    Ip ip;
    int acceses = 0;
    STNode* progenitore = nullptr;
    STNode* left = nullptr;
    STNode* right = nullptr;
};