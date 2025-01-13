#pragma once
#pragma once

#include <iostream>
#include <sstream>

inline std::istream& operator>>(std::istream& is, std::pair<int, int>& pair_int) {
    is >> pair_int.first >> pair_int.second; // ���������� ��������.
    return is; // ���������� ������ �� �����.
}

// ���������� ������ ��� Date.
inline std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& pair_int) {
    using namespace std::literals;
    os << "("s << pair_int.first << ", "s << pair_int.second << ")"s;
    return os;
}

// ������� ��� ������ �������� � ������.
inline std::string ToString(std::pair<int, int> p) {
    std::ostringstream buffer;
    buffer << p;
    return buffer.str();
}

// ������� ��� ������ �������� � ������.
inline std::pair<int, int> FromString(std::string str) {
    std::istringstream is(str);
    std::pair<int, int> p;
    if (is >> p) {
        return p;
    }
    return { 0, 0 };
}