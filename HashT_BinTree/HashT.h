#pragma once
#include <iostream>
#include "Item.h"

class Hashmap {
private:
    int size;
    Item** items;

public:
    Hashmap(); // Конструктор
    ~Hashmap(); // Деструктор
    long hashFunc(std::string key); // Хеш-функция
    void insertItem(std::string key, int data); // Вставка элемента
    void printTable(); // Вывод всех элементов
    bool searchItem(std::string key, int data); // Поиск элемента
};

