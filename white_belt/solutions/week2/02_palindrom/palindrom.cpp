/* find if an entered word is a palindrom or not */

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string word)
{
    for (auto i = 0; i < word.size() / 2; i++)
    {
        if (word[i] != word[word.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    string word;
    cin >> word;
    cout << IsPalindrom(word) << endl;
    return 0;
}