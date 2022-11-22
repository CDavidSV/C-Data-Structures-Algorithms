// Proyecto Virus.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include "./headers/Graph.h"

int main() {
    std::vector<Edge> users = {{0, 1, "Ana", "Juan"}, {1, 2, "Juan", "Pedro"}, {2, 3, "Pedro", "Luis"}, {2, 5, "Pedro", "Gustavo"}, {3, 4, "Luis", "Sebastian"}, {5, 6, "Gustavo", "Adrian"}, {6, 7, "Adrian", "Saul"}};
    Graph grafoUsuarios = Graph(users, 8, 7);

    // Casos de prueba.
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------- Casos de Prueba ------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "-------------- Pruebas del problema ---------------" << std::endl;
    grafoUsuarios.Publish(0, "Ana", 3);
    grafoUsuarios.Publish(3, "Luis", 4);
    std::cout << std::endl;

    std::cout << "----------------- Pruebas Extra ------------------" << std::endl;
    grafoUsuarios.Publish(4, "Sebastian", 2);
    grafoUsuarios.Publish(5, "Gustavo", 1);
    grafoUsuarios.Publish(3, "Luis", 1);
    grafoUsuarios.Publish(2, "pedro", 3);

    return 0;
}