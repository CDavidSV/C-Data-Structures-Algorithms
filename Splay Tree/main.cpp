#include <iostream>
#include <locale.h>
#include "./headers/SplayTree.h"
#include <windows.h>

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    SplayTree* splay = new SplayTree();

    // ---------------- Casos de prueba
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------- Casos de Prueba ------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------- Tamaño ---------------------" << std::endl;
    std::cout << splay->size() << std::endl;
    std::cout << std::endl;

    std::cout << "----------------- Agregar Datos ------------------" << std::endl;
    std::cout << "Agregamos: 5, 3, 6, 5, 2, 4" << std::endl;

    splay->insert(5);
    splay->insert(3);
    splay->insert(6);
    splay->insert(5);
    splay->insert(2);
    splay->insert(4);

    splay->printTree();
    std::cout << std::endl;

    std::cout << "--------------------- Tamaño ---------------------" << std::endl;
    std::cout << splay->size() << std::endl;
    std::cout << std::endl;

    std::cout << "----------------- Eliminar Datos -----------------" << std::endl;
    std::cout << "Eliminamos: 5, 6, 4, 200" << std::endl;
    splay->del(5);
    splay->del(6);
    splay->del(4);
    splay->del(200);

    splay->printTree();
    std::cout << std::endl;

    std::cout << "--------------------- Tamaño ---------------------" << std::endl;
    std::cout << splay->size() << std::endl;
    std::cout << std::endl;

    std::cout << "----------------- Agregar Datos ------------------" << std::endl;
    std::cout << "Agregamos: 5, 6, 4, 8, 9, 9" << std::endl;
    splay->insert(5);
    splay->insert(6);
    splay->insert(4);
    splay->insert(8);
    splay->insert(9);
    splay->insert(9);
    std::cout << std::endl;

    std::cout << "------------ Busqueda (1: Si, 0: No) ------------" << std::endl;
    std::cout << "Buscamos: 4" << std::endl;
    std::cout << "Encontrado: " << splay->find(4) << std::endl;
    splay->printTree();
    std::cout << std::endl;
    std::cout << "Buscamos: 5" << std::endl;
    std::cout << "Encontrado: " << splay->find(5) << std::endl;
    splay->printTree();
    std::cout << std::endl;
    std::cout << "Buscamos: 3" << std::endl;
    std::cout << "Encontrado: " << splay->find(3) << std::endl;
    splay->printTree();
    std::cout << std::endl;
    std::cout << "Buscamos: 2" << std::endl;
    std::cout << "Encontrado: " << splay->find(2) << std::endl;
    splay->printTree();
    std::cout << std::endl;
    std::cout << "Buscamos: 10" << std::endl;
    std::cout << "Encontrado: " << splay->find(10) << std::endl;
    splay->printTree();
    std::cout << std::endl;

    std::cout << "------------------ imprimir --------------------" << std::endl;
    splay->print();
    std::cout << std::endl;

    system("Pause");
    return 0;
}