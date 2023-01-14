# Inheritance and polymorphism

## [Programming Assignment: Inheritance](1_inheritance)

Given following code:

```cpp
#include <iostream>

using namespace std;

class Animal {
public:
    // your code

    const string Name;
};


class Dog {
public:
    // your code

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
```

Define the class bodies, consdering the following requirements:

1. The ```Dog``` class should be a derived class of the ```Animal``` class.
2. The constructor of the ```Dog``` class should take a string parameter and initialize the ```Name``` field in the```Animal``` class with it.

## [Programming exercise: Sending notifications](2_sending_notifications)

In this task you need to develop SmsNotifier and EmailNotifier classes that send SMS and e-mail notifications, respectively, as well as an abstract base class for them.

You are given the SendSms and SendEmail functions that simulate sending SMS and e-mail.

```cpp
void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);
```

Create:

1. an abstract base class ```INotifier```, which will have one purely virtual method```void Notify(const string& message)```.

2. ```SmsNotifier``` class, which:
    * is a derived class of the ```INotifier``` class;
    * in the constructor takes a single parameter of the string type - phone number;
    * Overrides the ```Notify``` method and calls the ```SendSms``` function from it.
3. The ```EmailNotifier``` class, which;
    * is a derived class of the ```INotifier``` class;
    * takes one parameter of type string - email address - in the constructor;
    * Overrides the ```Notify``` method and calls the ```SendEmail``` function from it.

## [Programming task: Set of figures](3_set_of_figures)

You are given the ```main``` function, which reads from standard input the commands for working with a set of geometric shapes:

```cpp
int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
```

As you can see from the code, there are two kinds of commands:

**ADD** - add a shape to the set;
**PRINT** - print name, perimeter and area for each figure in the set.

The program supports three types of shapes: rectangle, triangle and circle. Their addition is described as follows:

1. **ADD RECT** ***width height*** - add a rectangle with dimensions ***width*** and ***height*** (for example, **ADD RECT 2 3**).
2. **ADD TRIANGLE** ***a b c*** - add a triangle with sides ***a, b*** and ***c*** (for example, **ADD TRIANGLE 3 4 5**).
3. **ADD CIRCLE** ***r*** - add a circle of radius ***r*** (for example, **ADD CIRCLE 5**).

**Without changing the main** function, implement the missing functions and classes:

* basic class ```Figure``` with purely virtual methods ```Name```, ```Perimeter``` and ```Area```;

* classes ```Triangle```, ```Rect``` and ```Circle```, which are derivatives of the ```Figure``` class and override its virtual methods;
* the ```CreateFigure``` function which, depending on the contents of the input stream, creates ```shared_ptr<Rect>```,```shared_ptr<Triangle>``` or ```shared_ptr<Circle>```.

It is guaranteed that all **ADD** commands are correct; the sizes of all figures are natural numbers not greater than 1000. Use 3.14 as the value of π.

How your code will be tested

The automatic checking system will replace the main function in your program with the one given in the problem statement, compile the resulting file and run it on a set of tests. It will also separately check that the CreateFigure function returns an object created with ```make_shared<Rect>``` if the input stream specifies a rectangle, an object created with ```make_shared<Circle>``` if the input stream specifies a circle, etc.

## [Programming task: Code refactoring](4_code_refactoring)

In this assignment, you will modify the code so that it conforms to the principles outlined in the course.

Imagine you inherited this code from a colleague and now you have to maintain and improve it.
The first thing you decide to do is to refactor it.

The ultimate goals of refactoring are:

* simplify further maintenance of the code;
* reduce the complexity of the code;
* make it easier to add new abstractions to the program.

The task will be evaluated according to the following criteria:

* code execution efficiency;
* the code redundancy;
* the efficiency of using the code refactoring techniques, demonstrated in the lectures.

Besides, the code you send in must be compilable.
