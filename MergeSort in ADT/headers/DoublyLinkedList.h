#pragma once
#include <iostream>
#include "DNode.h"

template <class T>
class DoublyLinkedList {
   public:
    // Tamaño de la lista;
    int size = 0;

    // Constructor.
    DoublyLinkedList() {
        head = nullptr;
    }

    // Destructor.
    ~DoublyLinkedList() {
        if(!head) return;

        DNode<T>* currentNode = head;
        while(currentNode->nextNode != nullptr) {
            DNode<T>* temp = currentNode;
            currentNode = currentNode->nextNode;
            delete currentNode;
        }
    }

    /*
    Descripción: Agrega un nodo con cierto tipo de dato al final de una lista ligada y asigna el nodo siguiente al previo.
    Entrada: Nuevo valor de dato a agregar a la lista.
    Salida: Nada.
    Complejidad en el tiempo: O(1)
    Complejidad en el espacio: O(1)
    */
    void append(T data) {
        size++;

        // Creamos un nuevo nodo.
        DNode<T>* newNode = new DNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            last = newNode;
        } else {  // Si el primer nodo no es nulo lo agregamos al siguiente.
            // Asignamos el previo segun el ultimo nodo.
            newNode->prevNode = last;
            last->nextNode = newNode;
            last = newNode;
        }
    }

    /*
    Descripción: Agrega un nodo con cierto tipo de dato en el indice especificado y muevo los demas a la izquierda.
    Entrada: Indice y el nuevo valor de dato a agregar a la lista.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void add(int index, T data) {
        // Verificar el indice ingresado y que el primer nodo no sea nulo.
        if ((index > size - 1 || index < 0) || head == nullptr) {
            return;
        }

        DNode<T>* newNode = new DNode<T>(data);

        // Guardamos en una variable el nodo previo y el actual.
        DNode<T>* currentNode = head;
        DNode<T>* previousNode = nullptr;
        int currentIndex = 0;
        while (currentIndex < index && currentNode->nextNode != NULL) {  // Buscamos el nodo conb el indice correspondient segun el tamaño,
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
            currentIndex++;
        }
        // Cuando encontramos el indice lo agregamos y movemos el que ya se encontraba en esa posición.
        if (currentIndex == index) {
            DNode<T>* temp = currentNode;
            currentNode = newNode;
            currentNode->nextNode = temp;
            if (previousNode != nullptr) {  // En caso de que el nodo previo sea nulo, significa que es el primer nodo.
                previousNode->nextNode = currentNode;
                currentNode->prevNode = previousNode;  // Modificamos el nodo previo para el nodo actual.
            } else {
                head = newNode;
            }
            size++;
        }
    }

    /*
    Descripción: Remueve el ultimo nodo de la lista si es que existe.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void pop() {
        if (last == nullptr) {
            return;
        }

        DNode<T>* previous = nullptr;
        DNode<T>* current = head;

        int currentIndex = 0;
        while (currentIndex < size - 1) {  // Buscamos el ultimo nodo.
            previous = current;
            current = current->nextNode;
            currentIndex++;
        }

        // En caso de que sea el primer nodo.
        if (currentIndex == 0) {
            head = nullptr;
            last = nullptr;
            delete current;
        } else {  // Si no es lo removemos del final de la lista.
            last = previous;
            previous->nextNode = nullptr;
            delete current;
        }
        size--;
    }

    /*
    Descripción: Remueve el nodo especificado por el indice, en el caso de que exista.
    Entrada: Indice del nodo que se desea remover.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void remove(int index) {
        if ((index > size - 1 || index < 0) || head == nullptr) {
            return;
        }
        size--;

        DNode<T>* current = head;
        DNode<T>* previous = nullptr;
        DNode<T>* next = head->nextNode;

        int currentIndex = 0;
        while (currentIndex < index) {
            previous = current;
            current = current->nextNode;
            next = next->nextNode;
            currentIndex++;
        }

        // Si es el primer nodo, cambiamos el ultimo y el primero correspondientemente.
        if (currentIndex == 0) {
            head = current->nextNode;
            last = current->nextNode;
            delete current;
            return;
        }
        if (currentIndex == index) {
            previous->nextNode = current->nextNode;
            if (next != nullptr) {
                next->prevNode = current->prevNode;
            }
            if (current->nextNode == nullptr) {
                last = previous;
            }
            delete current;
        }
    }

    /*
    Descripción: Actualiza el valor de dato en un nodo especificado por su indice en el caso de que si exista.
    Entrada: Indice y el valor de dato a actualizar.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void update(int index, T data) {
        if ((index > size - 1 || index < 0) || head == nullptr) {
            return;
        }

        DNode<T>* modify = head;

        int current = 0;
        while (current < index && modify->nextNode != NULL) {
            modify = modify->nextNode;
            current++;
        }
        modify->data = data;
    }

    /*
    Descripción: Busca el nodo especificado por el indice y retorna el valor del dato almacenado en el mismo.
    Entrada:
    Salida: Retornara el dato que se encuetra el el nodo seleccionado tipo T (cualquier tipo de dato).
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    T* get(int index) {
        if ((index > size - 1 || index < 0) || head == nullptr) {      
            return NULL;
        }

        DNode<T>* result = head;

        // Retornamos el valor si el indice es 0.
        if (index == 0) {
            return &result->data;
        }

        // Si no es 0 entonces buscamos el valor en el indice correpondiente.
        int current = 0;
        while (current < index && result->nextNode != NULL) { // <---
            result = result->nextNode;
            current++;
        }
        return &result->data;
    }

    /*
    Descripción: Despliega la lista de una forma lineal.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void printList() {
        DNode<T>* currentNode = head;

        std::cout << "[";
        while (currentNode != NULL) {
            std::cout << currentNode->data;
            if (currentNode->nextNode != nullptr) {
                std::cout << ", ";
            }
            currentNode = currentNode->nextNode;
        }
        std::cout << "]";
        std::cout << std::endl;
    }

    /*
    Descripción: Despliega la lista por renglones.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void printInLine() {
        DNode<T>* currentNode = head;

        std::cout << "[" << std::endl;
        while (currentNode != NULL) {
            std::cout << "  " << currentNode->data;
            if (currentNode->nextNode != nullptr) {
                std::cout << ", " << std::endl;
            }
            currentNode = currentNode->nextNode;
        }
        std::cout << std::endl << "]";
        std::cout << std::endl;
    }

    /*
    Descripción: Despliega la lista de una forma lineal con un máximo establecido.
    Entrada: Cantidad de nodos que se quieren desplegar.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void printList(int maxPrint) {
        DNode<T>* currentNode = head;

        std::cout << "[";
        int currentIndex = 0;
        while (currentNode != NULL && currentIndex < maxPrint && currentIndex < size) {
            std::cout << currentNode->data;
            if (currentNode->nextNode != nullptr) {
                std::cout << ", ";
            }
            currentNode = currentNode->nextNode;
            currentIndex++;
        }
        std::cout << "]";
        std::cout << std::endl;
    }

    /*
    Descripción: Despliega la lista por renglones con un máximo establecido.
    Entrada: Cantidad de nodos que se quieren desplegar.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void printInLine(int maxPrint) {
        DNode<T>* currentNode = head;

        std::cout << "[" << std::endl;
        int currentIndex = 0;
        while (currentNode != NULL && currentIndex < maxPrint && currentIndex < size) {
            std::cout << "  " << currentNode->data;
            if (currentNode->nextNode != nullptr) {
                std::cout << ", " << std::endl;
            }
            currentNode = currentNode->nextNode;
            currentIndex++;
        }
        std::cout << std::endl << "]";
        std::cout << std::endl;
    }

    /*
    Descripción:
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo:
    Complejidad en el espacio:
    */
    void mergeSort() {

    }

   private:
    DNode<T>* head;
    DNode<T>* last;
};