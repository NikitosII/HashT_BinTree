#pragma once
#include <iostream>

class Node {
public:
    std::string key;
    int data;
    Node* left;
    Node* right;

    // Конструктор узла
    Node(std::string key, int data) {
        this->key = key;
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree(std::string key, int data); // Конструктор
    void insert(std::string key, int data); // Вставка узла
    Node* getRoot(); // Получение корневого узла
    void printTree(Node* node); // Вывод дерева
    bool search(int s); // Поиск узла
    bool searchH(Node* node, int s);
};
