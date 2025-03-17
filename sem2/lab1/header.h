#ifndef HEADER-H
#define HEADER_H

#include <vector>

namespace ArrayLib {
    // Ввод массива от пользователя
    void inputArray(std::vector<int>& arr);

    // Сортировка массива по возрастанию
    void sortArray(std::vector<int>& arr);

    // Бинарный поиск элемента: возвращает индекс или -1, если не найден
    int searchElement(const std::vector<int>& arr, int element);

    // Вставка элемента в отсортированный массив (с сохранением порядка)
    void insertIntoSortedArray(std::vector<int>& arr, int element);

    // Объединение двух отсортированных массивов без дубликатов
    std::vector<int> unionSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2);

    // Пересечение двух отсортированных массивов
    std::vector<int> intersectionSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2);

    // Вывод массива
    void printArray(const std::vector<int>& arr);

}

#endif // HEADER_H
