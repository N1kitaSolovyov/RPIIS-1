#include <iostream>
#include "..\LibraryLab\Header.h"

int main() {
    std::vector<int> arr1, arr2;
    bool exitProgram = false;

    while (!exitProgram) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Ввести первый массив\n";
        std::cout << "2. Ввести второй массив\n";
        std::cout << "3. Сортировать первый массив\n";
        std::cout << "4. Сортировать второй массив\n";
        std::cout << "5. Вставить элемент в первый массив\n";
        std::cout << "6. Вставить элемент во второй массив\n";
        std::cout << "7. Найти элемент в первом массиве\n";
        std::cout << "8. Объединить массивы\n";
        std::cout << "9. Пересечение массивов\n";
        std::cout << "0. Выйти\n";
        std::cout << "Выберите действие: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            ArrayLib::inputArray(arr1);
            break;
        case 2:
            ArrayLib::inputArray(arr2);
            break;
        case 3:
            if (!arr1.empty()) {
                ArrayLib::sortArray(arr1);
                std::cout << "Отсортированный первый массив: ";
                ArrayLib::printArray(arr1);
            }
            else {
                std::cout << "Массив пуст!\n";
            }
            break;
        case 4:
            if (!arr2.empty()) {
                ArrayLib::sortArray(arr2);
                std::cout << "Отсортированный второй массив: ";
                ArrayLib::printArray(arr2);
            }
            else {
                std::cout << "Массив пуст!\n";
            }
            break;
        case 5: {
            int elem;
            std::cout << "Введите элемент для вставки: ";
            std::cin >> elem;
            ArrayLib::insertIntoSortedArray(arr1, elem);
            std::cout << "Массив после вставки: ";
            ArrayLib::printArray(arr1);
            break;
        }
        case 6: {
            int elem;
            std::cout << "Введите элемент для вставки: ";
            std::cin >> elem;
            ArrayLib::insertIntoSortedArray(arr2, elem);
            std::cout << "Массив после вставки: ";
            ArrayLib::printArray(arr2);
            break;
        }
        case 7: {
            int elem;
            std::cout << "Введите элемент для поиска: ";
            std::cin >> elem;
            int index = ArrayLib::searchElement(arr1, elem);
            if (index != -1) std::cout << "Элемент найден на позиции: " << index << "\n";
            else std::cout << "Элемент не найден.\n";
            break;
        }
        case 8:
            if (!arr1.empty() && !arr2.empty()) {
                ArrayLib::sortArray(arr1);
                ArrayLib::sortArray(arr2);
                std::vector<int> result = ArrayLib::unionSortedArrays(arr1, arr2);
                std::cout << "Объединенный массив: ";
                ArrayLib::printArray(result);
            }
            else {
                std::cout << "Один из массивов пуст!\n";
            }
            break;
        case 9:
            if (!arr1.empty() && !arr2.empty()) {
                ArrayLib::sortArray(arr1);
                ArrayLib::sortArray(arr2);
                std::vector<int> result = ArrayLib::intersectionSortedArrays(arr1, arr2);
                std::cout << "Пересечение массивов: ";
                ArrayLib::printArray(result);
            }
            else {
                std::cout << "Один из массивов пуст!\n";
            }
            break;
        case 0:
            exitProgram = true;
            break;
        default:
            std::cout << "Неверный ввод, попробуйте снова!\n";
            break;
        }
    }

    return 0;
}
