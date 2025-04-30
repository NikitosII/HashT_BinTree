#include "Tree.h"
#include <sstream> 

BinaryTree::BinaryTree(std::string key, int data) {
    root = new Node(key, data);
}

// Вставка нового узла в бинарное дерево
void BinaryTree::insert(std::string key, int data) {
    Node* newNode = new Node(key, data);
    Node* current = root;

    while (current != nullptr) {
        if (data < current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
}

Node* BinaryTree::getRoot() {
    return root; // Возвращение корневого узла
}

// Вывод бинарного дерева в порядке возрастания
void BinaryTree::printTree(Node* node) {
    if (node != nullptr) {
        printTree(node->left);
        std::cout << "Key: " << node->key << ", Data: " << node->data << std::endl;
        printTree(node->right);
    }
}

// Рекурсивный поиск узла в бинарном дереве
bool BinaryTree::searchH(Node* root, int s) {

    if (root == nullptr) {
        return false;
    }

    if (root->data == s) {
        return true;
    }
    else if (s < root->data) {
        return searchH(root->left, s);

    }
    else {
        return searchH(root->right, s);
    }
}
bool BinaryTree::search(int s) {
    return searchH(root, s);
}




