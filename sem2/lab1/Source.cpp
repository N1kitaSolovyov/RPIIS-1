#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    DequeNode* front = nullptr;
    DequeNode* rear = nullptr;
    int option, value;

    while (true) {
        cout << "\n1. Создать элемент\n2. Добавить в начало\n3. Добавить в конец\n4. Удалить из начала\n5. Удалить из конца\n6. Просмотреть дек\n7. Очистить дек\n0. Выход\nВведите номер операции: ";
        cin >> option;

        switch (option) {
        case 1:
            if (front != nullptr) {
                cout << "Очистите память!" << endl;
                break;
            }
            cout << "Введите значение для первого элемента: ";
            cin >> value;
            CreateDeque(&front, &rear, value);
            cout << "Первый элемент создан: " << front->info << endl;
            break;

        case 2:
            cout << "Введите значение для добавления в начало: ";
            cin >> value;
            AddToFront(&front, &rear, value);
            cout << "Элемент " << value << " добавлен в начало." << endl;
            break;

        case 3:
            cout << "Введите значение для добавления в конец: ";
            cin >> value;
            AddToRear(&front, &rear, value);
            cout << "Элемент " << value << " добавлен в конец." << endl;
            break;

        case 4:
            value = RemoveFromFront(&front, &rear);
            if (value != 0) {
                cout << "Удален элемент из начала: " << value << endl;
            }
            break;

        case 5:
            value = RemoveFromRear(&front, &rear);
            if (value != 0) {
                cout << "Удален элемент из конца: " << value << endl;
            }
            break;

        case 6:
            cout << "Просмотреть дек (вперед - 0, назад - 1): ";
            int direction;
            cin >> direction;
            if (front == nullptr) {
                cout << " " << endl;
            }
            else {
                if (direction == 0) {
                    ViewDeque(0, front);
                }
                else {
                    ViewDeque(1, rear);
                }
            }
            break;

        case 7:
            ClearDeque(&front, &rear);
            cout << "Дек очищен." << endl;
            break;

        case 0:
            ClearDeque(&front, &rear);
            return 0;

        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    }
}