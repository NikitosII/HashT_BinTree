#include <iostream>
#include <string>
#include "HashT.h"
#include <fstream> 
#include <sstream> 

int main(int argc, char* argv[]) {
    Hashmap hashmap;

    std::string path;
    path = std::string(argv[1]);
    std::ifstream fin(path);
    std::string x;


    int choice = 0;
    do {
        std::cout << "  Menu:\n";
        std::cout << "1) Data input\n";
        std::cout << "2) Data output\n";
        std::cout << "3) Search data\n";
        std::cout << "0) Exit\n";
        std::cout << "Select a menu item: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            // Чтение данных из файла и вставка их в хеш-таблицу
            while (getline(fin, x)) {
                std::istringstream istream(x);
                std::string s, word = "";
                int num = 0;
                while (istream >> s) {
                    if (num == 0 && word != "") {
                        num = stoi(s);
                    }
                    if (word == "" && num == 0) {
                        word = s;
                    }
                }
                hashmap.insertItem(word, num);
            }
            system("pause");
            system("cls");
        }
              break;
        case 2: {
            // Вывод всех элементов хеш-таблицы
            hashmap.printTable();
            system("pause");
            system("cls");
        }
              break;
        case 3: {
            // Поиск элемента в хеш-таблице
            std::string key;
            int choice, data;
            do {
                std::cout << "Enter search (key data): ";
                std::cin >> key >> data;
                bool searchData = hashmap.searchItem(key, data);
                if (searchData) {
                    std::cout << "The element was found in the hash table." << std::endl;
                }
                else {
                    std::cout << "Element not found in hash table." << std::endl;
                }
                std::cout << "Continue?(0/1)";
                std::cin >> choice;
            } while (choice != 0);
        }
              break;
        default: {
            std::cout << "Enter an item from the list\n";
        }
               break;
        }
    } while (choice != 0);
    return 0;
}

