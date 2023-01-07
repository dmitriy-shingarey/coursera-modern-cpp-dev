#pragma once

#include <algorithm>
#include <vector>

template <typename T>
void RemoveDuplicates(std::vector<T> &elements)
{
	std::sort(elements.begin(), elements.end());
	auto last = std::unique(elements.begin(), elements.end());
	elements.erase(last, elements.end());
}