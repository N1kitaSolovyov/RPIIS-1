#include <iostream>
#include <string>
#include <cctype> 
#include <limits> 
#include "Node.h"
#include "bor.h"
using namespace std;

void printMenu() {
    cout << "\nВыберите операцию:\n";
    cout << "1 - Добавить строку в бор\n";
    cout << "2 - Удалить строку из бора\n";
    cout << "3 - Поиск строки в боре\n";
    cout << "4 - Вывести все строки в боре\n";
    cout << "0 - Завершить программу\n";
    cout << "Ваш выбор: ";
}

bool isValidString(const string& str) {
    for (char c : str) {
        if (!isalpha(c) && !isspace(c)) { 
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n = -1; 
    string s;
    Node* root = new Node();
    root->back_ptr = new Node(root);

    do {
        printMenu(); 
        cin >> n;

        if (cin.fail() || n < 0 || n > 4) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Ошибка: введите число от 0 до 4." << endl;
            continue; 
        }

        switch (n) {
        case 1:
            cin.ignore(); 
            cout << "Введите строку: ";
            getline(cin, s); 
            if (isValidString(s)) {
                AddString(s, root);
            }
            else {
                cout << "Ошибка: строка может содержать только буквы и пробелы." << endl;
            }
            break;
        case 2:
            cin.ignore();
            cout << "Введите строку: ";
            getline(cin, s);
            if (isValidString(s)) {
                DelString(s, root);
            }
            else {
                cout << "Ошибка: строка может содержать только буквы и пробелы." << endl;
            }
            break;
        case 3:
            cin.ignore();
            cout << "Введите строку: ";
            getline(cin, s);
            if (isValidString(s)) {
                SearchString(s, root);
            }
            else {
                cout << "Ошибка: строка может содержать только буквы и пробелы." << endl;
            }
            break;
        case 4:
            cout << "Строки в боре: " << endl;
            ShowBor(root);
            break;
        case 0:
            delete root->back_ptr;
            DelBor(root);
            cout << "Выход из программы." << endl;
            return 0;
        default:
            cout << "Введено необозначенное число." << endl;
        }
    } while (true);
}