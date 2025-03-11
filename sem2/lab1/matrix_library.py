class MatrixLibrary:
    def __init__(self):
        pass

    @staticmethod
    def global_sort(matrix):

        rows = len(matrix)
        cols = len(matrix[0]) if rows > 0 else 0

        # Объединяем все элементы в одномерный массив
        flattened = [element for row in matrix for element in row]

        # Сортируем одномерный массив
        flattened.sort()

        # Возвращаем двумерный массив исходного размера
        return [flattened[i * cols:(i + 1) * cols] for i in range(rows)]

    @staticmethod
    def insert_element(matrix, row_index, element):

        from bisect import insort
        if 0 <= row_index < len(matrix):
            insort(matrix[row_index], element)
        return matrix

    @staticmethod
    def search_element(matrix, row_index, element):

        if 0 <= row_index < len(matrix):
            return element in matrix[row_index]
        return False

    @staticmethod
    def merge_2d_arrays(matrix1, matrix2):

        if len(matrix1) != len(matrix2):
            raise ValueError("Обе матрицы должны иметь одинаковое количество строк.")
        merged_matrix = [
            sorted(matrix1[i] + matrix2[i]) for i in range(len(matrix1))
        ]
        return merged_matrix

    @staticmethod
    def intersect_2d_arrays(matrix1, matrix2):

        if len(matrix1) != len(matrix2):
            raise ValueError("Обе матрицы должны иметь одинаковое количество строк.")
        intersected_matrix = [
            sorted(set(matrix1[i]).intersection(matrix2[i])) for i in range(len(matrix1))
        ]
        return intersected_matrix
