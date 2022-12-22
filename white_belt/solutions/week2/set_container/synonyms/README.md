# Programming Assignment: Synonyms

    Two words are called synonyms of each other if they have similar meanings.
    Implement the following operations on the dictionary of synonyms:

         * ADD word1 word2 - add a pair of synonyms (word1, word2) to the dictionary.

         * COUNT word - get the number of word synonyms.

         * CHECK word1 word2 - check if word1 and word2 are synonyms. Words word1 and word2 are considered synonyms, if among ADD queries there was at least one query ADD ADD word1 word2 or ADD word2 word1.