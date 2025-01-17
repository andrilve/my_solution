#pragma once

#include <iostream>
#include <string>

class Rational {
public:
    Rational() = default;
    Rational(int numerator, int denominator)
        : numerator_{ numerator }, denominator_{ denominator } {
    }

    friend std::istream& operator>>(std::istream& is, Rational& r);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

private:
    int numerator_ = 0;
    int denominator_ = 1;
};

inline std::istream& operator>>(std::istream& is, Rational& r) {
    char slash = '/';
    char input_slash;
    std::string numerator_str = "";

    is >> numerator_str;
    if (numerator_str.front() == '"' && numerator_str.back() == '"') {
        numerator_str.erase(numerator_str.begin());
        numerator_str.pop_back();
    }
    r.numerator_ = std::stoi(numerator_str);

    if (!(is >> input_slash)) {
        //is.clear();
        is.unget();
        return is;
    }

    if (input_slash != slash) {
        is.unget();
        r.denominator_ = 1;
        return is;
    }

    is >> r.denominator_;
    
    if(r.denominator_ == 0) is.setstate(std::ios::failbit);

    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rational& r) {
    using namespace std::literals;
    if (r.denominator_ == 1) {
        os << r.numerator_;
    }
    else {
        os << r.numerator_ << " / "s << r.denominator_;
    }
    
    return os;
}