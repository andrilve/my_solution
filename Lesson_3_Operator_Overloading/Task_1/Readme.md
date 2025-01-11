

```md
# Задача: Использование перегруженных операций

В прошлой задаче вы перегрузили операции. В этой задаче код перегрузки уже дан в заготовке. Ваша задача — вызывать перегруженные операции.

## Условие

В заготовке дан перечислимый тип `enum class Weekday` и следующие функции для работы с ним:

```cpp
Weekday operator+(const Weekday &day, int value);
Weekday operator-(const Weekday &day, int value);
void Print(std::ostream &stream, Weekday day);
Weekday Read(std::istream &stream);
```

## Что нужно сделать

Необходимо реализовать функцию `main`, которая выполняет следующие действия:

1. Прочитает из `std::cin`:
   - День недели.
   - Операцию (`+` или `-`).
   - Число `N`.
2. Если операция — `+`, то выведет, какой день будет через `N` дней после прочитанного дня.
3. Если операция — `-`, то выведет, какой день был за `N` дней до прочитанного дня.

Результат необходимо вывести в `std::cout` с использованием функции `Print`.

## Пример ввода
```
Monday
+ 3
```

## Пример вывода
```
Thursday
```
```cpp
#include <iostream>
#include <string>
#include <stdexcept>

// Предположим, что enum Weekday и необходимые функции уже определены

int main() {
    Weekday day;
    char operation;
    int N;

    // Чтение данных
    try {
        day = Read(std::cin);
        std::cin >> operation >> N;

        if (operation == '+') {
            Print(std::cout, day + N);
        } else if (operation == '-') {
            Print(std::cout, day - N);
        } else {
            throw std::invalid_argument("Неподдерживаемая операция");
        }
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
```
## Замечания

1. Используйте предоставленные функции `operator+`, `operator-`, `Read` и `Print` для работы с типом `Weekday`.
2. Учтите, что операции должны быть корректными — обработайте ошибки, если операция или ввод некорректны.
```