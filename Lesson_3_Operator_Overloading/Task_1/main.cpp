#include <iostream>
#include <utility>
#include <string>
#include <cassert>

// Определим пару.
using Vector2I = std::pair<int, int>;

Vector2I operator+(const Vector2I& vect1, const Vector2I& vect2);
Vector2I operator-(const Vector2I& vect1, const Vector2I& vect2);
Vector2I operator*(const Vector2I& vect, int value);
void Print(std::ostream& str, const Vector2I& vect);
Vector2I Read(std::istream& str);

const std::string open_cnst = "{";
const std::string comma_cnst = ",";
const std::string close_cnst = "}";

int main() {
    Vector2I point1;
    Vector2I point2;
    char op_sym;
    int val;

    point1 = Read(std::cin);
    std::cin >> op_sym;
    // Выведем элементы пары.
    switch (op_sym) {
    case '+':
        point2 = Read(std::cin);
        // Тут теперь операция сложения пар.
        Print(std::cout, point1 + point2);
        break;
    case '-':
        point2 = Read(std::cin);
        // Тут вычитание.
        Print(std::cout, point1 - point2);
        break;
    case '*':
        std::cin >> val;
        // А тут умножение пары на число.
        Print(std::cout, point1 * val);
        break;
    default:
        std::cout << "Undefined symbol!";
    }
    std::cout << std::endl;
}

Vector2I operator+(const Vector2I& vect1, const Vector2I& vect2) {
    return { vect1.first + vect2.first , vect1.second + vect2.second };
}

Vector2I operator-(const Vector2I& vect1, const Vector2I& vect2) {
    return { vect1.first - vect2.first , vect1.second - vect2.second };
}

Vector2I operator*(const Vector2I& vect, int value) {
    return { vect.first * value , vect.second * value };
}

void Print(std::ostream& str, const Vector2I& vect) {
    str << open_cnst << vect.first << comma_cnst << vect.second << close_cnst;
}

Vector2I Read(std::istream& str) {
    char open_brace, comma, close_brace;
    Vector2I res;

    str >> open_brace >> res.first  >> comma >> res.second >> close_brace;

    assert(open_brace == open_cnst[0] && comma == comma_cnst[0] && close_brace == close_cnst[0]);

    return { res.first, res.second };
}