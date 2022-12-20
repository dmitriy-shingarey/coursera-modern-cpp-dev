/* find minimum string from input of three strings */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string string1, string2,string3;
    cin >> string1 >> string2 >> string3;
    vector<string> inputs = {string1,string2,string3};  
    sort(begin(inputs), end(inputs));
    cout << "Mimimal string is: " << inputs[0];
    return 0;
}
