#include "Header.h"
#include <iostream>
using namespace std;

void Add(prikol*& current, int value) {
    if (!current) {
        current = new prikol(value);
        return;
    }
    else if (value < current->data) {
        Add(current->left, value);
    }
    else if (value > current->data) {
        Add(current->right, value);
    }
    else {
        return;
    }
}

prikol* findMinNode(prikol* node) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (node->left == nullptr) {
        return node;
    }
    else {
        return findMinNode(node->left);
    }
}

void removeNode(prikol*& current, int value) {
    if (current == nullptr) {
        return;
    }
    if (value < current->data) {
        removeNode(current->left, value);
    }
    else if (value > current->data) {
        removeNode(current->right, value);
    }
    else {
        if (current->left == nullptr) {
            prikol* temp = current;
            current = current->right;
            delete temp;
        }
        else if (current->right == nullptr) {
            prikol* temp = current;
            current = current->left;
            delete temp;
        }
        else {
            prikol* minRight = findMinNode(current->right);
            current->data = minRight->data;
            removeNode(current->right, minRight->data);
        }
    }
}

void check(int value, prikol* node, prikol*& mnozhC) {
    if (!node) return;
    if (node->data == value) {
        Add(mnozhC, value);
        return;
    }
    check(value, node->left, mnozhC);
    check(value, node->right, mnozhC);
}

void intersection(prikol* mnozhA, prikol* mnozhB, prikol*& mnozhC) {
    if (!mnozhA) return;
    check(mnozhA->data, mnozhB, mnozhC);
    intersection(mnozhA->left, mnozhB, mnozhC);
    intersection(mnozhA->right, mnozhB, mnozhC);
}

void add1(prikol*& current, prikol*& mnozhC) {
    if (!current) return;
    Add(mnozhC, current->data);
    add1(current->right, mnozhC);
    add1(current->left, mnozhC);
}

void unity(prikol* mnozhA, prikol* mnozhB, prikol*& mnozhC) {
    add1(mnozhA, mnozhC);
    add1(mnozhB, mnozhC);
}

prikol* Find(prikol* node, int value) {
    setlocale(LC_ALL, "Russian");
    if (!node) {
        cout << "Элемент не найден";
        return NULL;
    }
    if (node->data == value) {
        cout << "Элемент найден";
        return node;
    }
    if (node->data < value) {
        Find(node->right, value);
    }
    else {
        Find(node->left, value);
    }
}

void view(prikol* node) {
    if (!node) return;
    view(node->left);
    cout << node->data << " ";
    view(node->right);
}

void addToSet(prikol*& mnozhestvo, int value) {
    Add(mnozhestvo, value);
}

void inputelem(prikol*& mnozhestvo) {
    int value;
    cout << "Введите значение для добавления в множество (или -1 для завершения ввода): ";
    while (cin >> value && value != -1) {
        addToSet(mnozhestvo, value);
        cout << "Введите значение для добавления в множество (или -1 для завершения ввода): ";
    }
}

void Menu() {
    cout << "Меню выбора:\n";
    cout << "1. Ввести мощность и элементы первого множества\n";
    cout << "2. Ввести мощность и элементы второго множества\n";
    cout << "3. Пересечение множеств\n";
    cout << "4. Объединение множеств\n";
    cout << "5. Поиск элемента\n";
    cout << "6. Удаление элемента\n";
    cout << "7. Добавление элементов\n";
    cout << "8. Показать множества\n";
    cout << "9. Выход\n";
}

bool empty(prikol* node) {
    return node == nullptr;
}