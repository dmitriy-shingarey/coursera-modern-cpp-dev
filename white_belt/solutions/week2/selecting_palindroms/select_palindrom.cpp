/* select palindroms of desired length from set of words*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/* check if a word is a palindrom */
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

/* find palindroms of desired length in word set */
vector<string> PalindromFilter (vector<string> words, int length){
    vector<string> palindroms;
    for (auto word : words)
    {
        if (word.length() <= length){
            if (IsPalindrom(word))
            {
                palindroms.push_back(word);
            }
        }
    }
    return palindroms;  
}

int main (){
    vector<string> entered_words, filtered_words;
    string word, line;
    int word_length;

    cout << "Enter words separated by spaces: ";
    getline(cin, line);
    istringstream stream(line);
    while (stream >> word)
        entered_words.push_back(word);

    cout << "Enter word length to be selected: ";
    cin >> word_length;

    filtered_words= PalindromFilter(entered_words,word_length);
    for (auto f_word : filtered_words){
        cout << f_word << endl;
    }

    return 0;
}