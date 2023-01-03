/*
Write a PrintVectorPart function that takes a vector of integers numbers,
searches for the first negative number in it and outputs to the standard
output all numbers, to the left of the found one, in reverse order.
If the vector does not contain negative numbers, print all numbers in
reverse order.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void PrintVectorPart(const std::vector<int> &numbers)
{
    auto it = numbers.end();
    it = std::find_if(numbers.begin(), numbers.end(), [](const int &n)
                      { return n < 0; });

    while (it != numbers.begin())
    {
        --it;
        std::cout << *it << " ";
    }
}

int main()
{
    PrintVectorPart({6, 1, 8, -5, 4}); // 8, 1, 6 will be printed
    std::cout << std::endl;
    PrintVectorPart({-6, 1, 8, -5, 4}); // nothing will be printed
    std::cout << std::endl;
    PrintVectorPart({6, 1, 8, 5, 4}); // nothing will be printed
    std::cout << std::endl;
    PrintVectorPart({}); // nothing will be printed
    std::cout << std::endl;
    return 0;
}