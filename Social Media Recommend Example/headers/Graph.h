#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <string>
#include "Edge.h"

// Pair<Valor, nombre usuario>
typedef std::pair<int, std::string> Pair;

class Graph {
   public:
    int vertices;
    int edges;
    std::vector<std::vector<Pair>> adjList;

    /*
    Descripción: Cargue los arcos del grafo y los almacene en  una Lista de Adjacencia.
    Entrada: Vector de aristas y dos enteros representando la cantidad de vertices y arcos.
    Salida: Nada.
    Complejidad en el tiempo: O(E)
    Complejidad en el espacio: O(V + E)
    */
    Graph(std::vector<Edge> edges, int n, int m) {
        if (n <= 0) {
            throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. n=" + std::to_string(n));
        } else if (m <= 0) {
            throw std::invalid_argument("Cantidad de aristas no puede ser menor o igual a 0. m=" + std::to_string(m));
        }

        adjList.resize(n);
        this->vertices = n;
        this->edges = m;

        for (auto edge : edges) {
            // Agregar valores a la lista.
            addEdge(edge.start, edge.end, edge.startUser, edge.endUser);
        }
    }
    Graph(int n, int m, int time) {
        adjList.resize(n);
        this->vertices = n;
        this->edges = m;
    }

    /*
    Descripción: Agrega un edge a la matriz, cambiamos los valores falsos a verdaderos de los vertices correspondientes.
    Entrada: Nada.
    Parametros de salida(): Void
    Complejidad en el tiempo: O(1)
    Complejidad de espacio: O(V^2)
    */
    void addEdge(int init, int end, std::string userS, std::string userE) {
        adjList[init].push_back(std::make_pair(end, userE));
    }

    /*
    Descripción: Imprima el Recorrido de BFS (Anchura) a partir de nodo inicial.
    Entrada: Nodo inicial y cantidad de nodos vecinos a infectar.
    Salida: Cantidad de nodos infectados.
    Complejidad en el tiempo: O(V + E)
    Complejidad en el espacio: O(V^2)
    */
    int Publish(int start, std::string startUser, int n) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> queue;
        int cantNodos = 0;
        if (n == 0) {
            return cantNodos;
        }

        visited[start] = true;
        queue.push(start);
        cantNodos++;
        std::string output = "";
        std::cout << "La publicacion de " << startUser << " Puede ser vista por: ";

        bool seen = false;
        while (!queue.empty()) {
            // Cada amigo pasa la publicacion al siguiente.
            if (n == 0) {
                break;
            }
            n--;
            int currVertex = queue.front();
            queue.pop();

            for (auto i : adjList[currVertex]) {
                int adjVertex = i.first;
                std::string adjVertexValue = i.second;
                if (!visited[adjVertex]) {
                    seen = true;
                    output += adjVertexValue + ", ";
                    cantNodos++;
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }
        if (!seen) {
            std::cout << "Nadie";
        } else {
            std::string st = output.substr(0, output.size() - 2);
            std::cout << st;
        }
        std::cout << std::endl;
        return cantNodos;
    }
};
