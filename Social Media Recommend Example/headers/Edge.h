#pragma once
#pragma once
#include <iostream>
#include <string>

class Edge {
   public:
    int start;
    int end;
    std::string startUser;
    std::string endUser;

    Edge(int startV, int endV, std::string startUser, std::string endUser) {
        start = startV;
        end = endV;
        this->startUser = startUser;
        this->endUser = endUser;
    }
    Edge() {
        start = 0;
        end = 0;
    }
};