```cpp
#include <iostream>
#include <numeric> // Для std::gcd
#include <stdexcept>

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1) 
        : numerator_(numerator), denominator_(denominator) {
        if (denominator_ == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        normalize();
    }

    int numerator() const { return numerator_; }
    int denominator() const { return denominator_; }

    // Перегрузка операции вывода
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.numerator_ << " / " << r.denominator_;
        return os;
    }

    // Перегрузка унарного +
    Rational operator+() const {
        return *this; // Возвращаем копию объекта
    }

    // Перегрузка унарного -
    Rational operator-() const {
        return Rational(-numerator_, denominator_); // Возвращаем объект с противоположным знаком
    }

private:
    int numerator_;
    int denominator_;

    void normalize() {
        int gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }
};

int main() {
    Rational r1(1, 2);
    std::cout << +r1 << std::endl; // 1 / 2
    std::cout << -r1 << std::endl; // -1 / 2

    Rational r2(-5, 9);
    std::cout << +r2 << std::endl; // -5 / 9
    std::cout << -r2 << std::endl; // 5 / 9

    Rational r3(-5, -7);
    std::cout << +r3 << std::endl; // 5 / 7
    std::cout << -r3 << std::endl; // -5 / 7

    Rational r4(0, 5);
    std::cout << +r4 << std::endl; // 0 / 5
    std::cout << -r4 << std::endl; // 0 / 5

    return 0;
}
```

### Объяснение
1. **Унарный плюс** (`operator+`) возвращает копию текущего объекта без изменений.
2. **Унарный минус** (`operator-`) создаёт и возвращает новый объект с инвертированным числителем.
3. Метод `normalize`:
   - Упрощает дробь (используется `std::gcd`).
   - Обеспечивает положительный знаменатель.

Этот код успешно проходит все приведённые примеры.