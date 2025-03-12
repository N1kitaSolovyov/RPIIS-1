# Лабораторная работа №1

## Цели лабораторной работы:
Разработать библиотеку для работы с деком на выбранном императивном языке программирования (например, C++, Java, Python).

## Задачи лабораторной работы:
Дек. Добавление элемента в начало или конец дека. Удаление элемента из начала или конца дека.

## Список используемых понятий:
**Дек** – структура, в которой добавление и извлечение элементов возможно с двух сторон.

## Описание используемых алгоритмов:

1. **Алгоритм создания первого элемента дека**
   
```cpp
void CreateDeque(DequeNode** front, DequeNode** rear, int value) {
    DequeNode* newNode = new DequeNode;
    newNode->info = value;
    newNode->next = newNode->prev = nullptr;
    *front = *rear = newNode;
}
```
![pic1](https://github.com/iis-42x70x/RPIIS/blob/Ганецкая_К/sem2/lab1/pic1.png?raw=true)

2. **Алгоритм добавления элемента в начало дека**
   
```cpp
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
        *rear = newNode; 
    }
}
```
![pic2](https://github.com/iis-42x70x/RPIIS/blob/Ганецкая_К/sem2/lab1/pic2.png?raw=true)

3. **Алгоритм добавления элемента в конец дека**   

```cpp
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
        *front = newNode; 
    }
}
```
![pic3](https://github.com/iis-42x70x/RPIIS/blob/Ганецкая_К/sem2/lab1/pic3.png?raw=true)

4. **Алгоритм удаления элемента из начала дека**
   
```cpp
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
        *rear = nullptr; 
    }

    delete temp; 
    return value; 
}
```
![pic4](https://github.com/iis-42x70x/RPIIS/blob/Ганецкая_К/sem2/lab1/pic4.png?raw=true)

5. **Алгоритм удаления элемента из конца дека**
   
```cpp
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
        *front = nullptr; 
    }

    delete temp; 
    return value; 
}
```
![pic5](https://github.com/iis-42x70x/RPIIS/blob/Ганецкая_К/sem2/lab1/pic5.png?raw=true)

6. **Алгоритм просмотра элемента дека**
   
```cpp
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
```
![pic6](https://github.com/iis-42x70x/RPIIS/blob/Ганецкая_К/sem2/lab1/pic%206.png?raw=true)

7. **Алгоритм очистки памяти дека**
   Этот алгоритм очищает дек, освобождая память, выделенную для каждого элемента.
   
```cpp
void ClearDeque(DequeNode** front, DequeNode** rear) {
    while (*front != nullptr) {
        DequeNode* temp = *front; 
        *front = (*front)->next; 
        delete temp; 
    }
    rear = nullptr; 
}
```
![pic7](https://github.com/iis-42x70x/RPIIS/blob/Ганецкая_К/sem2/lab1/pic7.png?raw=true)

## Вывод:

В результате выполнения данной работы были получены следующие практические навыки:


-изучение структуры очередь


-умение работать с header-файлами


-изучение базовых алгоритмов для работы со структурами типа деки.


## Используемые источники:
1) **Создание библиотеки** :(https://www.youtube.com/watch?v=pAxEfF2yVlM&t=1s)
2) **Деки в С++** :(https://metanit.com/cpp/tutorial/7.8.php)
