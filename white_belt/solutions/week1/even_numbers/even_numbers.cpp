/* given two number A and B (A <= B, A >= 1, B <= 30000).
   Find all even numbers between them.

Inputs: 
    A, B 
Outputs:
    all even numbers betwenn A and B */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int A, B;
    cout << "Enter A and B: ";
    cin >> A >> B;

    for ( auto i = A; i <= B; i++)
    {
        if (i % 2 == 0) 
        {
        // i - even numbers
        cout << i << " ";
        } 
        else 
        {
        // i - uneven numbers
        }
    }
    cout << endl;

    return 0;
}