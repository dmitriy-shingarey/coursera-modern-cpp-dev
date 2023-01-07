/*
Дано целое положительное число N, не превышающее 9.
Выведите все перестановки чисел от 1 до N в обратном лексикографическом порядке.
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
	std::iota(v.begin(), v.end(), 1);
	do
	{
		std::cout << v;
	} while (std::next_permutation(v.begin(), v.end()));
}

int main()
{
	int n;
	std::cin >> n;
	PrintPermutations(n);
}