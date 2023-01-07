# Iterators, algorithms, and containers

## [Programming Practice Assignment: Vector Part](1_vector_part)

Write a PrintVectorPart function that takes a vector of integers, searches for the first negative number in it, and prints all the numbers to the left of the found number in reverse order in the standard output. If the vector does not contain negative numbers, print all numbers in reverse order.

```cpp
void PrintVectorPart(const vector<int>& numbers);
```

## [Programming assignment: Split into words](2_split_into_words)

Write a SplitIntoWords function that splits a string into words by spaces.

```cpp.
vector<string> SplitIntoWords(const string& s);
```

It is guaranteed that:

* the string is nonempty
* the string consists only of Latin letters and spaces
* the first and last characters of the string are not spaces
* the string does not contain two spaces in a row.

### Hint

We recommend the following way of solving the problem:

* search for the next space using the find algorithm
* create the next word using the string constructor by two iterators.

## [Programming Practice Task: Removing Repetitions]

Write a template function RemoveDuplicates that takes a vector of elements objects of type T by reference and removes all duplicate elements from it. The order of the remaining elements can be anything.

It is guaranteed that objects of type T can be compared using operators ==, !=, < and >.

```cpp
template <typename T>
void RemoveDuplicates(vector<T>& elements);
```

## [Programming Assignment: Solving permutations](4_solving_permutations)

Given a positive integer N not exceeding 9. Output all permutations of numbers from 1 to N in reverse lexicographical order (see example).

### Example

#### Input

```commandline
3
```

#### Output

```commandline
3 2 1
3 1 2
2 3 1
2 1 3
1 3 2
1 2 3
```

### Hint

The library ```<algorithm>``` contains ready-made functions to solve this problem.
