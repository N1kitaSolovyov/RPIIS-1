from matrix_library import MatrixLibrary
def get_matrix_from_input():
    matrix = []
    rows = int(input("Введите количество строк в массиве: "))
    cols = int(input("Введите количество столбцов в массиве: "))
    print("Введите элементы массива построчно (через пробел):")
    for i in range(rows):
        row = list(map(int, input(f"Введите элементы для строки {i + 1}: ").split()))
        while len(row) != cols:
            print(f"Ошибка! Введите ровно {cols} элементов.")
            row = list(map(int, input(f"Введите элементы для строки {i + 1}: ").split()))
        matrix.append(row)
    return matrix

if __name__ == "__main__":
    # Получение первого двумерного массива
    print("Введите первый двумерный массив:")
    matrix1 = get_matrix_from_input()

    print("\nИсходная матрица 1:")
    for row in matrix1:
        print(row)
    # Глобальная сортировка первого массива
    sorted_matrix1 = MatrixLibrary.global_sort(matrix1)
    print("\nМатрица 1 после глобальной сортировки:")
    for row in sorted_matrix1:
        print(row)

    # Вставка элемента в первый массив
    row_index = int(input("\nВведите номер строки для вставки элемента в Матрицу 1 (начиная с 0): "))
    element = int(input("Введите элемент для вставки: "))
    updated_matrix1 = MatrixLibrary.insert_element(sorted_matrix1, row_index, element)
    print("\nМатрица 1 после вставки элемента:")
    for row in updated_matrix1:
        print(row)

    # Получение второго двумерного массива
    print("\nВведите второй двумерный массив:")
    matrix2 = get_matrix_from_input()

    print("\nИсходная матрица 2:")
    for row in matrix2:
        print(row)

    # Глобальная сортировка второго массива
    sorted_matrix2 = MatrixLibrary.global_sort(matrix2)
    print("\nМатрица 2 после глобальной сортировки:")
    for row in sorted_matrix2:
        print(row)

    # Объединение двух матриц
    try:
        merged_matrix = MatrixLibrary.merge_2d_arrays(sorted_matrix1, sorted_matrix2)
        print("\nОбъединение двух матриц:")
        for row in merged_matrix:
            print(row)
    except ValueError as e:
        print(f"\nОшибка объединения матриц: {e}")

    # Пересечение двух матриц
    try:
        intersected_matrix = MatrixLibrary.intersect_2d_arrays(sorted_matrix1, sorted_matrix2)
        print("\nПересечение двух матриц:")
        for row in intersected_matrix:
            print(row)
    except ValueError as e:
        print(f"\nОшибка пересечения матриц: {e}")
