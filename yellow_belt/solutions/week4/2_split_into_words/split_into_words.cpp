#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string &s)
{
    vector<string> v;
    auto it = s.begin();
    while (it != s.end())
    {
        auto it_prev = it;
        it = find(it_prev, s.end(), ' '); // find next space
        if ((it != it_prev))              // if there is a space
        {
            v.push_back(string(it_prev, it)); // add string to a vector
            if (it != s.end())
            {
                it++; // jump over a previous space to the beginning of the next word
            }
        }
    }
    return v;
}

int main()
{
    string s = "Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it)
    {
        if (it != begin(words))
        {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}