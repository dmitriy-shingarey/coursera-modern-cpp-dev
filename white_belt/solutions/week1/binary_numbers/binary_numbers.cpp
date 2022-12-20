/* convert integer to binary number */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int input;

    cout << "Enter integer number: ";
    cin >> input;
    vector<int> output;

    while (input>=1)
    {
        if (input%2 == 1)
        {
            output.push_back(1);
        }
        else
        {
            output.push_back(0);
        }
        input=input/2;
    }
    for (int i=0; i<=output.size()-1 ; i++)
    {
        cout << output[output.size()-i-1];
    }

    cout << endl;

}