/* update second string if first string is greater
Inputs: two strings */

#include <iostream>
#include <string>

using namespace std;

void UpdateIfGreater(string& first, string& second){
    if (first > second)
    {
        string tmp = second;
        second = first;
        first = tmp; 
    }
}

int main(){
    string string1, string2;
    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    UpdateIfGreater(string1,string2);
    cout << string1 << " " << string2 << endl;

    return 0;
}