/* sort an array of chars by absolute value of integers*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool MyFunc(const int &i, const int &j) { return (abs(i) < abs(j)); }

void PrintVector(const vector<char> &A)
{
    for (auto item : A)
    {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    int vector_size;
    char input_char;
    cin >> vector_size;
    vector<char> chars(vector_size);

    for (auto i = 0; i < vector_size; i++)
    {
        cin >> input_char;
        chars[i] = tolower(input_char);
    }

    PrintVector(chars);

    sort(begin(chars), end(chars));

    PrintVector(chars);
}