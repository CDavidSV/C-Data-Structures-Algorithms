// Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Carlos David Sandoval Vargas | A00834448
#include <iostream>
#include <fstream>
#include <string>

// Headers
#include "./headers/DoublyLinkedList.h"

// Esta función leen el archivo de bitacora.txt y lo convierta al su tipo de lista.
DoublyLinkedList<std::string>* readFile(std::string fileDir) {
    DoublyLinkedList<std::string>* list = new DoublyLinkedList<std::string>();

    std::ifstream binnacle(fileDir);

    std::string text;
    while (std::getline(binnacle, text)) {
        list->append(text);
    }
    return list;
}

int main() {
    DoublyLinkedList<std::string>* doublyLinkedList = new DoublyLinkedList<std::string>();
    //doublyLinkedList = readFile("./resources/bitacora.txt");

    // ---------------- Casos de prueba
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------- Casos de Prueba ------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;


    system("Pause");
    return 0;
}