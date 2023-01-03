# Programming Assignment: Split Into Words

Write a function *SplitIntoWords* that splits a string into words by spaces.

```objectivec
vector<string> SplitIntoWords(const string& s);

```

It is guaranteed that:

* the string is nonempty;
* The string consists only of Latin letters and spaces;
* the first and last characters of the string are not spaces;
* The string does not contain two spaces in a row.

## Hint

We recommend the following way of solving the problem:

* search for the next space using the find algorithm;
* create the next word using the string constructor by two iterators.

## Example code

```objectivec
int main() {
  string s = "Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
```

## Output

```commandline
 C/Cpp/Java/Python
```
