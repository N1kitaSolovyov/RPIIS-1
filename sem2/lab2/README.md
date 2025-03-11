# Лабораторная работа №2
**Вариант №3** 
## Цели лабораторной работы:
Изучить основы теории множеств.
## Задачи лабораторной работы
Реализовать программу, формирующую множество равное симметрической разности исходных множеств (без учёта кратных вхождений элементов).

Изучить основы теории множеств.
## Список ключевых понятий:
**Множество** – это структурированный тип данных, представляющий собой набор взаимосвязанных по какому-либо признаку или группе признаков неповторяющихся объектов, которые можно рассматривать как единое целое.

**Симметрическая разность** – это набор элементов, которые принадлежат либо первому, либо второму множеству, но не их пересечению. Иными словами, симметрическая разность содержит все элементы обоих множеств, кроме общих.

## Описание используемых алгоритмов:
*Библиотека fstream*: содержит инструменты для работы с файлами.

1. **Создание и ввод множеств**
 
  1.1 Через условный оператор реализуется ввод множест
  
```cpp

  if (sets_count < 100) {
                std::cout << "Введите множество номер " << sets_count + 1 << "\n";
                std::getline(std::cin, sets[sets_count]);
                sets[sets_count] = removeSpaces(sets[sets_count]);
                sets_count++;
            }  
```


2.  С помощью функции *void removeDuplicates* реализуется проверка на ввод дубликатов

  
```cpp
void removeDuplicates(int& resultCount, std::string* result) {
    for (int i = 0; i < resultCount; ++i) {
        for (int j = i + 1; j < resultCount; ++j) {
            if (areElementsEqual(result[i], result[j])) {
               
                for (int k = j; k < resultCount - 1; ++k) {
                    result[k] = result[k + 1];
                }
                resultCount--;
                j--; 
            }
        }
    }
}

```


3. С помощью функции *void symmetricDifference* реализуется вычисление симметрической разности
   
   
```cpp

void symmetricDifference(std::string* set1, int count1, std::string* set2, int count2, std::string* result, int& resultCount) {
    resultCount = 0;
    for (int i = 0; i < count1; ++i) {
        bool found = false;
        for (int j = 0; j < count2; ++j) {
            if (areElementsEqual(set1[i], set2[j])) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[resultCount++] = set1[i];
        }
    }
    for (int i = 0; i < count2; ++i) {
        bool found = false;
        for (int j = 0; j < count1; ++j) {
            if (areElementsEqual(set2[i], set1[j])) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[resultCount++] = set2[i];
        }
    }

    
    removeDuplicates(resultCount, result);
}

```


4. С помощью функции *void save* реализуется сохрание множеств и их элементов в текстовый файл
   
 
```cpp
void save(const std::string* sets, int sets_count, const std::string* elements1, int count1, const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cout << "Ошибка открытия файла для записи\n";
        return;
    }

    fout << "Количество множеств: " << sets_count << std::endl;

    for (int i = 0; i < sets_count; i++) {
        std::string set_content = sets[i];
        std::string* elements = new std::string[100];
        int elements_count = 0;
        extractElements(set_content, elements, elements_count);
        removeDuplicates(elements_count, elements);
        std::string new_set = "{";
        for (int j = 0; j < elements_count; j++) {
            new_set += elements[j];
            if (j < elements_count - 1) {
                new_set += ",";
            }
        }
        new_set += "}";

        fout << "Множество " << (i + 1) << " = {" << new_set << "}" << std::endl;

        delete[] elements;
    }


    fout << "Симметрическая разность = {";
    for (int i = 0; i < count1; i++) {
        fout << elements1[i];
        if (i < count1 - 1) {
            fout << ", ";
        }
    }
    fout << "}" << std::endl;

    fout.close();
    std::cout << "Данные сохранены в файл " << filename << std::endl;
}


```

5. С помощью функции *void load* данные множеств и их элементов выгружаются из текстового файла

```cpp

void load(std::string* sets, int& sets_count, std::string* elements1, int& count1, const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла для чтения\n";
        return;
    }

    std::string line;
    std::getline(fin, line); 
    sets_count = std::stoi(line.substr(line.find(":") + 1));

    for (int i = 0; i < sets_count; i++) {
        std::getline(fin, line);
        std::string set_content = line.substr(line.find("{") + 1);

        int brace_count = 0;
        size_t start = 0;
        for (size_t j = 0; j < set_content.size(); j++) {
            if (set_content[j] == '{') {
                brace_count++;
            }
            else if (set_content[j] == '}') {
                brace_count--;
            }
          
            if (brace_count == 0) {
                sets[i] = set_content.substr(0, j + 1); // Извлекаем полное множество
                break;
            }
        }
    }

  
    std::getline(fin, line);
    line = line.substr(line.find("{") + 1, line.find("}") - line.find("{") - 1); 

    int pos = 0;
    count1 = 0;

    while ((pos = line.find(',')) != std::string::npos) {
        std::string element = line.substr(0, pos);
        elements1[count1++] = element; 
        line.erase(0, pos + 1);
    }
    
    if (!line.empty()) {
        elements1[count1++] = line;
    }

    for (int i = 0; i < count1; i++) {
        elements1[i].erase(remove(elements1[i].begin(), elements1[i].end(), ' '), elements1[i].end());
    }

    fin.close();
    std::cout << "Данные загружены из файла " << filename << std::endl;
}

```
## Тесты:
<img src="https://ltdfoto.ru/images/2025/03/11/SNIMOK-EKRANA_20250311_230535.png" alt="  Визуальный пример:" width="400" />
<img src="https://ltdfoto.ru/images/2025/03/11/SNIMOK-EKRANA_20250311_230732.png" alt="  Визуальный пример:" width="400" />
## Вывод:

В результате выполнения данной работы были получены следующие практические навыки:
Изучение теории множеств и выполнения операций над ними;
Работа header-файлами.





## Используемые источники:
1) **Создание библиотеки** :(https://www.youtube.com/watch?v=pAxEfF2yVlM&t=1s)
