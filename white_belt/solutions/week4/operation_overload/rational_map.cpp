#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
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
        Set(numerator, denominator);
    }

    void SetNewValues(int numerator, int denumerator)
    {
        Set(numerator, denumerator);
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
    void Set(int &numerator, int &denominator)
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
};

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return (lhs.Denominator() == rhs.Denominator()) && (lhs.Numerator() == rhs.Numerator());
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator<(const Rational &lhs, const Rational &rhs)
{
    return ((float)lhs.Numerator() / (float)lhs.Denominator()) < ((float)rhs.Numerator() / (float)rhs.Denominator());
}

bool operator!=(const Rational &lhs, const Rational &rhs)
{
    return (lhs.Numerator() != rhs.Numerator()) || (lhs.Denominator() != rhs.Denominator());
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

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational({lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()});
}

ostream &operator<<(ostream &stream, const Rational &rational)
{
    stream << to_string(rational.Numerator());
    stream << "/";
    stream << to_string(rational.Denominator());
    return stream;
}

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