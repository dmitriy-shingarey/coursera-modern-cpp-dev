#include <iostream>
#include <map>
#include <set>
#include <vector>
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

    void Update(int numerator, int denominator)
    {
        int gcd_ = gcd(numerator, denominator);
        // cout << "GCD: " << gcd_ << endl;
        num = numerator / gcd_;
        den = denominator / gcd_;
    }

    Rational(int numerator, int denominator)
    {
        Update(numerator, denominator);
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
bool operator<(const Rational &lhs, const Rational &rhs)
{
    cout << "Lhs: " << (float)lhs.Numerator() / (float)lhs.Denominator() << " " << (float)rhs.Numerator() / (float)rhs.Denominator() << endl;
    return (((float)lhs.Numerator() / (float)lhs.Denominator()) < ((float)rhs.Numerator() / (float)rhs.Denominator()));
}

bool operator!=(const vector<Rational> &lhs, const vector<Rational> &rhs)
{
    return (lhs.size() != rhs.size());
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main()
{
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3)
        {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs)
        {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}})
        {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2)
        {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}