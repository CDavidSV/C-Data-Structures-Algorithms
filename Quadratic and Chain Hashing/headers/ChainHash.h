#pragma once
#include <iostream>
#include <list>
#include <string>

class ChainHash {
   public:
    // Variables.
    int Bucket;
    std::list<int> *table;

    // Funciones.
    int hashFunction(int v) {
        return (v % this->Bucket);
    }

    // Constructor.
    ChainHash(int s) {
        if (s <= 0) {
            throw std::invalid_argument("El valor de tamaño no puede ser menor a 1. (s=" + std::to_string(s) + ")");
        }
        this->Bucket = s;
        this->table = new std::list<int>[s];
    }

    /*
    Descripción: Inserta un nuevo valor a la tabla de dispersión.
    Entrada: Valor entero a ser agregado.
    Salida: Nada.
    Complejidad en el tiempo: O(1)
    Complejidad en el espacio: O(1)
    */
    void insertItem(int k) {
        int index = hashFunction(k);

        table[index].push_back(k);
    }

    /*
    Descripción: Elimina un elemento de la tabla.
    Entrada: Valor entero a ser eliminado.
    Salida: Nada.
    Complejidad en el tiempo: O(1+(n/m))
    Complejidad en el espacio: O(1)
    */
    void deleteItem(int k) {
        int index = hashFunction(k);

        std::list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if (*i == k) {
                table[index].erase(i);
                break;
            }
        }
    }

    /*
    Descripción: Despliega todos los elementos de la tabla.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo: O(1+(n/m))
    Complejidad en el espacio: O(1)
    */
    void displayHash() {
        for (int i = 0; i < this->Bucket; i++) {
            std::cout << i;
            for (auto y : table[i]) {
                std::cout << " --> " << y;
            }
            std::cout << std::endl;
        }
    }

    /*
    Descripción:Inserta los elementos de un arreglo en el hash utilizando el metodo de encadenamiento.
    Entrada: Arreglo con los valores y el tamaño.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void chain(int itemsArray[], int size) {
        for (int i = 0; i < size; i++) {
            insertItem(itemsArray[i]);
        }
    }
};