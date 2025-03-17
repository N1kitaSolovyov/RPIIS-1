#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, c, choice;
    prikol* joke = nullptr;
    prikol* joke2 = nullptr;
    prikol* joke3 = nullptr;
    prikol* joke4 = nullptr;

    do {
        Menu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "введите мощность 1-го множества" << endl;
            cin >> a;
            cout << "введите элементы 1-го множества" << endl;
            for (int i = 0; i < a; i++) {
                cin >> b;
                Add(joke, b);
            }
            break;

        case 2:
            cout << "введите мощность 2-го множества" << endl;
            cin >> a;
            cout << "введите элементы 2-го множества" << endl;
            for (int i = 0; i < a; i++) {
                cin >> b;
                Add(joke2, b);
            }
            break;

        case 3:
            intersection(joke, joke2, joke3);
            cout << "Пересечение:\n";
            view(joke3);
            cout << endl;
            break;

        case 4:
            unity(joke, joke2, joke4);
            cout << "Объединение:\n";
            view(joke4);
            cout << endl;
            break;

        case 5:
            if (empty(joke4)) {
                cout << "Ошибка: множество пустое. Сначала добавьте элементы.\n";
            }
            else {
                cout << "выберите элемент для поиска" << endl;
                cin >> c;
                Find(joke4, c);
                cout << endl;
            }
            break;

        case 6:
            if (empty(joke4)) {
                cout << "Ошибка: множество пустое. Сначала добавьте элементы.\n";
            }
            else {
                cout << "выберите элемент для удаления" << endl;
                cin >> c;
                removeNode(joke4, c);
                cout << "Удаление:\n";
                view(joke4);
                cout << endl;
            }
            break;

        case 7:
            cout << "Добавьте элементы\n";
            inputelem(joke4);
            view(joke4);
            cout << endl;
            break;

        case 8:
            cout << "Показать множества:\n";
            cout << "\nПервое множество:\n";
            view(joke);
            cout << endl;
            cout << "Второе множество:\n" ;
            view(joke2);
            cout << endl << "\n";
            break;

        case 9:
            cout << "Выход\n";
            break;

        default:
            cout << "Неправильный выбор. Повторите попытку.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
