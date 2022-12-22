/* find day temperatures above average
Input:
    N: number of measurements. Temperature for a day
    values: measurement values
Output:
    K: number of days with temperature above average
    numbers: days numbers  */

#include <iostream>
#include <vector>

using namespace std;

int FindAverage(const vector<int> &v)
{
    int sum = 0;
    for (auto el : v)
    {
        sum = sum + el;
    }
    return (sum / v.size());
}

void FindIndAboveAverage(vector<int> &v_above, const vector<int> &v)
{
    int av = FindAverage(v);
    int i = 0;
    for (auto el : v)
    {
        if (el > av)
        {
            v_above.push_back(i);
        }
        ++i;
    }
}

void PrintVector(const vector<int> &v)
{
    for (auto el : v)
    {
        cout << el << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int v_size;
    cin >> v_size; // enter number of vector elements
    vector<int> v(v_size, 0);
    for (int &el : v)
    {
        cin >> el; // enter temperature for day
    }
    vector<int> v_above;
    FindIndAboveAverage(v_above, v);
    cout << v_above.size() << endl;
    PrintVector(v_above);
}