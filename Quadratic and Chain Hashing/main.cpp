#include <iostream>
#include "./headers/ChainHash.h"
#include "./headers/QuadraticHash.h"

int main() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------- Casos de Prueba ------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;

    QuadraticHash qh1 = QuadraticHash(6);
    QuadraticHash qh2 = QuadraticHash(7);
    QuadraticHash qh3 = QuadraticHash(7);
    QuadraticHash qh4 = QuadraticHash(10);

    ChainHash ch1 = ChainHash(6);
    ChainHash ch2 = ChainHash(7);
    ChainHash ch3 = ChainHash(7);
    ChainHash ch4 = ChainHash(10);

    int arr1[6] = {12, 6, 5, 20, 6, 15};
    int arr2[5] = {15, 11, 27, 8, 12};
    int arr3[7] = {50, 700, 76, 85, 92, 73, 101};
    int arr4[10] = {50, 11, 15, 6, 5, 12, 300, 234, 32, 2};

    std::cout << "--------- Agregamos datos usando quadratic ---------" << std::endl;
    std::cout << "------------- Valor: -1 es no asignado -------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Agregamos: {12, 6, 5, 20, 6, 15}" << std::endl;
    qh1.quadratic(arr1, 6);
    qh1.displayHash();
    std::cout << std::endl;

    std::cout << "Agregamos: {15, 11, 27, 8, 12}" << std::endl;
    qh2.quadratic(arr2, 5);
    qh2.displayHash();
    std::cout << std::endl;

    std::cout << "Agregamos: {50, 700, 76, 85, 92, 73, 101}" << std::endl;
    qh3.quadratic(arr3, 7);
    qh3.displayHash();
    std::cout << std::endl;

    std::cout << "Agregamos: {50, 11, 15, 6, 5, 12, 300, 234, 32, 2}" << std::endl;
    qh4.quadratic(arr4, 10);
    qh4.displayHash();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "----------- Agregamos datos usando chain -----------" << std::endl;
    std::cout << std::endl;
    std::cout << "Agregamos: {12, 6, 5, 20, 6, 15}" << std::endl;
    ch1.chain(arr1, 6);
    ch1.displayHash();
    std::cout << std::endl;

    std::cout << "Agregamos: {15, 11, 27, 8, 12}" << std::endl;
    ch2.chain(arr2, 5);
    ch2.displayHash();
    std::cout << std::endl;

    std::cout << "Agregamos: {50, 700, 76, 85, 92, 73, 101}" << std::endl;
    ch3.chain(arr3, 7);
    ch3.displayHash();
    std::cout << std::endl;

    std::cout << "Agregamos: {50, 11, 15, 6, 5, 12, 300, 234, 32, 2}" << std::endl;
    ch4.chain(arr4, 10);
    ch4.displayHash();

    return 0;
}