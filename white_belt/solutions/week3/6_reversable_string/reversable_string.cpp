
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReversibleString
{
private:
    /* data */
    string s;

public:
    ReversibleString(/* args */){};
    ReversibleString(const string &new_string)
    {
        s = new_string;
    };
    ~ReversibleString();

    string ToString() const
    {
        return s;
    }
    void Reverse()
    {
        reverse(s.begin(), s.end());
    }
};

ReversibleString::ReversibleString(/* args */)
{
}

ReversibleString::~ReversibleString()
{
}

int main()
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString &s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}