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

// Реализуйте для класса Rational операторы ==, + и -

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return (lhs.Denominator() == rhs.Denominator()) && (lhs.Numerator() == rhs.Numerator());
}

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    int num_, den_;
    num_ = lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator();
    den_ = lhs.Denominator() * rhs.Denominator();
    return {num_, den_};
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    int num_, den_;
    num_ = lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator();
    den_ = lhs.Denominator() * rhs.Denominator();
    return {num_, den_};
}

int main()
{
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal)
        {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal)
        {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal)
        {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
