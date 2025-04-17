#include "Rational.h"

void Rational::Normalize() {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    
    // Приводим знаменатель к положительному виду
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    // Сокращаем дробь
    int gcd = std::gcd(std::abs(numerator), std::abs(denominator));
    if (gcd != 0) {
        numerator /= gcd;
        denominator /= gcd;
    }
}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    Normalize();
}

int Rational::Numerator() const { return numerator; }
int Rational::Denominator() const { return denominator; }

Rational Rational::operator+(const Rational& rhs) const {
    return Rational(
        numerator * rhs.denominator + rhs.numerator * denominator,
        denominator * rhs.denominator
    );
}

Rational Rational::operator-(const Rational& rhs) const {
    return Rational(
        numerator * rhs.denominator - rhs.numerator * denominator,
        denominator * rhs.denominator
    );
}

Rational Rational::operator*(const Rational& rhs) const {
    return Rational(
        numerator * rhs.numerator,
        denominator * rhs.denominator
    );
}

Rational Rational::operator/(const Rational& rhs) const {
    return Rational(
        numerator * rhs.denominator,
        denominator * rhs.numerator
    );
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational& Rational::operator+=(const Rational& rhs) {
    *this = *this + rhs;
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    *this = *this - rhs;
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
    *this = *this * rhs;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    *this = *this / rhs;
    return *this;
}

bool Rational::operator==(const Rational& rhs) const {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

bool Rational::operator!=(const Rational& rhs) const {
    return !(*this == rhs);
}

// Реализации дружественных операторов с int
Rational operator+(const Rational& r, int value) {
    return r + Rational(value);
}

Rational operator+(int value, const Rational& r) {
    return Rational(value) + r;
}

Rational operator-(const Rational& r, int value) {
    return r - Rational(value);
}

Rational operator-(int value, const Rational& r) {
    return Rational(value) - r;
}

Rational operator*(const Rational& r, int value) {
    return r * Rational(value);
}

Rational operator*(int value, const Rational& r) {
    return Rational(value) * r;
}

Rational operator/(const Rational& r, int value) {
    return r / Rational(value);
}

Rational operator/(int value, const Rational& r) {
    return Rational(value) / r;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerator << "/" << r.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    int num, denom = 1;
    char slash;
    
    if (is >> num) {
        if (is >> slash && slash == '/') {
            if (is >> denom) {
                r = Rational(num, denom);
                return is;
            }
        } else {
            // Если нет слэша, значит ввели целое число
            is.putback(slash);
            r = Rational(num);
            return is;
        }
    }
    
    is.setstate(std::ios::failbit);
    return is;
}