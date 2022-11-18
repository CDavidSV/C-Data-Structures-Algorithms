#include <iostream>
#include <windows.h>

// Heap Priority Queue.
#include "./headers/PriorityQueue.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    // Casos de prueba.

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------- Casos de Prueba ------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;

    // Declaramos nuestra lista de prioridad con 10 elementos como máximo.
    PriorityQueue* queue = new PriorityQueue();

    std::cout << "Probar si esta vacia la lista (1: Si, 0: No): ";
    std::cout << queue->empty() << std::endl;
    std::cout << std::endl;

    std::cout << "Obtener el elemento con mayor prioridad (0: NULL): ";
    std::cout << queue->top() << std::endl;
    std::cout << std::endl;

    std::cout << "Obtener el tamaño: ";
    std::cout << queue->size() << std::endl;
    std::cout << std::endl;

    std::cout << "Agregar datos: 5, 7, 8, 9, 10, 12, 5" << std::endl;
    queue->push(5);
    queue->push(7);
    queue->push(8);
    queue->push(9);
    queue->push(10);
    queue->push(12);
    queue->push(5);
    std::cout << "Desplegar: ";
    queue->print();
    std::cout << std::endl;

    std::cout << "Probar si esta vacia la lista (1: Si, 0: No): ";
    std::cout << queue->empty() << std::endl;
    std::cout << std::endl;

    std::cout << "Obtener el elemento con mayor prioridad (0: NULL): ";
    std::cout << queue->top() << std::endl;
    std::cout << std::endl;

    std::cout << "Obtener el tamaño: ";
    std::cout << queue->size() << std::endl;
    std::cout << std::endl;

    std::cout << "Removemos 4 datos: ";
    queue->print();
    queue->pop();
    queue->print();
    queue->pop();
    queue->print();
    queue->pop();
    queue->print();
    queue->pop();
    queue->print();
    std::cout << std::endl;

    std::cout << "Obtener el tamaño: ";
    std::cout << queue->size() << std::endl;
    std::cout << std::endl;

    std::cout << "Obtener el elemento con mayor prioridad (0: NULL): ";
    std::cout << queue->top() << std::endl;
    std::cout << std::endl;

    std::cout << "Agregamos 30 como un nuevo valor para comprobar el metodo top(): ";
    queue->push(30);
    std::cout << "Desplegar: ";
    queue->print();
    std::cout << std::endl;

    std::cout << "Obtener el elemento con mayor prioridad (0: NULL): ";
    std::cout << queue->top() << std::endl;
    std::cout << std::endl;

    std::cout << "Removemos todos los valores : ";
    queue->print();
    queue->pop();
    queue->print();
    queue->pop();
    queue->print();
    queue->pop();
    queue->print();
    queue->pop();
    queue->print();
    std::cout << std::endl;

    std::cout << "Obtener el tamaño: ";
    std::cout << queue->size() << std::endl;
    std::cout << std::endl;

    std::cout << "Agregar datos: 10, 12" << std::endl;
    queue->push(10);
    queue->push(12);
    std::cout << "Desplegar: ";
    queue->print();
    std::cout << std::endl;

    std::system("pause");
    return 0;
}