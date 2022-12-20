/* find if two given words are anagramms*/

#include <iostream>
#include <map>
#include <numeric>
#include <string>

using namespace std;

map<char, int> BuildCharCounters (const string & word){
    map<char, int> counter;
    for (auto c : word)
    {
        ++counter[c];
    }
    return counter;
}

int main() {
    int pair_number;
    string word1, word2;
    cout << "Enter number of pairs: ";
    cin >> pair_number;
    for (size_t i = 0; i < pair_number; i++)
    {
        cout << "Enter word pair " << i+1 << " : ";
        cin >> word1 >> word2;
        if (BuildCharCounters(word1)==BuildCharCounters(word2))
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}