# programming assignment: Part of a vector

Write a function *PrintVectorPart* that takes a vector of integers *numbers*, searches for the first negative number in it, and outputs all numbers to the left of the found number in reverse order to the standard output. If the vector does not contain negative numbers, print all numbers in reverse order.

```objectivec
void PrintVectorPart(const vector<int>& numbers);

```

## Example code

```objectivec
int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  PrintVectorPart({6, 1, 8, -5, 4}); // nothing will be printed
  PrintVectorPart({6, 1, 8, 5, 4});
  return 0;
}
```

## Output

```commandline
8 1 6

4 5 8 1 6
```
