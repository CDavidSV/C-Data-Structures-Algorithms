#pragma once
#include <iostream>
#include <queue>
#include "BSTNode.h"

class BST {
   private:
    BSTNode* root;

    /*
    Descripción: Despliega los datos con el metodo de preorden.
    Entrada: la raiz donde comienza a desplegar los nodos.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(logn)
    */
    void preorder(BSTNode* p) {
        if (!p) return;
        std::cout << p->getData().getIp() << " ";
        preorder(p->getLeft());
        preorder(p->getRight());
    }

    /*
    Descripción: Despliega los datos con el metodo de inorden.
    Entrada: la raiz donde comienza a desplegar los nodos.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(logn)
    */
    void inorder(BSTNode* p) {
        if (!p) return;
        inorder(p->getLeft());
        std::cout << p->getData().getIp() << " ";
        inorder(p->getRight());
    }

    /*
    Descripción: Despliega los datos con el metodo de postorden.
    Entrada: la raiz donde comienza a desplegar los nodos.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(logn)
    */
    void postorder(BSTNode* p) {
        if (!p) return;
        postorder(p->getLeft());
        postorder(p->getRight());
        std::cout << p->getData().getIp() << " ";
    }

    /*
    Descripción: Despliega los datos en cada nivel del arbol de izquierda a derecha.
    Entrada: la raiz donde comienza a desplegar los nodos.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(w)
    */
    void levelByLevel(BSTNode* p) {
        if (!p) return;

        std::queue<BSTNode*> treeList;
        treeList.push(p);

        while (!treeList.empty()) {
            // Imprimir el nodo de la primera parte de la fila y eliminarlo.
            BSTNode* currenBSTNode = treeList.front();
            std::cout << currenBSTNode->getData().getIp() << " ";
            treeList.pop();

            // Agregar el nodo izquierdo a la fila.
            if (currenBSTNode->getLeft() != NULL) {
                treeList.push(currenBSTNode->getLeft());
            }

            // Agregar el nodo derecho a la fila.
            if (currenBSTNode->getRight() != NULL) {
                treeList.push(currenBSTNode->getRight());
            }
        }
    }

    /*
    Descripción: Calcula la altura por medio de el recorrido más largo que exista más uno.
    Entrada: El nodo de donde comienza el recorrido.
    Salida: La altura máxima del arbol.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(n)
    */
    int calculateMaxheight(BSTNode* p) {
        if (!p) return 0;

        int leftHeight = calculateMaxheight(p->getLeft());
        int rightHeight = calculateMaxheight(p->getRight());

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }

   public:
    BST() {
        root = NULL;
    }

    /*
    Descripción: Agrega un valor nuevo al arbol dependiendo de su tamaño.
    Entrada: Nuevo valor.
    Salida: Un valor booleano que establece si se agrego o no el nodo.
    Complejidad en el tiempo: O(logn)
    Complejidad en el espacio: O(1)
    */
    bool add(Ip value) {
        BSTNode* parent = NULL;
        BSTNode* p = root;

        BSTNode* newNode = new BSTNode(value);
        if (!p) {
            root = newNode;
            return true;
        }
        while (!!p) {
            if (p->getData() == value) return false;

            parent = p;

            // Obtener el nodo correspondiente dependiendo de si el valor es mayor o menor.
            p = (p->getData() > value ? p->getLeft() : p->getRight());
        }

        if (value > parent->getData()) {
            parent->setRight(newNode);
        } else {
            parent->setLeft(newNode);
        }

        return true;
    }

    /*
    Descripción: Remueve un valor HOJA especificado.
    Entrada: Valor que corresponde al nodo hoja que se quiere remover.
    Salida: Un valor booleano que establece si se removió o no el nodo.
    Complejidad en el tiempo: O(logn)
    Complejidad en el espacio: O(1)
    */
    bool remove(Ip value) {
        BSTNode* parent = NULL;
        BSTNode* p = root;

        if (p->getData() == value) {
            // Delete the node if it's the first one found.
            delete p;
            root = NULL;
            return true;
        }

        while (!!p) {
            // Make sure it is a leaf node.
            if (p->getRight() == NULL && p->getLeft() == NULL && value == p->getData()) {
                // Identify if the node is right or left for the parent.
                if (parent->getRight() && parent->getRight()->getData() == value) {
                    parent->setRight(NULL);
                } else {
                    parent->setLeft(NULL);
                }

                // Delete the node.
                delete p;
                return true;
            }

            // Get parent node.
            parent = p;

            // Buscar el nodo correspondiente.
            p = (p->getData() > value ? p->getLeft() : p->getRight());
        }

        return false;
    }

    /*
    Descripción: Busca si existe o no cierto nodo correspondiente a su valor.
    Entrada: Valor que corresponde al nodo que se quiere buscar.
    Salida: Un valor booleano que establece si se encontro o no el nodo.
    Complejidad en el tiempo: O(logn)
    Complejidad en el espacio: O(1)
    */
    bool search(Ip value) {
        BSTNode* p = root;
        while (!!p) {
            // Valor dado es igual al del nodo.
            if (p->getData() == value) return true;

            // Obtener siguiente nodo.
            p = (p->getData() > value ? p->getLeft() : p->getRight());
        }

        return false;
    }

    /**
     * @brief
     *
     * @param parameter 1. preorder, 2. inorder, 3. postorder, 4. levelbylevel
     *
     *  Complejidades dependen de el metodo que se selecciones. Se ecuentran en la parte privada de la clase.
     */
    void visit(int parameter) {
        if (parameter < 1 || parameter > 4) return;

        switch (parameter) {
            case 1:
                preorder(root);
                std::cout << std::endl;
                break;
            case 2:
                inorder(root);
                std::cout << std::endl;
                break;
            case 3:
                postorder(root);
                std::cout << std::endl;
                break;
            case 4:
                levelByLevel(root);
                std::cout << std::endl;
                break;
        }
    }

    // Llama a la función para calcular la altura, en la parte privada de la clase.
    /*
    Descripción: Regresará la altura del BST.
    Entrada: Nada.
    Salida: Un entero con el cual indicará la altura del BST.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(n)
    */
    int height() {
        if (!root) {
            return 0;
        }
        return calculateMaxheight(root);
    }

    /*
    Descripción: Desplegará los ancestros de un dato.
    Entrada: El dato del cual se desea conocer los ancestros.
    Salida: Nada.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    void ancestors(Ip value) {
        if (!root || !search(value)) {
            std::cout << -1 << std::endl;
            return;
        }

        BSTNode* p = root;

        while (!!p) {
            if (p->getData() == value) break;
            std::cout << p->getData().getIp() << " ";

            // Obtener siguiente nodo.
            p = (p->getData() > value ? p->getLeft() : p->getRight());
        }
        std::cout << std::endl;
    }

    /*
    Descripción: Regresará un entero que indica el nivel en que se encuentra un dato,
    o -1 en caso de que no se encuentre en el BST.
    Entrada: Un dato a buscar su nivel.
    Salida: Entero indicando el nivel del dato en el BST, o -1 si no se encuentra.
    Complejidad en el tiempo: O(n)
    Complejidad en el espacio: O(1)
    */
    int whatLevelAmI(Ip value) {
        if (!root) {
            return -1;
        }

        int level = 0;
        bool found = false;

        BSTNode* p = root;
        while (!!p) {
            level++;
            if (p->getData() == value) {
                found = true;
                break;
            };

            // Obtener siguiente nodo.
            p = (p->getData() > value ? p->getLeft() : p->getRight());
        }

        if (found) return level;
        return -1;
    }
};