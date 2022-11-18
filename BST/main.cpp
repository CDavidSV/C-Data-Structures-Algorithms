#include <iostream>

// Headers
#include "./headers/BST.h"

int main() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------- Casos de Prueba ------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;
    BST* testBST = new BST();

    std::cout << "--------------------- Agregar -----------------------" << std::endl;
    std::cout << "Agregar los valores: 12, 7, 21, 4, 9, 16, 25, 2, 8, 11, 19" << std::endl;
    testBST->add(12);
    testBST->add(7);
    testBST->add(21);
    testBST->add(4);
    testBST->add(9);
    testBST->add(16);
    testBST->add(25);
    testBST->add(2);
    testBST->add(8);
    testBST->add(11);
    testBST->add(19);

    std::cout << "-------------- Busqueda (1: Si, 0: No) ---------------" << std::endl;
    std::cout << "Buscar si existe 11: " << testBST->search(11) << std::endl;
    std::cout << "Buscar si existe 16: " << testBST->search(16) << std::endl;
    std::cout << "Buscar si existe 22: " << testBST->search(22) << std::endl;
    std::cout << "Buscar si existe 20: " << testBST->search(20) << std::endl;
    std::cout << "Buscar si existe 4: " << testBST->search(4) << std::endl;
    std::cout << std::endl;

    std::cout << "------------------ Visita: Preorden -----------------" << std::endl;
    testBST->visit(1);
    std::cout << std::endl;

    std::cout << "------------------ Visita: Inorden ------------------" << std::endl;
    testBST->visit(2);
    std::cout << std::endl;

    std::cout << "------------------ Visita: Postorden ----------------" << std::endl;
    testBST->visit(3);
    std::cout << std::endl;

    std::cout << "-------------- Visita: Nivel por nivel --------------" << std::endl;
    testBST->visit(4);
    std::cout << std::endl;

    std::cout << "---------------------- Altura -----------------------" << std::endl;
    std::cout << "La altura del arbol es: " << testBST->height() << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------- Ancestros ---------------------" << std::endl;
    std::cout << "Ancestros de 2: ";
    testBST->ancestors(2);
    std::cout << "Ancestros de 25: ";
    testBST->ancestors(25);
    std::cout << "Ancestros de 12: ";
    testBST->ancestors(12);
    std::cout << "Ancestros de 22: ";
    testBST->ancestors(22);
    std::cout << "Ancestros de 11: ";
    testBST->ancestors(11);
    std::cout << std::endl;

    std::cout << "------------------- WhatLevelAmI -------------------" << std::endl;
    std::cout << "12 Se encuentra en el nivel: " << testBST->whatLevelAmI(12) << std::endl;
    std::cout << "19 Se encuentra en el nivel: " << testBST->whatLevelAmI(19) << std::endl;
    std::cout << "9 Se encuentra en el nivel: " << testBST->whatLevelAmI(9) << std::endl;
    std::cout << "30 Se encuentra en el nivel: " << testBST->whatLevelAmI(30) << std::endl;
    std::cout << "4 Se encuentra en el nivel: " << testBST->whatLevelAmI(4) << std::endl;

    std::cout << "--------------------- Remover ---------------------" << std::endl;
    std::cout << "Remover nodos hoja: 8, 2, 11, 25" << std::endl;
    testBST->remove(8);
    testBST->remove(2);
    testBST->remove(11);
    testBST->remove(25);
    testBST->visit(4);
    std::cout << std::endl;

    std::system("pause");
}