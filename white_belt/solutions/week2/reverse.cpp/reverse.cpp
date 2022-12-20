/* copy values from one vector "first" to the vector "second" and clear the values from the "first" vector */

#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& input){
    int tmp;
    for (auto i = 0; i <input.size()/2; i++)
    {
        tmp=input[i];
        input[i]=input[input.size()-i-1];
        input[input.size()-i-1]=tmp;
    }
}

int main() {
    vector<int> test = {1,2,3,4};
    Reverse(test);
    for (auto i : test)
    {
        cout << i;
    }
    return 0;
}