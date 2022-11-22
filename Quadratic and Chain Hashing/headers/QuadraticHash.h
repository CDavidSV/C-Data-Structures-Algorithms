#pragma once
#include <iostream>
#include <list>
#include <string>

class QuadraticHash {
   public:
    // Variables.
    int Bucket;
    int *table;

    // Funciones.
    int hashFunction(int v) {
        return (v % this->Bucket);
    }

    // Constructor.
    QuadraticHash(int s) {
        if (s <= 0) {
            throw std::invalid_argument("El valor de tamaño no puede ser menor a 1. (s=" + std::to_string(s) + ")");
        }
        this->Bucket = s;
        this->table = new int[s];

        for (int i = 0; i < s; i++) {
            table[i] = -1;
        }
    }

    /*
    Descripción: Despliega todos los elementos de la tabla.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void displayHash() {
        for (int i = 0; i < this->Bucket; i++) {
            std::cout << table[i] << " ";
        }
        std::cout << std::endl;
    }

    /*
    Descripción: Inserta un nuevo valor a la tabla.
    Entrada: Valor entero a ser agregado.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void insertItem(int k) {
        int index = hashFunction(k);

        if (table[index] == -1) {
            table[index] = k;
        } else {
            for (int j = 0; j < this->Bucket; j++) {
                int newIndex = hashFunction(index + j * j);
                if (table[newIndex] == -1) {
                    table[newIndex] = k;
                    break;
                }
            }
        }
    }

    /*
    Descripción: Elimina un elemento de la tabla.
    Entrada: Valor entero a ser eliminado.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void deleteItem(int k) {
        int index = hashFunction(k);

        if (table[index] == k) {
            table[index] = -1;
        } else {
            for (int i = 0; i < this->Bucket; i++) {
                int newIndex = hashFunction(index + i * i);
                if (table[newIndex] == k) {
                    table[newIndex] = -1;
                    break;
                }
            }
        }
    }

    /*
    Descripción: Inserta los elementos de un arreglo en el hash utilizando el metodo cuadrático.
    Entrada: Arreglo con elementos de entrada y el tamaño del arreglo.
    Salida: Nada.
    Complejidad en el tiempo: O(N * L)
    Complejidad en el espacio: O(1)
    */
    void quadratic(int itemsArray[], int size) {
        for (int i = 0; i < size; i++) {
            insertItem(itemsArray[i]);
        }
    }
};