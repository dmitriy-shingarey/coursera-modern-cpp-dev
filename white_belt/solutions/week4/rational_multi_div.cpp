#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

class Rational
{
public:
    Rational()
    {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator)
    {
        int gcd_ = gcd(numerator, denominator);
        // cout << "GCD: " << gcd_ << endl;
        num = numerator / gcd_;
        den = denominator / gcd_;
    }

    int Numerator() const
    {
        return num;
    }

    int Denominator() const
    {
        return den;
    }

private:
    int num, den;
};

// Реализуйте для класса Rational операторы ==, + и -

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()));
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    Rational r(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
    return r;
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    Rational r(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
    return r;
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    Rational r(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
    return r;
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    Rational r(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
    return r;
}

// Реализуйте для класса Rational операторы * и /

int main()
{
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal)
        {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal)
        {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}