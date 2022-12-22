/* devide A over B and return quotient
A and B are numbers from 0 to 1 000 000
if B is zero - return impossible */

#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    if (b != 0)
    {
        std::cout << std::abs(a / b) << std::endl;
    }
    else
    {
        std::cout << "Impossible" << std::endl;
    }
    return 0;
}