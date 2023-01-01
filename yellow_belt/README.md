# About  

This course is a continuation of the course [C++ Development Essentials: white belt](https://github.com/dmitriy-shingarey/coursera-modern-cpp-dev/tree/white_belt/white_belt). It continues to introduce you to the capabilities of the C++ language. The course covers:

- integer types in C++
- pairs and tuples
- function templates
- inheritance and polymorphism
- iterators and standard algorithms
- code distribution into several files

In addition, the course deals with the use of unit tests for debugging programs and code reliability, and demonstrates how to develop your own unit test framework using only the knowledge of the White and Yellow Belts.

Just like the White Belt, you'll also get a final project at the end of the course. In the White Belt, you had to implement a simple data warehouse with the ability to add, delete and search. In the Yellow Belt, this repository will need to be improved by adding support for more complex queries.

Moved from [Gitlab-repo1](https://gitlab.com/Shingarey/coursera_yandex_cpp) and [Gitlab-repo2](https://gitlab.com/Shingarey/yandex_cpp).

## Course syllabus

### [1. Integer Types, Tuples, Template Functions](solutions/week1)

This week's material introduces you to C++ features not covered in the C++ White Belt course. First we look at the different integer types in C++, explain how they differ, and give practical advice on how to use them. Then we look at pairs and tuples as a way to simplify the return of multiple values from functions and create comparison operators for your classes. Finally, we talk about function templates. "When will templates be available?" was one of the most frequent questions we were asked by White Belt listeners. This topic is vast and complex, so we start small by talking about feature templates: what they are, what they're for, and how to create them.

### [2. Testing and debugging](solutions/week2)

This week is devoted to using unit tests for testing and debugging programs. Using an example, we will demonstrate how unit tests help you find and fix bugs and what you need to do to cover your code with unit tests. We will then use the knowledge we have gathered so far to develop our own framework for creating unit tests, which you will be able to use in your own programs.

### [3. Distributing code by file](solutions/week3)

All the code we have written in our course before has always been in one file. Naturally, real big projects are not written in one file. In this week's content, we'll look at how to distribute C++ program code into multiple files. We will explain what header files and implementation files are, how the #include directive works and how to build a multi-file project. We will also talk about problems that arise in large projects and how to solve them.

### [4. Iterators, Algorithms and Containers](solutions/week4)

In the White Belt in C++ course we got acquainted with some standard algorithms: count, count_if and sort. Of course, the C++ library is much richer and contains much more standard algorithms that make your code shorter, clearer and more reliable. To master them, you must first learn what iterators are. That's where we'll start in week 4. Then we'll take a look at the standard algorithms that use iterators. Finally, we will introduce you to the new standard containers: dec and queue.

### [5. Inheritance and polymorphism](solutions/week5)

Object-oriented programming stands on three pillars: encapsulation, inheritance and polymorphism. We learned about the means by which encapsulation is achieved in C++ in the C++ White Belt. This week we'll tell you about the two remaining "whales": inheritance and polymorphism. We'll not only show how exactly in C++ to inherit one class from another and create a set of polymorphic objects, but also put this knowledge into practice by creating a calculator program that supports working with variables.

### [6. Course Project](solutions/week5_final_project)

It's time to consolidate all the knowledge gained in the course by applying it to the final project. This week's task is a development of the final project in the White Belt in C++ course. You'll also need to develop a database that stores a set of events and supports various operations on it.
