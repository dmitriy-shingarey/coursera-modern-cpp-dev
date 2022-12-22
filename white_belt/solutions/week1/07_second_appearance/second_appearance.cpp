/* given a string.
   find second appearance of the letter "f" in that strinf and print an index.

Inputs:
    string
Outputs:
    - print index of the second appearance
    - if no second appearance print:
         -1 if "f" appears only once
         -2 if "f" does not appear
     */

#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int count = 0;
    int pos = -2;
    char ch = 'f';

    for (auto i = 0; i < str.length(); i++)
    {
        if (str[i] == ch)
        {
            if (count == 0)
            {
                pos = -1;
                count = count + 1;
            }
            else if (count == 1)
            {
                pos = i;
                count = count + 1;
            }
        }
    }

    cout << pos << endl;

    return 0;
}
}