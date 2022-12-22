#include <iostream>
#include <numeric>
using namespace std;

class Rational
{
public:
    Rational()
    {
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(int numerator, int denominator)
    {
        int gcd_ = std::gcd(numerator, denominator);
        if (denominator < 0)
        {
            numerator_ = (-1) * numerator / gcd_;
            denominator_ = (-1) * denominator / gcd_;
        }
        else
        {
            numerator_ = numerator / gcd_;
            denominator_ = denominator / gcd_;
        }
    }

    int Numerator() const
    {
        return numerator_;
    }

    int Denominator() const
    {
        return denominator_;
    }

private:
    int numerator_;
    int denominator_;
};

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return (lhs.Denominator() == rhs.Denominator()) && (lhs.Numerator() == rhs.Numerator());
}

// Реализуйте для класса Rational операторы * и /

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational({lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()});
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    return Rational({lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()});
}

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