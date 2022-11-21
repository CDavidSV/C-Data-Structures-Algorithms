#pragma once
#include <iostream>

class PriorityQueue {
   private:
    int* heapArray;
    int heapSize = 0;

    /*
    Descripción: Intercambia dos valores dentro de un arreglo
    Entrada: Dos indices correspondientes a los valores que se desean intercambiar.
    Salida: Nada.
    Complejidad en el tiempo: O(1)
    Complejidad en el espacio: O(1)
    */
    void swap(int index1, int index2) {
        int temp = heapArray[index1];
        heapArray[index1] = heapArray[index2];
        heapArray[index2] = temp;
    }

    /*
    Descripción: Intercambia el nodo hijo con su padre hasta que el heap este satisfecho y cumpla
    con su prioridad.
    Entrada: Indice correspondiente al tamaño del arreglo o heap.
    Salida: Nada.
    Complejidad en el tiempo: O(log(n))
    Complejidad en el espacio: O(1)
    */
    void swiftUp(int index) {
        while (index > 0 && heapArray[(index - 1) / 2] < heapArray[index]) {
            swap((index - 1) / 2, index);

            index = (index - 1) / 2;
        }
    }

    /*
    Descripción: Intercambia el nodo padre con su hijo menor hasta que el heap este satisfecho y cumpla
    con su prioridad.
    Entrada: Indice correspondiente al padre o raiz.
    Salida: Nada.
    Complejidad en el tiempo: O(log(n))
    Complejidad en el espacio: O(n)
    */
    void swiftDown(int rootIndex) {
        int max = rootIndex;
        int left = (2 * rootIndex) + 1;
        int right = (2 * rootIndex) + 2;

        if (left < heapSize && heapArray[max] < heapArray[left]) {
            max = left;
        }
        if (right < heapSize && heapArray[max] < heapArray[right]) {
            max = right;
        }

        if (max != rootIndex) {
            swap(max, rootIndex);
            swiftDown(max);
        }
    }

   public:
    // Constructors.
    PriorityQueue(const int maxSize) {
        heapArray = new int[maxSize];
    }
    PriorityQueue() {
        heapArray = new int[1000];
    }

    // Destructor.
    ~PriorityQueue() {
        delete[] heapArray;
    }

    /*
    Descripción: Agregue un dato a la fila priorizada.
    Entrada: Un entero, el cual se desea agregar a la fila priorizada.
    Salida: Nada.
    Complejidad en el tiempo: O(log(n)) - Por swiftUp()
    Complejidad en el espacio: O(1) - Por swiftUp()
    */
    void push(int newValue) {
        heapArray[heapSize] = newValue;
        heapSize++;

        if (heapSize > 1) {
            swiftUp(heapSize - 1);
        }
    }

    /*
    Descripción: Saca de la fila priorizada el dato que tiene mayor prioridad.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo: O(log(n)) - Por swiftDown()
    Complejidad en el espacio: O(n) - Por swiftDown()
    */
    void pop() {
        int temp = heapArray[heapSize - 1];
        heapArray[heapSize - 1] = heapArray[0];
        heapArray[0] = temp;
        heapSize--;

        if (heapSize > 1) {
            swiftDown(0);
        }
    }

    /*
    Descripción: Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
    Entrada: Nada.
    Salida: El dato que tiene mayor prioridad dentro de la Fila priorizada.
    */
    int top() {
        if (heapSize == 0) return NULL;
        return heapArray[0];
    }

    /*
    Descripción: Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
    Entrada: Nada.
    Salida: Un valor boleano que diga si la fila priorizada esta vacía o tiene datos.
    */
    bool empty() {
        if (heapSize == 0) return true;
        return false;
    }

    /*
    Descripción: Regresa la cantidad de datos que tiene la fila priorizada.
    Entrada: Nada.
    Salida: Salida Un valor entero que represena la cantidad de datos de la fila priorizada.
    */
    int size() {
        return heapSize;
    }

    /*
    Descripción: Despliega todos los valores de la fila priorizada.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void print() {
        for (int i = 0; i < heapSize; i++) {
            std::cout << heapArray[i] << " ";
        }
        std::cout << std::endl;
    }

    /*
    Descripción: Despliega los valores hasta el máximo especificad0.
    Entrada: Número máximo de valores que se deben de desplegar.
    Salida: Nada.
    Complejidad en el tiempo: O(1)
    Complejidad en el espacio: O(1)
    */
    void print(int maxElements) {
        if (maxElements > heapSize || maxElements < 0) {
            std::cout << "Error: entrada de tamaño fuera de rango." << std::endl;
        }

        for (int i = 0; i < maxElements; i++) {
            std::cout << heapArray[i] << " ";
        }
        std::cout << std::endl;
    }
};