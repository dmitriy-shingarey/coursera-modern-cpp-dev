# Principles of code optimization, algorithm complexity and efficient use of I/O

## [Programming Assignment: Sorting Students by Rating](1_sorting_by_rating)

In this task, you need to optimize the code used to sort students by rating. Each student's data is in the ```Student``` structure declared in ```student.h```. The student's rating is written in the rating field:

```cpp
struct Student {
  string first_name;
  string last_name;
  map<string, double> marks;
  double rating;

  bool operator < (const Student& other) const {
    return GetName() < other.GetName();
  }

  bool Less(const Student& other) const {
    return rating > other.rating;
  }

  string GetName() const {
    return first_name + " " + last_name;
  }
};

```

A comparison function is used to sort students by rating, returning ```true``` if student first's rating is higher than student second's rating.

```cpp
bool Compare(Student first, Student second) {
  return first.Less(second);
}
```

It has been found that this function is the bottleneck of the sorting process, and it is this bottleneck that needs to be optimized.

Send a file with an optimized version of the Compare function to test it. If your implementation is not efficient enough, the solution will not meet the time constraint.



