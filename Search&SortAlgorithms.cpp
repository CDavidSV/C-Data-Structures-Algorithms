// AlgoritmosOrdenamientoYBusqueda.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Alumno: Carlos David Sandoval Vargas
// Matr�cula: A00834448

#include <iostream>
#include <vector>
#include <string>

// Muestra el vector en la terminal.
void displayVector(std::vector<int> arr) {
    for (char i : arr) {
        std::cout << std::to_string(i) << " ";
    }
    std::cout << std::endl;
}

// Intercambia dos elementos de un vector.
void swap(std::vector<int>& arr, int index1, int index2) {
    int aux = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = aux;
}

// Mezcla el vector de manera aleatoria.
void shuffle(std::vector<int>& arr) {
    int randomIndex;
    int min = 0;
    int max = arr.size();
    for (int i = 0; i < arr.size(); i++) {
        randomIndex = rand() % (max - min);
        swap(arr, i, randomIndex);
    }
}

// ---------------- Algoritmos de Ordenamiento ----------------

/*
Descripción: Ordena los elementos de forma ascendente usando el metodo de inserci�n.
Entrada: Un vector de tipo entero con todos los valores.
Salida: No retornar� nada.
Complejidad en el tiempo: O(n^2)
Complejidad en el espacio: O(1)
*/
void InsertionSort(std::vector<int>& arr) {
    int j;
    int aux;
    for (int i = 1; i < arr.size(); i++) {
        aux = arr[i];

        j = i - 1;
        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = aux;
    }
}

/*
Descripción: Ordena los elementos de forma ascendente usando el metodo de burbuja.
Entrada: Un vector de tipo entero con todos los valores.
Salida: No retornará nada.
Complejidad en el tiempo: O(n^2)
Complejidad en el espacio: O(1)
*/
void bubbleSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                swapped = true;
            };
        }
        if (!swapped) {
            break;
        }
    }
}

/*
Descripción: Ordena los elementos de un vector de forma ascendente usando el metodo de Merge.
Entrada: Un vector de tipo entero con todos los valores.
Salida: No retornará nada.
Complejidad en el tiempo: O(n*log(n))
Complejidad en el espacio: O(n)
*/
void merge(std::vector<int>& arr, int start, int end, int mid) {
    int leftSubArrayLength = mid - start + 1;
    int rightSubArrayLength = end - mid;

    // Crear los arreglos temporales.
    std::vector<int> leftSubArray;
    std::vector<int> rightSubArray;

    // Asignar valores a los arreglos temporales.
    for (int i = 0; i < leftSubArrayLength; i++)
        leftSubArray.push_back(arr[start + i]);
    for (int j = 0; j < rightSubArrayLength; j++)
        rightSubArray.push_back(arr[mid + 1 + j]);

    int indexSubArrayOne = 0;
    int indexSubArrayTwo = 0;
    int indexMergedArray = start;

    // Copiar los elementos al arreglo principal dependiendo de cual sea m�s grande.
    while (indexSubArrayOne < leftSubArrayLength && indexSubArrayTwo < rightSubArrayLength) {
        if (leftSubArray[indexSubArrayOne] <= rightSubArray[indexSubArrayTwo]) {
            arr[indexMergedArray] = leftSubArray[indexSubArrayOne];
            indexSubArrayOne++;
        } else {
            arr[indexMergedArray] = rightSubArray[indexSubArrayTwo];
            indexSubArrayTwo++;
        }
        indexMergedArray++;
    }

    // Mover los elementos restantes de cada sub-arreglo creado si es que quedan algunos.
    while (indexSubArrayOne < leftSubArrayLength) {
        arr[indexMergedArray] = leftSubArray[indexSubArrayOne];
        indexSubArrayOne++;
        indexMergedArray++;
    }
    while (indexSubArrayTwo < rightSubArrayLength) {
        arr[indexMergedArray] = rightSubArray[indexSubArrayTwo];
        indexSubArrayTwo++;
        indexMergedArray++;
    }
}
void mergeSort(std::vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end, mid);
}

int partition(std::vector<int> &arr, int low, int high) {
  // Escojer el pivote que en este caso es el ultimo.
  int pivot = arr[high];

  // Indice que indica la posición en la que se encontrara el pivote.
  int index = low - 1;

  for (int i = low; i <= high - 1; i++) {
    if (arr[i] < pivot) {
      index++;

      swap(arr, i, index);
    }
  }
  swap(arr, index + 1, high);

  return index + 1;
}

/*
Descripción: Ordena los elementos de un vector de forma ascendente usando el
metodo de quicksort. Entrada: Un vector de tipo entero con todos los valores.
Salida: No retornará nada.
Complejidad en el tiempo: O(n*logn)
Complejidad en el espacio: O(logn)
*/
void quickSort(std::vector<int> &arr, int start, int end) {
  
  if (start < end) {
    int ptn = partition(arr, start, end);

    quickSort(arr, start, ptn - 1);
    quickSort(arr, ptn + 1, end);
  }
}

// ------------------ Algoritmos de Busqueda ------------------

/*
Descripción: Busca un elemento especificado en un vector de manera secuencial.
Entrada: Un vector de tipo entero con todos los valores y el n�mero entero que se desea encontrar.
Salida: Retornará el indice en el que se encuentra el número.
Complejidad en el tiempo: O(n)
Complejidad en el espacio: O(1)
*/
int sequentialSearch(std::vector<int> arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

/*
Descripción: Busca un elemento especificado en un vector de manera binaria.
Entrada: Un vector de tipo entero con todos los valores y el n�mero entero que se desea encontrar.
Salida: Retornará el indice en el que se encuentra el número.
Complejidad en el tiempo: O(log(n))
Complejidad en el espacio: O(1)
*/
int binarySearch(std::vector<int> arr, int target) {
    int leftPointer = 0;
    int rightPointer = arr.size() - 1;

    while (leftPointer <= rightPointer) {
        int mid = leftPointer + (rightPointer - leftPointer) / 2;

        // Revisamos si el valor del medio es igual al que buscamos.
        if (arr[mid] == target) return mid;

        // Si el valor que buscamos el mayor al del medio, buscamos en la otra mitad.
        if (arr[mid] < target) {
            leftPointer = mid + 1;
        } else {  // Si es menor.
            rightPointer = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Casos de prueba.

    // Arreglos Desordenados (Para probar los algoritmos de ordenamiento).
    std::vector<int> arr1{50, 20, 39, 11, 42, 73, 4, 74, 35, 30, 18, 27, 2, 85, 17, 66, 81, 84, 92, 1, 94, 61, 47, 52, 99, 88, 30, 70, 76, 87};
    std::vector<int> arr2{19, 53, 42, 90, 26, 77, 70, 33, 44, 37, 67, 0, 49, 5, 34, 63, 50, 23, 10, 85, 74, 11, 42, 13, 54, 34, 34, 29, 89, 6};
    std::vector<int> arr3{60, 74, 56, 30, 47, 62, 94, 61, 59, 47, 75, 40, 64, 7, 57, 65, 92, 72, 18, 16, 61, 24, 20, 45, 99, 26, 54, 52, 50, 61};
    std::vector<int> arr4{17, 82, 90, 69, 17, 26, 88, 81, 26, 92, 77, 18, 14, 100, 11, 0, 66, 43, 77, 72, 86, 87, 50, 30, 7, 15, 40, 51, 42, 9};

    // Arreglos ordenados (Para probar los algoritmos de busqueda).
    std::vector<int> arr5{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33};
    std::vector<int> arr6{4, 24, 25, 27, 28, 29, 42, 46, 47, 48, 49, 50, 51, 53, 54, 58, 63, 67, 70, 71, 73, 76, 80, 82, 86, 91, 94, 96, 97, 98};

    // Primero se mezcla el arreglo y luego lo ordenamos (repetimos esto para cada caso de prueba y con cada uno de los 4 arreglos).
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "---------- Algoritmos de Ordenamiento ----------" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "---------- Insertion Sort ----------" << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 1: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr1);
    displayVector(arr1);
    std::cout << "Arreglo Ordenado: " << std::endl;
    InsertionSort(arr1);
    displayVector(arr1);
    std::cout << std::endl;

    std::cout << "Caso 2: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr2);
    displayVector(arr2);
    std::cout << "Arreglo Ordenado: " << std::endl;
    InsertionSort(arr2);
    displayVector(arr2);
    std::cout << std::endl;

    std::cout << "Caso 3: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr3);
    displayVector(arr3);
    std::cout << "Arreglo Ordenado: " << std::endl;
    InsertionSort(arr3);
    displayVector(arr3);
    std::cout << std::endl;

    std::cout << "Caso 4: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr4);
    displayVector(arr4);
    std::cout << "Arreglo Ordenado: " << std::endl;
    InsertionSort(arr4);
    displayVector(arr4);
    std::cout << std::endl;

    std::cout << "----------- Bubble Sort -----------" << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 1: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr1);
    displayVector(arr1);
    std::cout << "Arreglo Ordenado: " << std::endl;
    bubbleSort(arr1);
    displayVector(arr1);
    std::cout << std::endl;

    std::cout << "Caso 2: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr2);
    displayVector(arr2);
    std::cout << "Arreglo Ordenado: " << std::endl;
    bubbleSort(arr2);
    displayVector(arr2);
    std::cout << std::endl;

    std::cout << "Caso 3: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr3);
    displayVector(arr3);
    std::cout << "Arreglo Ordenado: " << std::endl;
    bubbleSort(arr3);
    displayVector(arr3);
    std::cout << std::endl;

    std::cout << "Caso 4: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr4);
    displayVector(arr4);
    std::cout << "Arreglo Ordenado: " << std::endl;
    bubbleSort(arr4);
    displayVector(arr4);
    std::cout << std::endl;

    std::cout << "------------ Merge Sort ------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 1: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr1);
    displayVector(arr1);
    std::cout << "Arreglo Ordenado: " << std::endl;
    mergeSort(arr1, 0, arr1.size() - 1);
    displayVector(arr1);
    std::cout << std::endl;

    std::cout << "Caso 2: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr2);
    displayVector(arr2);
    std::cout << "Arreglo Ordenado: " << std::endl;
    mergeSort(arr2, 0, arr2.size() - 1);
    displayVector(arr2);
    std::cout << std::endl;

    std::cout << "Caso 3: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr3);
    displayVector(arr3);
    std::cout << "Arreglo Ordenado: " << std::endl;
    mergeSort(arr3, 0, arr3.size() - 1);
    displayVector(arr3);
    std::cout << std::endl;

    std::cout << "Caso 4: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr4);
    displayVector(arr4);
    std::cout << "Arreglo Ordenado: " << std::endl;
    mergeSort(arr4, 0, arr4.size() - 1);
    displayVector(arr4);
    std::cout << std::endl;

    std::cout << "------------ Quick Sort ------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 1: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr1);
    displayVector(arr1);
    std::cout << "Arreglo Ordenado: " << std::endl;
    quickSort(arr1, 0, arr1.size() - 1);
    displayVector(arr1);
    std::cout << std::endl;

    std::cout << "Caso 2: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr2);
    displayVector(arr2);
    std::cout << "Arreglo Ordenado: " << std::endl;
    quickSort(arr2, 0, arr2.size() - 1);
    displayVector(arr2);
    std::cout << std::endl;

    std::cout << "Caso 3: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr3);
    displayVector(arr3);
    std::cout << "Arreglo Ordenado: " << std::endl;
    quickSort(arr3, 0, arr3.size() - 1);
    displayVector(arr3);
    std::cout << std::endl;

    std::cout << "Caso 4: " << std::endl;
    std::cout << "Arreglo Desordenado: " << std::endl;
    shuffle(arr4);
    displayVector(arr4);
    std::cout << "Arreglo Ordenado: " << std::endl;
    quickSort(arr4, 0, arr4.size() - 1);
    displayVector(arr4);
    std::cout << std::endl;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "------------ Algoritmos de Busqueda ------------" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "---------- Busqueda Secuencial ----------" << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 1: " << std::endl;
    std::cout << "Valor que se busca: 10" << std::endl;
    std::cout << "Indice en el que se encuentra: " << sequentialSearch(arr1, 10) << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 2: " << std::endl;
    std::cout << "Valor que se busca: 53" << std::endl;
    std::cout << "Indice en el que se encuentra: " << sequentialSearch(arr2, 53) << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 3: " << std::endl;
    std::cout << "Valor que se busca: 12" << std::endl;
    std::cout << "Indice en el que se encuentra: " << sequentialSearch(arr3, 12) << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 4: " << std::endl;
    std::cout << "Valor que se busca: 5" << std::endl;
    std::cout << "Indice en el que se encuentra: " << sequentialSearch(arr4, 5) << std::endl;
    std::cout << std::endl;

    // Prueba con usuario.
    int searches;
    int target;
    std::cout << "Ingrese la cantidad de Busquedas que desea: ";
    std::cin >> searches;
    std::cout << std::endl;

    for (int i = 0; i < searches; i++) {
        displayVector(arr5);
        std::cout << "Ingrese el numero que desea encontrar: ";
        std::cin >> target;
        std::cout << std::endl;

        int index = sequentialSearch(arr5, target);

        if (index < 0) {
            std::cout << index;
            std::cout << std::endl;
        } else {
            std::cout << "Indice en el que se encuentra: " << index << std::endl;
            std::cout << std::endl;
        }
    }

    std::cout << "---------- Busqueda Binaria ----------" << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 1: " << std::endl;
    std::cout << "Valor que se busca: 10" << std::endl;
    std::cout << "Indice en el que se encuentra: " << binarySearch(arr6, 10) << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 2: " << std::endl;
    std::cout << "Valor que se busca: 53" << std::endl;
    std::cout << "Indice en el que se encuentra: " << binarySearch(arr6, 53) << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 3: " << std::endl;
    std::cout << "Valor que se busca: 12" << std::endl;
    std::cout << "Indice en el que se encuentra: " << binarySearch(arr6, 12) << std::endl;
    std::cout << std::endl;

    std::cout << "Caso 4: " << std::endl;
    std::cout << "Valor que se busca: 5" << std::endl;
    std::cout << "Indice en el que se encuentra: " << binarySearch(arr6, 5) << std::endl;
    std::cout << std::endl;

    // Prueba con usuario.
    std::cout << "Ingrese la cantidad de Busquedas que desea: ";
    std::cin >> searches;
    std::cout << std::endl;

    for (int i = 0; i < searches; i++) {
        displayVector(arr6);
        std::cout << "Ingrese el numero que desea encontrar: ";
        std::cout << std::endl;

        int index = sequentialSearch(arr6, target);

        if (index < 0) {
            std::cout << index << std::endl;
            std::cout << std::endl;
        } else {
            std::cout << "Indice en el que se encuentra: " << index << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}