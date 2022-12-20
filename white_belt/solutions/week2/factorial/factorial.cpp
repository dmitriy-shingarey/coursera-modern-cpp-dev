/* find factorial for a number */

#include <iostream>

using namespace std;

/* factorial function*/
int Factorial(int number) {
    
    int out=1;
    
    if (number<0)
    {
        return 1;
    }
    
    for (int i = 1; i <= number; i++)
    {
        out=i*out;
    }
    return out;
}

/* mian function */
int main() {
    int entered_number;
    cout << "Enter number: ";
    cin >> entered_number;
    cout << "Factorial for the number " << entered_number << " is: " << Factorial(entered_number) << endl;
    return 0;
}