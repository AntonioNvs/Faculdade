/*
    Trabalho Prático - Estrutura de Dados - UFMG, map.hpp
    Propósito: Definir estruturas gerais da classe Map;

    @author Antônio Neves
    @version 1.0 04/07/2023
*/

#ifndef MAP_HPP
#define MAP_HPP
#define max(a,b) ((a)>(b)?(a):(b))

#include <iostream>

#include "vector.hpp"

template <typename K, typename V>
class Map {
    protected:
        // Estrutura para armazenar os nós da árvore AVL
        struct node_t {
            K key;
            V value;
            int height;
            node_t *left, *right, *parent;

            node_t(K key, V value) {
                this->key = key;
                this->value = value;
                this->left = nullptr;
                this->right = nullptr;
                this->parent = nullptr;
                height = 1;
            };
        };

    public:
        /*
            @brief Construtor da classe Map
        */
        Map() {};
        ~Map();
        
        // Estrutura para armazenar um par chave-valor
        struct pair_t {
            K key;
            V value;
        };

        /*
            @brief Insere um elemento no Map
            @param Chave do elemento
        */
        void erase(K key);

        /*
            @brief Adquire os elementos do map pareados
            @return Vetor com todos os elementos
        */
        Vector<pair_t> iterate();

        /*
            @brief Pesquisa um elemento no Map
            @param Chave do elemento
            @param Nó do elemento
        */
        node_t* find(K key);

        /*
            @brief Acessa um elemento no Map
            @param Chave do elemento
            @param Valor do elemento
        */
        V& operator[](K key);
    private:
        int size = 0;
        node_t* root = nullptr;
        node_t* insert(K key, V value);

        /*
            @brief Percorre a árvore em ordem
            @param Nó atual
            @param Vetor para armazenar os elementos
        */
        void inorder(node_t* node, Vector<pair_t> *arr);

        /*
            @brief Balanceia a árvore
            @param Nó atual
        */
        void balance(node_t* node);

        /*
            @brief Adquire a altura de um nó
            @param Nó atual
            @return Altura do nó
        */
        int get_height(node_t* node);

        /*
            @brief Auxilia na rotação de balanceamento
            @param Nó atual
        */
        void helper(node_t* node);

        /*
            @brief Rotaciona para a esquerda
            @param Nó atual
        */
        void left_rotation(node_t* node);

        /*
            @brief Rotaciona para a direita
            @param Nó atual
        */
        void right_rotation(node_t* node);

        /*
            @brief Adquire o predecessor em ordem
            @param Nó atual
            @return Predecessor em ordem
        */
        node_t* inorder_predecessor(node_t* node);

        /*
            @brief Adquire o sucessor em ordem
            @param Nó atual
            @return Sucessor em ordem
        */
        node_t* inorder_sucessor(node_t* node);

        /*
            @brief Destrói a árvore
            @param Nó atual
        */
        void destruct_tree(node_t* node);

        int count = 0;
};


template <typename K, typename V>
Map<K, V>::~Map() {
    destruct_tree(root);
}

template <typename K, typename V>
void Map<K, V>::destruct_tree(node_t* node) {
    if(node == nullptr) return;
    destruct_tree(node->left);
    destruct_tree(node->right);
    delete node;
}

template <typename K, typename V>
typename Map<K, V>::node_t * Map<K, V>::insert(K key, V value) {
    size++;
    node_t* new_node = new node_t(key, value);
    if(root == nullptr) {
        root = new_node;
        return new_node;
    }
    
    node_t* current = root, *prev = nullptr;
    while(current != nullptr) {
        prev = current;
        if(key < current->key) current = current->left;
        else if(key > current->key) current = current->right;
        else {
            // Elemento já existe
            delete new_node;
            size--;

            return current;
        }
    }
    

    if(key < prev->key)
        prev->left = new_node;
    else
        prev->right = new_node;

    new_node->parent = prev;

    balance(new_node);

    return new_node;
}

template <typename K, typename V>
Vector<typename Map<K, V>::pair_t> Map<K, V>::iterate() {
    Vector<pair_t> *arr = new Vector<pair_t>();
    this->inorder(root, arr);
    Vector<pair_t> ret = (*arr);
    delete arr;
    return ret;
}

template <typename K, typename V>
void Map<K, V>::inorder(node_t* node, Vector<pair_t>* arr) {
    if(node == nullptr) return;
    inorder(node->left, arr);
    arr->push_back({node->key, node->value});
    inorder(node->right, arr);
}

template <typename K, typename V>
typename Map<K, V>::node_t * Map<K, V>::find(K key) {
    this->count = 0;
    node_t* current = root;

    // Percorre a árvore até encontrar o elemento
    while(current != nullptr) {
        this->count++;
        if(key < current->key) current = current->left;
        else if(key > current->key) current = current->right;
        else return current;
    }
    return nullptr;
}

template <typename K, typename V>
V& Map<K, V>::operator[](K key) {
    node_t *node = find(key);
    if(node == nullptr)
        this->insert(key, V());
    
    return find(key)->value;
}

template <typename K, typename V>
void Map<K, V>::right_rotation(node_t* node) {
    node_t*left = node->left;
    node->left = left->right;

    // Atualiza os pais
    if(left->right != nullptr)
        left->right->parent = node;
    if(node->parent != nullptr && node->parent->right == node)
        node->parent->right = left;
    else if(node->parent != nullptr && node->parent->left == node)
        node->parent->left = left;
    
    left->parent = node->parent;
    left->right = node;
    node->parent = left;
}

template <typename K, typename V>
void Map<K, V>::left_rotation(node_t* node) {
    node_t* right = node->right;
    node->right = right->left;

    // Atualiza os pais
    if(right->left != nullptr)
        right->left->parent = node;
    if(node->parent != nullptr && node->parent->left == node)
        node->parent->left = right;
    else if(node->parent != nullptr && node->parent->right == node)
        node->parent->right = right;

    right->parent = node->parent;
    right->left = node;
    node->parent = right;   
}

template <typename K, typename V>
void Map<K, V>::erase(K key) {
    size--;

    node_t *crr = this->find(key);

    if(crr == nullptr) {
        size++;
        return;
    }

    if(size == 0 && crr == root) {
        delete root;
        root = nullptr;
        return;
    }

    node_t* l = this->inorder_predecessor(crr->left);
    node_t* r = this->inorder_sucessor(crr->right);

    node_t* prev = crr->parent;

    // Caso 1: Nó é folha
    if(l == nullptr && r == nullptr) {
        if(prev == nullptr)
            root = nullptr;
        else {
            if(prev->left == crr)
                prev->left = nullptr;
            else
                prev->right = nullptr;
            
            delete crr;
            balance(prev);
        }
        return;
    }
    
    // Caso 2: Nó tem um filho
    node_t* start = nullptr;
    if(l != nullptr) {
        // Caso 2.1: Nó tem um filho à esquerda
        if(l == crr->left) {
            l->right = crr->right;
            if(l->right != nullptr) {
                l->right->parent = l;
            }
        } else {
            if(l->left != 0)
                l->left->parent = l->parent;
            start = l->parent;
            l->parent->right = l->left;
            l->right = crr->right;
            l->parent = nullptr;
            if(l->right != nullptr)
                l->right->parent = l;
            crr->left->parent = l;
        }

        // Atualiza o pai
        if(prev == nullptr)
            root = l;
        else {
            if(prev->left == crr)
                prev->left = l, l->parent = prev;
            else
                prev->right = l, l->parent = prev;
            delete crr;
        }
        this->balance(start);
        return;
    } else {
        // Caso 2.2: Nó tem um filho à direita
        if(r == crr->right) {
            r->left = crr->left;
            if(r->left != nullptr)
                r->left->parent = r;
        } else {
            if(r->right != nullptr)
                r->right->parent = r->parent;
            start = r->parent;
            r->parent->left = r->right;
            r->left = crr->left;
            r->parent = nullptr;
            if(r->left != nullptr)
                r->left->parent = r;
            r->right = crr->right;
            crr->right->parent = r;
        }

        // Atualiza o pai
        if(prev == nullptr)
            root = r;
        else {
            if(prev->right == crr)
                prev->right = r, r->parent = prev;
            else
                prev->left = r, r->parent = prev;
            delete crr;
        }

        balance(start);
        return;
    }
}

template <typename K, typename V>
typename Map<K, V>::node_t * Map<K, V>::inorder_predecessor(Map<K, V>::node_t* node) {
    if(node == nullptr)
        return node;
    while(node->right != nullptr)
        node = node->right;
    return node;
}

template <typename K, typename V>
typename Map<K, V>::node_t * Map<K, V>::inorder_sucessor(Map<K, V>::node_t* node) {
    if(node == nullptr)
        return node;
    while(node->left != nullptr)
        node = node->left;
    return node;
}

template <typename K, typename V>
void Map<K, V>::balance(Map<K, V>::node_t* node) {
    // Atualiza a altura dos nós
    while(node != root) {
        int h = node->height;
        node = node->parent;
        // Atualiza a altura
        if(node->height < h + 1)
            node->height = h + 1;
        if(node == root && get_height(node->left) - get_height(node->right) > 1) {
            if(get_height(node->left->left) > get_height(node->left->right)) {
                root = node->left;
            } else {
                root = node->left->right;
            }
            // Rotaciona
            helper(node);
            break;
        } else if(node == root && get_height(node->left) - get_height(node->right) < -1) {
            if(get_height(node->right->right) > get_height(node->right->left)) {
                root = node->right;
            } else {
                root = node->right->left;
            }
            // Rotaciona
            helper(node);
            break;
        }
        helper(node);
    }   
}

template <typename K, typename V>
int Map<K, V>::get_height(Map<K, V>::node_t* node) {
    if(node == nullptr)
        return 0;
    return node->height;
}

template <typename K, typename V>
void Map<K, V>::helper(Map<K, V>::node_t* node) {
    // Caso 1: Rotação à direita
    if(get_height(node->left) - get_height(node->right) > 1) {
        // Caso 1.1: Rotação à direita
        if(get_height(node->left->left) > get_height(node->left->right)) {
            node->height = max(get_height(node->right) + 1, get_height(node->left->right) + 1);
            node->left->height = max(get_height(node->left->left) + 1, get_height(node) + 1);
            right_rotation(node);
        } else {
            // Caso 1.2: Rotação à esquerda e depois à direita
            node->left->height = max(
                get_height(node->left->left) + 1,
                get_height(node->left->right->left) + 1
            );
            node->height = max(
                get_height(node->left->right->right) + 1,
                get_height(node->right) + 1
            );
            node->left->right->height = max(
                get_height(node) + 1,
                get_height(node->left) + 1
            );

            left_rotation(node->left);
            right_rotation(node);
        }
    } else if(get_height(node->left) - get_height(node->right) < -1) {
        if(get_height(node->right->right) > get_height(node->right->left)) {
            // Caso 2.1: Rotação à esquerda
            node->height = max(get_height(node->left) + 1, get_height(node->right->left) + 1);
            node->right->height = max(get_height(node->right->right) + 1, get_height(node) + 1);
            left_rotation(node);
        } else {
            // Caso 2.2: Rotação à direita e depois à esquerda
            node->right->height = max(
                get_height(node->right->right) + 1,
                get_height(node->right->left->right) + 1
            );
            node->height = max(
                get_height(node->right->left->left) + 1,
                get_height(node->left) + 1
            );
            node->right->left->height = max(
                get_height(node) + 1,
                get_height(node->right) + 1
            );

            right_rotation(node->right);
            left_rotation(node);
        }
    }
}

#endif