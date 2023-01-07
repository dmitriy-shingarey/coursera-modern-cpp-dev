# Meditation on algorithms and classes

## [Programming assignment: Sorting integers by modulo](1_sort_array_by_abs)

### Condition

A standard thread is given one string consisting of N + 1 integers.
The first number is the number N itself.
Then another N numbers follow, let's define them as array A.
The numbers are separated from each other by a space.

Sort array A modulo and output it to a standard stream.

### Restrictions

* 0 <= N <= 1000
* -1000000 <= A[i] <= 1000000

## [Programming Assignment: Case Insensitive String Sorting](2_sort_string_array)

### Condition

A standard stream is given one string consisting of a number N followed by N strings S.
The number and lines are separated from each other by a space.

Sort the lines S in lexicographic order in ascending order,
ignoring the case of letters, and output them to the standard output stream.

### Restrictions

* 0 <= N <= 1000
* 1 <= |S| <= 15
* Each line S[i] can consist of the following characters: [0-9,a-z,A-Z]

## [Programming Practice Assignment: Sorted Strings](3_sorted_strings/)

Implement a class that supports a set of strings in sorted order.
The class must contain two public methods:

```cpp
class SortedStrings {
public:
  void AddString(const string& s) {
    // add string s to the set
  }
  vector<string> GetSortedStrings() {
    // get the set of all added strings in sorted order
  }
private:
  // private fields
};
```

## [Programming Assignment: First and Last Names - 1](structures_and_classes/4_names-1)

Implement a class for a person that maintains a history of a person changing their last name and surname.
```cpp
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // add the fact of changing first_name to year
  }
  void ChangeLastName(int year, const string& last_name) {
    // add the fact of last_name change in year
  }
  string GetFullName(int year) {
    // get full name as of the end of year year
  }
private:
  // private fields
};
```

Consider that no more than one change of last name and no more than one change of first name can happen in each year. However, as time passes, more and more facts from a person's past may be revealed, so the years in successive calls to the ChangeLastName and ChangeFirstName methods do not have to increase.

It is guaranteed that all names and surnames are non-empty.

The string returned by the GetFullName method must contain the first and last names of the person as of the end of the given year, separated by one space.

* If no name and surname changes have occurred by the given year, return the string **"Incognito "**.
* If there was a change in the last name but no change in the first name for the year, return **"last_name with unknown first name "**.
* If there has been a name change for the year, but there has not been a last name change, return **"first_name with unknown last name "**.

## [Programming Task: First and Last Names - 2](structures_and_classes/5_names-2)

Complete the class from the previous task "First and Last Names - 1" with the GetFullNameWithHistory method:

```cpp
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // add the fact of changing the name to first_name in year
  }
  void ChangeLastName(int year, const string& last_name) {
    // add the fact of last_name change in year
  }
  string GetFullName(int year) {
    // get full name as of the end of year year
  }
  string GetFullNameWithHistory(int year) {
    // get all names and surnames as of the end of the year year
  }
private:
  // private fields
};
```

Unlike the GetFullName,
The GetFullNameWithHistory method should return not only the last name at the end of a given year,
but also all previous names in reverse chronological order.
If the current facts show that a person has changed their last name or first name to the same thing twice in a row,
the second change should be ignored when building the history.

## [Programming Practice Assignment: String](6_reversable_string)

Implement a ReversibleString class that stores a string and supports Reverse methods for reversing the string and ToString methods for retrieving the string.

## [Programming Task: Names and Surnames - 3](structures_and_classes/7_names-3)

Complete the Person class from the "Names and Surnames - 2" problem with a constructor,
that allows you to specify a person's first and last name at birth, as well as the year of birth itself.
The class should not have a default constructor.

When receiving a year that is less than the year of birth as input:

* the GetFullName and GetFullNameWithHistory methods should give "No person";
* ChangeFirstName and ChangeLastName methods should ignore the request.
In addition, all methods that are essentially them must be declared as constants.

