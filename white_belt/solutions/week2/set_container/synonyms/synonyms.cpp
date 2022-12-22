#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    string input;
    int nr_of_operations;
    cin >> nr_of_operations;
    getline(cin, input);
    string word1, word2;
    string command;
    set<set<string>> set_of_synonyms;
    map<string, int> word_counter;

    for (size_t i = 0; i < nr_of_operations; i++)
    {
        getline(cin, input);
        std::istringstream iss(input);
        iss >> command;

        if (command == "ADD")
        {
            iss >> word1;
            iss >> word2;
            set<string> set_of_words = {word1, word2};

            if (word_counter.count(word1) == 0)
            {
                word_counter[word1] = 1;
            }
            else
            {
                if (set_of_synonyms.count(set_of_words) == 0)
                {
                    ++word_counter[word1];
                }
            }
            if (word_counter.count(word2) == 0)
            {
                word_counter[word2] = 1;
            }
            else
            {
                if (set_of_synonyms.count(set_of_words) == 0)
                {
                    ++word_counter[word2];
                }
            }
            set_of_synonyms.insert({word1, word2});
        }
        if (command == "COUNT")
        {
            iss >> word1;
            int i = 0;
            cout << word_counter[word1] << endl;
        }
        if (command == "CHECK")
        {
            iss >> word1;
            iss >> word2;
            set<string> set_of_words = {word1, word2};
            string answer = "NO";
            if (set_of_synonyms.count(set_of_words))
            {
                answer = "YES";
            }
            cout << answer << endl;
        }
    }
}
