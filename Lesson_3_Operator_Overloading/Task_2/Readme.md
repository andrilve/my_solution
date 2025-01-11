### Задача: Работа с перечисляемым типом Weekday

В прошлой задаче вы перегрузили операции. В этой задаче код перегрузки уже дан в заготовке. Ваша задача — вызывать перегруженные операции.

#### Данные функции и тип
В заготовке дан перечислимый тип `enum class Weekday` и следующие функции для работы с ним:

```cpp
Weekday operator+(const Weekday &day, int value);
Weekday operator-(const Weekday &day, int value);
void Print(std::ostream &stream, Weekday day);
Weekday Read(std::istream &day);
```

#### Что нужно сделать
Нужно реализовать функцию `main`, которая:

1. Прочитает день недели, операцию и число `N` из `std::cin`.
2. Если операция "+", то выведет, какой день будет через `N` дней после прочитанного дня.
3. Если операция "-", то выведет, какой день был за `N` дней до прочитанного дня.

#### Пример реализации функции main

```cpp
#include <iostream>
#include "weekday.h" // Здесь предполагается, что объявлены функции и тип Weekday

int main() {
    Weekday day;
    char operation;
    int N;

    // Считываем входные данные
    day = Read(std::cin);
    std::cin >> operation >> N;

    // Обрабатываем операции
    if (operation == '+') {
        Print(std::cout, day + N);
    } else if (operation == '-') {
        Print(std::cout, day - N);
    } else {
        std::cerr << "Некорректная операция" << std::endl;
    }

    return 0;
}