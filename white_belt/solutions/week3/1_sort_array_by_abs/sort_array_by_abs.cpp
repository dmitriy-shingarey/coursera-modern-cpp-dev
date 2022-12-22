/* sort an array of integers by absolute value of integers*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool MyFunc(const int &i, const int &j) { return (abs(i) < abs(j)); }

void PrintVector(const vector<int> &A)
{
    for (auto item : A)
    {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    int vector_size, number;
    cin >> vector_size;
    vector<int> numbers(vector_size);

    for (auto i = 0; i < vector_size; i++)
    {
        cin >> number;
        numbers[i] = number;
    }

    PrintVector(numbers);

    sort(begin(numbers), end(numbers), MyFunc);

    PrintVector(numbers);
}