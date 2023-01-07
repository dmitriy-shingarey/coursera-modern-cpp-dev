/*
Write a template function RemoveDuplicates that takes a vector of elements objects of type T by reference and removes all duplicate elements from it. The order of the remaining elements can be anything.

It is guaranteed that objects of type T can be compared using operators ==, !=, <and>
*/

#include "removing_duplicates.h"
#include <iostream>

int main()
{
	std::vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
	RemoveDuplicates(v1);
	for (int x : v1)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::vector<std::string> v2 = {"C", "C++", "C++", "C", "C++"};
	RemoveDuplicates(v2);
	for (const std::string &s : v2)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;
	return 0;
}