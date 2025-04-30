#pragma once
#include <iostream>
#include "Tree.h"

class Item {
public:
    std::string key;
    BinaryTree* tree;

    // Конструктор элемента хэш-таблицы
    Item(std::string key, int data) {
        this->key = key;
        this->tree = new BinaryTree(key, data);
    }
};

