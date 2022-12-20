/* devide A over B and return quotient
A and B are numbers from 0 to 1 000 000
if B is zero - return impossible */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int divisor, dividend, quotient;
    
    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    if (divisor == 0)
    {
        cout << "Division by 0 is impossible! " << endl;
    }
    else
    {
        quotient = dividend / divisor;
        cout << "Quotient = " << quotient << endl;
    }
    
    return 0;
    
}