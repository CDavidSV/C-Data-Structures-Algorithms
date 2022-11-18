// FuncionesSuma.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

// Calcula la sumatoria de 1 hasta n de manera iterativa.
int sumaIterativa(int n) {
    if (n < 0) return 0;
    int suma = 0;
    for (int i = 1; i <= n; i++) { // El ciclo aumenta el valor de suma hasta llegar a n.
        suma += i;
    }
    return suma;
}

// Calcula la sumatoria de 1 hasta n de manera Recursiva.
int sumaRecursiva(int n) {
    if (n < 0) return 0;
    if (n <= 1) { // Cuando n sea 1 se retorna 1.
        return n;
    }
    return n + sumaRecursiva(n - 1); // Cada llamada recursiva se suma al total.
}

// Calcula la sumatoria de 1 hasta n de manera Directa usando la formula de gauss.
int sumaDirecta(int n) {
    if (n < 0) return 0;
    return n * (n + 1) / 2; // Formula de gauss.
}

int main()
{
    // Casos de prueba.
    std::cout << "-----------------------------" << std::endl;
    std::cout << "------ Casos de Prueba ------" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::cout << "Funcion: sumaIterativa(n)" << std::endl;
    std::cout << "1.caso n = 12: " << sumaIterativa(12) << std::endl;
    std::cout << "2.caso n = 4: " << sumaIterativa(4) << std::endl;
    std::cout << "3.caso n = 20: " << sumaIterativa(20) << std::endl;
    std::cout << "4.caso n = 1: " << sumaIterativa(1) << std::endl;

    std::cout << std::endl;

    std::cout << "Funcion: sumaRecursiva(n)" << std::endl;
    std::cout << "1.caso n = 12: " << sumaRecursiva(12) << std::endl;
    std::cout << "2.caso n = 4: " << sumaRecursiva(4) << std::endl;
    std::cout << "3.caso n = 20: " << sumaRecursiva(20) << std::endl;
    std::cout << "4.caso n = 1: " << sumaRecursiva(1) << std::endl;
    
    std::cout << std::endl;

    std::cout << "Funcion: sumaDirecta(n)" << std::endl;
    std::cout << "1.caso n = 12: " << sumaDirecta(12) << std::endl;
    std::cout << "2.caso n = 4: " << sumaDirecta(4) << std::endl;
    std::cout << "3.caso n = 20: " << sumaDirecta(20) << std::endl;
    std::cout << "4.caso n = 1: " << sumaDirecta(1) << std::endl;
}