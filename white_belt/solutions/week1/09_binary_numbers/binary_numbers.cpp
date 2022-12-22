/* convert integer to binary number */

#include <iostream>
#include <vector>

using namespace std;

vector<int> dec2bin(int dec)
{
    vector<int> bits;
    while (dec != 0)
    {
        bits.push_back(dec % 2);
        dec = dec / 2;
    }
    return bits;
}

int main()
{

    int dec;

    cin >> dec;

    auto bits = dec2bin(dec);

    for (auto i = bits.size(); i > 0; i--)
    {
        cout << bits[i - 1];
    }

    cout << endl;

    return 0;
}