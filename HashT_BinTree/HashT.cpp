#include <iostream>
#include "HashT.h"

Hashmap::Hashmap() {
    size = 10;
    items = (Item**)calloc(size, sizeof(Item*));
}

Hashmap::~Hashmap() {
    for (int i = 0; i < size; ++i) {
        Item* current = items[i];
        if (current != nullptr) {
            delete current->tree;
            delete current;
        }
    }
    free(items);
    items = nullptr;
}

// Хеш-функция для вычисления индекса
long Hashmap::hashFunc(std::string key) {
    long sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum += key[i];
    }
    return (sum % 10);
}

// Вставка элемента в хеш-таблицу
void Hashmap::insertItem(std::string key, int data) {
    long index = hashFunc(key);
    Item* current = items[index];

    if (current == nullptr) {
        items[index] = new Item(key, data);
    }
    else {
        current->tree->insert(key, data);
    }
}

// Вывод всех элементов хеш-таблицы
void Hashmap::printTable() {
    std::cout << "by default, elements of binary trees are displayed in ascending order" << std::endl;
    for (int i = 0; i < size; ++i) {
        Item* current = items[i];
        if (current != nullptr) {
            /*std::cout << "Key: " << current->key << std::endl;*/
            std::cout << "Item " << i << ":" << std::endl;
            current->tree->printTree(current->tree->getRoot());
        }
    }
}

// Поиск элемента в хеш-таблице
bool Hashmap::searchItem(std::string key, int data) {
    long index = hashFunc(key);
    Item* current = items[index];

    if (current != nullptr) {
        bool result = current->tree->search(data);
        return result;
    }

    return false;
}