#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <stack>
#include <queue>

// Pair<Valor, Peso>
typedef std::pair<int, int> Pair;

class Edge {
   public:
    int start;
    int end;
    int weight;

    Edge(int startV, int endV, int weightV) {
        start = startV;
        end = endV;
        weight = weightV;
    }
};

class Graph {
   public:
    // Vertices y arcos.
    int vertices;
    int edges;

    // Vector
    std::vector<std::vector<Pair>> adjList;

    // Constructor.
    Graph() {}

    /*
    Descripción: Cargue los arcos del grafo y los almacene en  una Lista de Adjacencia.
    Entrada: Vector de aristas y dos enteros representando la cantidad de vertices y arcos.
    Salida: Nada.
    Complejidad en el tiempo: O(E)
    Complejidad en el espacio: O(V + E)
    */
    void loadGraph(std::vector<Edge> edges, int n, int m) {
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
            adjList[edge.start].push_back(std::make_pair(edge.end, edge.weight));
        }
    }
};

/*
Descripción: Imprima el Recorrido de DFS (Profundidad) a partir de nodo inicial.
Entrada: Lista de adjacencia, nodo inicial, n (cantidad de vertices) y m (Arcos).
Salida: Nada.
Complejidad en el tiempo: O(V + E)
Complejidad en el espacio: O(V)
*/
void DFS(std::vector<std::vector<Pair>> adjList, int init, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. n=" + std::to_string(n));
    }

    std::vector<bool> visited(n, false);

    std::stack<int> stack;
    stack.push(init);

    while (!stack.empty()) {
        int s = stack.top();
        stack.pop();

        if (!visited[s]) {
            std::cout << s << " ";
            visited[s] = true;
        }

        for (auto i : adjList[s]) {
            if (!visited[i.first]) {
                stack.push(i.first);
            }
        }
    }
}

/*
Descripción: Imprima el Recorrido de BFS (Anchura) a partir de nodo inicial.
Entrada: Lista de adjacencia, nodo inicial y n (cantidad de vertices).
Salida: Nada.
Complejidad en el tiempo: O(V + E)
Complejidad en el espacio: O(V^2)
*/
void BFS(std::vector<std::vector<Pair>> adjList, int init, int n) {
    if (n <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. n=" + std::to_string(n));
    }

    std::vector<bool> visited(n, false);
    std::queue<int> queue;

    visited[init] = true;
    queue.push(init);

    while (!queue.empty()) {
        int currVertex = queue.front();
        std::cout << currVertex << " ";
        queue.pop();

        for (auto i : adjList[currVertex]) {
            int adjVertex = i.first;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
}

bool isCyclic(int src, int prt, std::vector<std::vector<Pair>> &adjList, std::vector<bool> &visited) {
    visited[src] = true;
    for (auto node : adjList[src]) {
        if (!visited[node.first]) {
            if (isCyclic(node.first, src, adjList, visited)) return true;
        } else if (node.first != prt) {
            return true;
        }
    }
    return false;
}

/*
Descripción: Diga si el Grafo Dirigido (DAG) es un árbol o no.
Entrada: La lista de Adjacencia, n (Vertices) y m (Arcos).
Salida: Nada.
Complejidad en el tiempo: O(V + E) Por la implementación de DFS en la función de isCyclic.
Complejidad en el espacio: O(V)
*/
bool isTree(std::vector<std::vector<Pair>> &adjList, int n, int m) {
    if (n <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. n=" + std::to_string(n));
    } else if (m <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. m=" + std::to_string(m));
    }

    std::vector<bool> visited(n, false);

    if (isCyclic(0, -1, adjList, visited)) return false;

    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            return false;
        }
    }
    return true;
}

void topologicalSortUtil(std::vector<std::vector<Pair>> &adjList, std::stack<int> &stack, std::vector<bool> &visited, int v) {
    visited[v] = true;
    for (auto node : adjList[v]) {
        if (!visited[node.first]) {
            topologicalSortUtil(adjList, stack, visited, node.first);
        }
    }

    stack.push(v);
}

/*
Descripción: Ordene nodos de manera topologica
Entrada: La lista de Adjacencia, n (Vertices) y m (Arcos).
Salida: Nada.
Complejidad en el tiempo: O(V + E) Por la implementación de DFS.
Complejidad en el espacio: O(V)
*/
void topologicalSort(std::vector<std::vector<Pair>> &adjList, int n, int m) {
    if (n <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. n=" + std::to_string(n));
    } else if (m <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. m=" + std::to_string(m));
    }

    std::vector<bool> visited(n, false);
    std::stack<int> stack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(adjList, stack, visited, i);
        }
    }

    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
}

bool bipartiteUtil(std::vector<std::vector<Pair>> &adjList, int v, std::vector<bool> &visited, std::vector<int> &color) {
    for (auto u : adjList[v]) {
        if (visited[u.first] == false) {
            visited[u.first] = true;

            color[u.first] = !color[v];

            if (!bipartiteUtil(adjList, u.first, visited, color))
                return false;
        }

        // if two adjacent are colored with same color then
        // the graph is not bipartite
        else if (color[u.first] == color[v])
            return false;
    }
    return true;
}

/*
Descripción: Diga si el Grafo Dirigido (DAG) puede ser representado como Grafo bipartita.
Entrada: La lista de Adjacencia, n (Vertices) y m (Arcos).
Salida: Nada.
Complejidad en el tiempo: O(N)
Complejidad en el espacio: O(N)
*/
bool bipartiteGraph(std::vector<std::vector<Pair>> &adjList, int n, int m) {
    if (n <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. n=" + std::to_string(n));
    } else if (m <= 0) {
        throw std::invalid_argument("Cantidad de vertices no puede ser menor o igual a 0. m=" + std::to_string(m));
    }

    std::vector<bool> visited(n, false);
    std::vector<int> color(n + 1);

    visited[1] = true;
    color[1] = 0;

    return bipartiteUtil(adjList, 1, visited, color);
}

int main() {
    // Casos de prueba.
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------- Casos de Prueba ------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Creamos 5 grafos." << std::endl;
    Graph grafo1;
    Graph grafo2;
    Graph grafo3;
    Graph grafo4;
    Graph grafo5;
    std::cout << std::endl;

    std::cout << "--------------------- Agregar -----------------------" << std::endl;
    std::cout << "Agregamos al grafo 1: Edge(0, 2, 1), Edge(2, 1, 1), Edge(2, 3, 1), Edge(3, 4, 1), Edge(1, 4, 1)" << std::endl;
    std::vector<Edge> edges1 = {Edge(0, 2, 1), Edge(2, 1, 1), Edge(2, 3, 1), Edge(3, 4, 1), Edge(1, 4, 1)};
    grafo1.loadGraph(edges1, 5, 5);
    std::cout << std::endl;

    std::cout << "Agregamos al grafo 2: Edge(0, 1, 1), Edge(0, 3, 1), Edge(3, 2, 1), Edge(1, 2, 1), Edge(2, 4, 1)" << std::endl;
    std::vector<Edge> edges2 = {Edge(0, 1, 1), Edge(0, 3, 1), Edge(3, 2, 1), Edge(1, 2, 1), Edge(2, 4, 1)};
    grafo2.loadGraph(edges2, 5, 5);
    std::cout << std::endl;

    std::cout << "Agregamos al grafo 3: Edge(0, 2, 1), Edge(0, 1, 1), Edge(0, 3, 1), Edge(3, 5, 1), Edge(3, 4, 1)" << std::endl;
    std::vector<Edge> edges3 = {Edge(0, 2, 1), Edge(0, 1, 1), Edge(0, 3, 1), Edge(3, 5, 1), Edge(3, 4, 1)};
    grafo3.loadGraph(edges3, 6, 5);
    std::cout << std::endl;

    std::cout << "Agregamos al grafo 4: Edge(0, 2, 1), Edge(2, 1, 1), Edge(3, 5, 1), Edge(1, 2, 1), Edge(1, 5, 1)" << std::endl;
    std::vector<Edge> edges4 = {Edge(0, 2, 1), Edge(2, 1, 1), Edge(3, 5, 1), Edge(1, 2, 1), Edge(1, 5, 1)};
    grafo4.loadGraph(edges4, 6, 4);
    std::cout << std::endl;

    std::cout << "---------------------- IsTree -----------------------" << std::endl;
    std::cout << "Grafo 1: " << isTree(grafo1.adjList, 5, 5) << std::endl;
    std::cout << "Grafo 2: " << isTree(grafo2.adjList, 5, 5) << std::endl;
    std::cout << "Grafo 3: " << isTree(grafo3.adjList, 6, 5) << std::endl;
    std::cout << "Grafo 4: " << isTree(grafo4.adjList, 6, 4) << std::endl;
    std::cout << std::endl;

    std::cout << "----------------- Topological Sort ------------------" << std::endl;
    std::cout << "Grafo 1: ";
    topologicalSort(grafo1.adjList, 5, 5);
    std::cout << std::endl;
    std::cout << "Grafo 2: ";
    topologicalSort(grafo2.adjList, 5, 5);
    std::cout << std::endl;
    std::cout << "Grafo 3: ";
    topologicalSort(grafo3.adjList, 6, 5);
    std::cout << std::endl;
    std::cout << "Grafo 4: ";
    topologicalSort(grafo4.adjList, 6, 4);
    std::cout << std::endl
              << std::endl;

    std::cout << "----------------- Bipartite Graph ------------------" << std::endl;
    std::cout << "Grafo 1: " << bipartiteGraph(grafo1.adjList, 5, 5) << std::endl;
    std::cout << "Grafo 2: " << bipartiteGraph(grafo2.adjList, 5, 5) << std::endl;
    std::cout << "Grafo 3: " << bipartiteGraph(grafo3.adjList, 6, 5) << std::endl;
    std::cout << "Grafo 4: " << bipartiteGraph(grafo4.adjList, 6, 4) << std::endl;
    std::cout << std::endl;

    // Preguntar datos al usuario.
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "------------ Casos de Prueba (Usuario) -------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;

    int vertices;
    int arcos;
    std::string edges;

    std::cout << "Ingrese la cantidad de vertices: ";
    std::cin >> vertices;
    std::cout << "Ingrese la cantidad de arcos: ";
    std::cin >> arcos;
    std::cout << std::endl
              << std::endl;
    std::cout << "Ingresa las conexiones te todos los nodos separados por comas. E.j: 2-3,5-4,0-1,1-2,5-6";
    std::cout << std::endl;
    std::cin >> edges;

    std::string word = "";
    std::vector<std::string> edgesString;
    for (char i : edges) {
        if (i == ',' || i == '-') {
            edgesString.push_back(word);
            word = "";
        } else {
            word += i;
        }
    }
    edgesString.push_back(word);

    std::vector<Edge> userEdges;
    for (int i; i < edgesString.size() - 1; i++) {
        userEdges.push_back(Edge(stoi(edgesString[i]), stoi(edgesString[i + 1]), 1));
    }
    grafo5.loadGraph(userEdges, vertices, arcos);
    std::cout << "isTree: ";
    std::cout << isTree(grafo5.adjList, vertices, arcos);
    std::cout << std::endl;
    std::cout << "Topological Sort: ";
    topologicalSort(grafo5.adjList, vertices, arcos);
    std::cout << std::endl;
    std::cout << "Bipartite Graph: ";
    std::cout << bipartiteGraph(grafo5.adjList, vertices, arcos);
    std::cout << std::endl;
    return 0;
}