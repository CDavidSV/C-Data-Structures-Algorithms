#pragma once
#include <iostream>
#include <locale.h>
#include <string>

#include "STNode.h"

class SplayTree {
   private:
    STNode* root;
    int treeSize = 0;

    void zig(STNode* node) {
        STNode* y = node->left;
        node->left = y->right;
        if (y->right != nullptr) {
            y->right->progenitore = node;
        }

        y->progenitore = node->progenitore;

        if (node->progenitore == nullptr) {
            root = y;
        } else if (node == node->progenitore->right) {
            node->progenitore->right = y;
        } else {
            node->progenitore->left = y;
        }
        y->right = node;

        node->progenitore = y;
    }

    void zag(STNode* node) {
        STNode* y = node->right;
        node->right = y->left;
        if (y->left != nullptr) {
            y->left->progenitore = node;
        }
        y->progenitore = node->progenitore;
        if (node->progenitore == nullptr) {
            root = y;
        } else if (node == node->progenitore->left) {
            node->progenitore->left = y;
        } else {
            node->progenitore->right = y;
        }
        y->left = node;
        node->progenitore = y;
    }

    void splay(STNode* node) {
        while (node->progenitore) {
            if (!node->progenitore->progenitore) {
                if (node->progenitore->left == node) {
                    zig(node->progenitore);
                } else {
                    zag(node->progenitore);
                }
            } else if (node->progenitore->left == node && node->progenitore == node->progenitore->progenitore->left) {
                zig(node->progenitore->progenitore);
                zig(node->progenitore);
            } else if (node->progenitore->right == node && node->progenitore == node->progenitore->progenitore->right) {
                zag(node->progenitore->progenitore);
                zag(node->progenitore);
            } else if (node->progenitore->right == node && node->progenitore == node->progenitore->progenitore->left) {
                zag(node->progenitore);
                zig(node->progenitore);
            } else {
                zig(node->progenitore);
                zag(node->progenitore);
            }
        }
    }

    STNode* max(STNode* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }

    void devide(STNode*& node, STNode*& s, STNode*& t) {
        splay(node);

        if (node->right) {
            t = node->right;
            t->progenitore = nullptr;
        } else {
            t = nullptr;
        }
        s = node;
        s->right = nullptr;
    }

    STNode* join(STNode* left, STNode* right) {
        if (!left) return right;
        if (!right) return left;

        STNode* x = max(left);
        splay(x);

        x->right = right;
        right->progenitore = x;
        return x;
    }

    void printTree(STNode* node, std::string fill, bool last) {
        if (node) {
            std::cout << fill;
            if (last) {
                std::cout << "└────";
                fill += "     ";
            } else {
                std::cout << "├────";
                fill += "|    ";
            }
            std::cout << node->ip.getIp();
            std::cout << ", Acceses: " << node->acceses << std::endl;
            printTree(node->left, fill, false);
            printTree(node->right, fill, true);
        }
    }

    void inorder(STNode* p) {
        if (!p) return;
        inorder(p->left);
        std::cout << p->ip.getIp() << " ";
        inorder(p->right);
    }

   public:
    // Constructores.
    SplayTree() {
        root = nullptr;
    }
    SplayTree(Ip newValue) {
        STNode* newNode = new STNode(newValue);
        root = newNode;
    }

    // Metodos.

    /*
    Descripción: Agregue un dato al Splay Tree.
    Entrada: Un entero, el cual se desea agregar al Splay Tree.
    Salida: Nada.
    Complejidad en el tiempo promedio: O(logn)
    Complejidad en el espacio: O(1)
    */
    void insert(Ip newValue) {
        STNode* newNode = new STNode(newValue);
        newNode->progenitore = nullptr;
        STNode* previous = nullptr;
        STNode* current = root;

        // Asignar el nuevo nodo.
        while (current != nullptr) {
            previous = current;
            if (newNode->ip < current->ip) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Detectar si el dato es duplicado.
        if (previous && previous->ip == newValue) return;

        newNode->progenitore = previous;

        // El Arbol esta vacio.
        if (previous == nullptr) {
            root = newNode;
        } else if (newNode->ip < previous->ip) {
            previous->left = newNode;
        } else {
            previous->right = newNode;
        }

        // Mover el nuevo nodo hasta la raiz.
        splay(newNode);
        treeSize++;
    }

    /*
    Descripción: Elimina el dato del Splay Tree.
    Entrada: El dato entero que se desea borrar.
    Salida: Nada.
    Complejidad en el tiempo promedio: O(logn)
    Complejidad en el espacio: O(1)
    */
    void del(Ip valueToDelete) {
        STNode* eliminate = nullptr;
        STNode *t, *s;
        STNode* current = root;

        // Buscar el elemento a borrar.
        while (current) {
            if (current->ip == valueToDelete) {
                eliminate = current;
                break;
            } else if (current->ip < valueToDelete) {
                current = current->right;
            } else {
                current = current->left;
            }
        }

        if (eliminate) {
            devide(eliminate, s, t);
            if (s->left) {
                s->left->progenitore = nullptr;
            }

            root = join(s->left, t);

            delete s;
            s = nullptr;
            treeSize--;
        }
    }

    /*
    Descripción: Regresa un valor boleano que representa si el dato qus se desea encontrar existe o no.
    Entrada: El entero que se busca
    Salida: Un valor boleando que representa si el dato qus se desea encontrar existe o no.
    Complejidad en el tiempo promedio: O(logn)
    Complejidad en el espacio: O(1)
    */
    bool find(Ip valueToFind) {
        STNode* current = root;

        while (current) {
            if (current->ip == valueToFind) {
                current->acceses++;
                return true;
            } else if (valueToFind > current->ip) {
                current = current->right;
            } else {
                current = current->left;
            }
        }
        return false;
    }

    /*
    Descripción: Despliega de manera visual el arbol.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo promedio: O(n)
    Complejidad en el espacio: O(n)
    */
    void printTree() {
        printTree(root, "", true);
    }

    /*
    Descripción: Despliega en orden ascendentemente el contenido del Splay Tree.
    Entrada: Nada.
    Salida: Nada.
    Complejidad en el tiempo promedio: O(n)
    Complejidad en el espacio: O(logn)
    */
    void print() {
        inorder(root);
    }

    /*
    Descripción: Regresa la cantidad de datos que tiene el Splay Tree.
    Entrada: Nada.
    Salida: Un valor entero que represena la cantidad de datos el Splay Tree.
    Complejidad en el tiempo promedio: O(1)
    Complejidad en el espacio: O(1)
    */
    int size() {
        return treeSize;
    }
};