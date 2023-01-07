# I/O, exceptions, and operator overloading

## [Programming Assignment: LectureTitle Structure](1_structures)

The LectureTitle structure is given:

```cpp
struct LectureTitle {
  string specialization;
  string course;
  string week;
};

```

Rewrite the constructor and structures Specialization, Course, Week so that the LectureTitle object can be created with the code

```cpp
LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);
```

but we couldn't with the following code snippets:

```cpp
LectureTitle title("C++", "white belt", "4th");

LectureTitle title(string("C++"), string("white belt"), string("4th"));

LectureTitle title = {"C++", "White belt", "4th"};

LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

LectureTitle title(
    Course("White belt"),
    Specialization("C++"),
    Week("4th")
);

LectureTitle title(
    Specialization("C++"),
    Week("4th"),
    Course("White belt")
);
```

## [Programming Practice Assignment: Reversible Function](2_inverted_function.cpp)

Implement the Function class that was explained in the lecture,
that allows you to create, calculate, and invert a function consisting of the following elementary operations:

* add a real number x;
* Subtract a real number x.
At the same time, you must declare as constant all methods, which are essentially such.

## [Class Rational and OPerations Overload](operation_overload)
