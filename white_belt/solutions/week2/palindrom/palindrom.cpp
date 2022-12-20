/* find if an entered word is a palindrom or not */

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom (string word) {
    for (size_t i = 0; i < word.length() / 2 ; i++)
    {
        if (word[i] != word[word.length()-i-1])
        {
            return false;
        }
    }
    return true;
}

int main (){
    string entered_word;
    cout << "Enter a word: ";
    cin >> entered_word;
    cout << IsPalindrom(entered_word) << endl;
    return 0;
}