/* copy values from one vector "first" to the vector "second" and clear the values from the "first" vector */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string> &src, vector<string> &dst)
{
    for (auto s : src)
    {
        dst.push_back(s);
    }
    src.clear()
}

void PrintVector(vector<string> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> source, destination;
    string word, line;

    cout << "Enter source vector separated by spaces: ";
    getline(cin, line);
    std::istringstream stream(line);
    while (stream >> word)
        source.push_back(word);

    cout << "Enter destination vector separated by spaces: ";
    getline(cin, line);
    std::istringstream stream2(line);
    while (stream2 >> word)
        destination.push_back(word);

    cout << "Before moving strings: " << endl;
    PrintVector(source);
    PrintVector(destination);

    MoveStrings(source, destination);

    cout << "After moving strings: " << endl;
    PrintVector(source);
    PrintVector(destination);

    return 0;
}