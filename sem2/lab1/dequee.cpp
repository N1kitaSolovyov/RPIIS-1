#include "Header.h"

using namespace std;

// Создание первого элемента дека
void CreateDeque(DequeNode** front, DequeNode** rear, int value) {
    DequeNode* newNode = new DequeNode;
    newNode->info = value;
    newNode->next = newNode->prev = nullptr;
    *front = *rear = newNode;
}

// Добавление элемента в начало дека
void AddToFront(DequeNode** front, DequeNode** rear, int value) {
    DequeNode* newNode = new DequeNode;
    newNode->info = value;
    newNode->prev = nullptr;
    newNode->next = *front;

    if (*front != nullptr) {
        (*front)->prev = newNode;
    }
    *front = newNode;

    if (*rear == nullptr) {
        *rear = newNode; // Если дек был пуст
    }
}

// Добавление элемента в конец дека
void AddToRear(DequeNode** front, DequeNode** rear, int value) {
    DequeNode* newNode = new DequeNode;
    newNode->info = value;
    newNode->next = nullptr;
    newNode->prev = *rear;

    if (*rear != nullptr) {
        (*rear)->next = newNode;
    }
    *rear = newNode;

    if (*front == nullptr) {
        *front = newNode; // Если дек был пуст
    }
}

// Удаление элемента из начала дека
int RemoveFromFront(DequeNode** front, DequeNode** rear) {
    if (*front == nullptr) {
        cout << "Дек пуст." << endl;
        return 0; 
    }

    int value = (*front)->info;
    DequeNode* temp = *front; 
    *front = (*front)->next;

    if (*front != nullptr) {
        (*front)->prev = nullptr;
    }
    else {
        *rear = nullptr; // Если дек стал пустым
    }

    delete temp; 
    return value; 
}

// Удаление элемента из конца дека
int RemoveFromRear(DequeNode** front, DequeNode** rear) {
    if (*rear == nullptr) {
        cout << "Дек пуст." << endl;
        return 0; 
    }

    int value = (*rear)->info;
    DequeNode* temp = *rear; 
    *rear = (*rear)->prev;

    if (*rear != nullptr) {
        (*rear)->next = nullptr;
    }
    else {
        *front = nullptr; // Если дек стал пустым
    }

    delete temp; 
    return value; 
}

// Просмотр элементов дека
void ViewDeque(int direction, DequeNode* node) {
    while (node != nullptr) {
        cout << node->info << " ";
        if (direction == 0) {
            node = node->next; 
        }
        else {
            node = node->prev; 
        }
    }
    cout << endl;
}

// Очистка памяти дека
void ClearDeque(DequeNode** front, DequeNode** rear) {
    while (*front != nullptr) {
        DequeNode* temp = *front; 
        *front = (*front)->next; 
        delete temp; 
    }
    rear = nullptr; 
}