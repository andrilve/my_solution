```md
# Перегрузка ввода и вывода для `std::pair<int, int>`

## Проблема
Для работы с `std::pair<int, int>` необходимо обращаться к элементам `first` и `second`. Это не всегда удобно. Решение — перегрузка операций ввода и вывода.

---

## Что нужно сделать
Перегрузите операции ввода и вывода для типа `std::pair<int, int>`.

- **Ввод:** Программа получает значения для каждого элемента:
  ```
  600
  27
  ```
  При некорректном вводе функция должна вернуть поток и оставить `pair` неизменным.

- **Вывод:** Пара должна быть представлена в формате:
  ```
  (600, 27)
  ```

---

## Подсказки
В заготовке даны вспомогательные функции:
- `FromString` — читает данные из строки.
- `ToString` — записывает данные в строку.

Эти функции используют перегрузки ввода-вывода, упрощая тестирование.

---

## Юнит-тесты

### Тест 1: Ввод пары
```cpp
assert((FromString("10 20\n"s) == std::pair{10, 20}));
assert((FromString("0 0\n"s) == std::pair{0, 0}));
assert((FromString("2 5666\n"s) == std::pair{2, 5666}));
assert((FromString("-27 -1000\n"s) == std::pair{-27, -1000}));
assert((FromString("2 -1.11116\n"s) == std::pair{2, -1}));
assert((FromString("5 -5+\n"s) == std::pair{5, -5}));

// Некорректный ввод
assert((FromString("6 -*\n"s) == std::pair{0, 0}));
assert((FromString("Ben 10\n"s) == std::pair{0, 0}));
assert((FromString("Ben Ten\n"s) == std::pair{0, 0}));
```

### Тест 2: Вывод пары
```cpp
assert((ToString(std::pair{0, 0}) == "(0, 0)"s));
assert((ToString(std::pair{1, 2}) == "(1, 2)"s));
assert((ToString(std::pair{-11, 27}) == "(-11, 27)"s));
assert((ToString(std::pair{-121, -2}) == "(-121, -2)"s));
```

---

## Ограничения
- Функции в заголовочных файлах должны быть **встроенными** (`inline`).

```cpp
#include <iostream>
#include <utility>
#include <sstream>
#include <string>

inline std::istream& operator>>(std::istream& is, std::pair<int, int>& p) {
    int first, second;
    if (is >> first >> second) {
        p = {first, second};
    } else {
        is.clear(std::ios::failbit);  // Устанавливаем флаг ошибки
    }
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

inline std::pair<int, int> FromString(const std::string& str) {
    std::istringstream iss(str);
    std::pair<int, int> p{0, 0};
    if (!(iss >> p)) {
        p = {0, 0};  // Возвращаем дефолтные значения при ошибке
    }
    return p;
}

inline std::string ToString(const std::pair<int, int>& p) {
    std::ostringstream oss;
    oss << p;
    return oss.str();
}
```

Теперь ваш код готов для использования и тестирования! 🚀
```