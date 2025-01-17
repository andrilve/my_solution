class Rational {
public:
    Rational(int numerator, int denominator)
        : numerator_(numerator)
        , denominator_(denominator) {
    }

    Rational(int num)
        : numerator_(num)
        , denominator_(1) {
    }

    // Перегрузка операции сравнения.
    // Вы научитесь этому в следующем уроке.
    bool operator==(const Rational& r) const {
        return (numerator_ == r.numerator_) &&
            (denominator_ == r.denominator_);
    }

    // Добавьте новый конструктор.
    // И реализуйте перегрузку присваивания.
    Rational& operator=(const int num) {
        numerator_ = num;
        denominator_ = 1;
        return *this;
    }

private:
    int numerator_ = 0;
    int denominator_ = 1;
};
