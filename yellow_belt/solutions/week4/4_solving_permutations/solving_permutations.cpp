/*
Given a positive integer N not exceeding 9. Output all permutations of numbers from 1 to N in reverse lexicographical order.
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
	for (auto it = vec.begin(); it < vec.end(); it++)
	{
		if (it != (vec.end() - 1))
		{
			os << *it << ' ';
		}
		else
		{
			os << *it;
		}
	}
	os << std::endl;
}
void PrintPermutations(const int size)
{
	std::vector<int> v(size);
	std::iota(v.rbegin(), v.rend(), 1);
	do
	{
		std::cout << v;
	} while (std::prev_permutation(v.begin(), v.end()));
}

int main()
{
	int n;
	std::cin >> n;
	PrintPermutations(n);
}