/* find factorial for a number */

#include <iostream>

using namespace std;

int Factorial(int arg)
{
    if (arg > 1)
    {
        return arg * Factorial(arg - 1);
    }
    else
    {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int arg;
    cout << "Enter int to find a factorial: ";
    cin >> arg;
    cout << "Factorial of the element is: ";
    cout << Factorial(arg) << endl;
    return 0;
}
