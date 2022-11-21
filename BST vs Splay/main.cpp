#include <iostream>
#include <locale.h>
#include "./headers/SplayTree.h"
#include "./headers/Ip.h"
#include "./headers/BST.h"
#include <windows.h>
#include <vector>
#include <fstream>
#include <time.h>
#include <iomanip>

// Struct para retornar los dos arboles y un vector en la función de leer archivo.
struct ds {
    SplayTree* splay;
    BST* bst;
    std::vector<Ip>* vec;
};

// Lee el archivo de bitacora y retorna un struct de tipo "trees" que contiene el bst y splayTree.
ds readFile(std::string fileDir, int option) {
    // Crear el splay para almacenar las ips.
    SplayTree* splayIps = new SplayTree();
    BST* BSTips = new BST();
    std::vector<Ip>* vec = new std::vector<Ip>();

    // leemos el archivo de texto.
    std::ifstream bitacora(fileDir);

    // Leemos el archivo y agregamos los datos a un vector.
    std::string text;
    while (std::getline(bitacora, text)) {
        std::vector<std::string> record;

        // Agarrar cada caracter de cada linea de la bitacora.
        std::string word = "";
        for (char i : text) {
            if (i == ' ') {  // Separamos si encontramos un espacio o doble punto.
                record.push_back(word);
                word = "";
            } else {
                word += i;
            }
        }
        Ip newIp = Ip(record[3]);

        if (option == 1) {
            vec->push_back(newIp);
        } else if (option == 2) {
            splayIps->insert(newIp);
            BSTips->add(newIp);
        }
    }

    // Cerrar el archivo.
    bitacora.close();

    // retornar el vector.
    ds collectedTrees;
    collectedTrees.splay = splayIps;
    collectedTrees.bst = BSTips;
    collectedTrees.vec = vec;

    return collectedTrees;
}

void compareExecutionTime(SplayTree* splay, BST* bst, std::vector<Ip>* vector) {
    // Declarar variables para el tiempo.
    clock_t startBST, endBST, startSplay, endSplay;

    // Buscar las ip en el BST.bool foundIp;
    startBST = clock();
    for (auto& ipValue : *vector) {
        bst->search(ipValue);
    }
    endBST = clock();

    // Buscar las ip en el Splay Tree.
    startSplay = clock();
    for (auto& ipValue : *vector) {
        splay->find(ipValue);
    }
    endSplay = clock();

    std::cout << " " << std::right << std::setw(50) << std::setfill('-') << "" << std::endl;
    std::cout << std::right << std::setw(35) << std::setfill(' ') << "Tiempos de Ejecución";
    std::cout << std::endl;
    std::cout << " * Buscar " << vector->size() << " ips";
    std::cout << std::endl;

    std::cout << "    - BST tardo: " << (double)(endBST - startBST) / CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "    - Splay Tree tardo: " << (double)(endSplay - startSplay) / CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << std::endl;
    std::cout << " " << std::right << std::setw(50) << std::setfill('-') << "" << std::endl;

    std::cout << std::endl;
};

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // IMPORTANTE: Agregar mas casos de prueba.
    // Cargar los datos con la bitacora desordenada en los arboles BST y splay.
    ds trees = readFile("./resources/bitacora.txt", 2);
    SplayTree* splay = trees.splay;
    BST* bst = trees.bst;

    // Cargar los datos de la bitacora ordenada en un vector para realizar la busqueda en los arboles.
    std::vector<Ip>* vector = readFile("./resources/bitacoraOrdenada.txt", 1).vec;

    compareExecutionTime(splay, bst, vector);

    std::cout << "Agregar dos ips más:" << std::endl;
    std::cout << "Agregamos: 106.104.111:3000 y 308.234.103:2896" << std::endl;
    Ip newIp1 = Ip("106.104.111:3000");
    Ip newIp2 = Ip("308.234.103:2896");
    bst->add(newIp1);
    splay->insert(newIp1);
    bst->add(newIp2);
    splay->insert(newIp2);
    vector->push_back(newIp1);
    vector->push_back(newIp2);

    compareExecutionTime(splay, bst, vector);

    system("Pause");
    return 0;
}