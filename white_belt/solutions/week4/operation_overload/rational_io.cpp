#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
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

    // void SetNumerator(string numerator_str) {
    //     Set(stoi(numerator_str), denominator_);
    // }
    //
    // void SetDenominator(string denominator_str) {
    //    Set(numerator_, stoi(denominator_str));
    //}

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

// Implement << and >> operators for Rational class

ostream &operator<<(ostream &stream, const Rational &rational)
{
    stream << to_string(rational.Numerator());
    stream << "/";
    stream << to_string(rational.Denominator());
    return stream;
}

istream &operator>>(istream &stream, Rational &rational)
{
    int num_, den_;
    char op;
    int sign_num = 1;
    int sign_den = 1;
    while (stream >> ws)
    {
        char n = stream.peek();

        // while (n == ' ')
        //{
        //     stream.ignore();
        //     n = stream.peek();
        // }
        if (n == '-')
        {
            stream.ignore();
            sign_num = -1;
            n = stream.peek();
        }
        if (std::isdigit(stoi(to_string(n))))
        {
            stream >> num_;
        }
        else
        {
            return stream;
        }
        char c = stream.peek();
        if (c == '/')
        {
            stream >> op;
        }
        else
        {
            return stream;
        }
        // stream.get(op);
        char d = stream.peek();
        if (d == '-')
        {
            stream.ignore();
            sign_den = -1;
            d = stream.peek();
        }
        if (std::isdigit(stoi(to_string(d))))
        {
            stream >> den_;
            // cout << "num_: " << num_ << endl;
            // cout << "den_: " << den_ << endl;
            rational.SetNewValues(num_ * sign_num, den_ * sign_den);
            return stream;
        }
        else
        {
            return stream;
        }

        // if ( std::isdigit(d) ){
        //     stream >> den_;
        //     cout << "den: " << den_ << endl;
        //     rational.SetNewValues(num_*sign_num, den_);
        //     return stream;
        // }
    }
    return stream;
}

// istream& operator >> (istream& is, Rational& r) {
//   int n, d;
//   char c;
//
//   if (is) {
//       is >> n >> c >> d;
//       if (is) {
//           if (c == '/') {
//               r = Rational(n, d);
//           }
//           else {
//               is.setstate(ios_base::failbit);
//           }
//       }
//   }
//
//   return is;
// }

int main()
{
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4")
        {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal)
        {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        input >> r;
        bool correct = !(input >> r);
        if (!correct)
        {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
        {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
        {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct)
        {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct)
        {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }
    {
        istringstream input("-5/-7 -10/-8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
        {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
