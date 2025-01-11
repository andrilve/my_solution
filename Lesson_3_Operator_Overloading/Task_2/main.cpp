#include <iostream>
#include <string>
#include <vector>

using namespace std::literals;

// �������� ���� ������ �� ����������.
const std::vector<std::string> WEEKDAY_NAMES = {
    "Monday"s, "Tuesday"s,  "Wednesday"s, "Thursday"s,
    "Friday"s, "Saturday"s, "Sunday"s,    "Unknown"s };

enum class Weekday {
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    UNKNOWN
};

Weekday operator+(const Weekday& day, int value) {
    if (day == Weekday::UNKNOWN) {
        // ���������� ������ �������.
        return day;
    }
    // �������, ������� ���� ������ � ������ ������.
    const auto weekdays = static_cast<int>(day) + value;
    constexpr auto days = static_cast<int>(Weekday::UNKNOWN);
    // ������� ���������� ����� ��� ������ �� 0.
    const auto weekday_number = (weekdays % days + days) % days;
    // ����������� ��� � Weekday (������������ ������� ��������������),
    // ����������, ��� �������� ��������� � ��������� ���� ������.
    return static_cast<Weekday>(weekday_number);
}

Weekday operator-(const Weekday& day, int value) { return day + -value; }

void Print(std::ostream& stream, Weekday day) {
    // ���������� ������������ ��������.
    if (day == Weekday::UNKNOWN) {
        // ���������� ������ �������.
        stream << "Wrong value!"s;
        return;
    }
    // ���������� �������� �������.
    stream << WEEKDAY_NAMES[static_cast<int>(day)];
}

Weekday Read(std::istream& day) {
    std::string str;
    day >> str;
    for (size_t i = 0; i < WEEKDAY_NAMES.size(); ++i) {
        if (WEEKDAY_NAMES[i] == str) {
            return static_cast<Weekday>(i);
        }
    }
    return Weekday::UNKNOWN;
}

int main() {
    char operand;
    int n;

    Weekday day = Read(std::cin);
    std::cin >> operand >> n;

    switch (operand) {
    case '+':
        Print(std::cout, day + n);
        break;
    case '-':
        Print(std::cout, day - n);
        break;
    default:
        std::cout << "Undefined symbol!";
    }
}