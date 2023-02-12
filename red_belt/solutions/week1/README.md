# Macros and class templates

## [Programming Assignment: Maximum Element by Predicate](0_max_element_by_predicate)

### Preface

If you're not sure if you should take our earlier courses first, or if you have enough knowledge to start with the Red Belt, try this problem. If you don't understand its condition or can't solve it quickly, you should probably take Yellow Belt first

### Problem condition

Implement the template function

```cpp
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
```

which returns an iterator on the maximal element in the range ```[first, last]``` for which the predicate```pred```returns true. If the range contains several matching elements with a maximum value, the result is the first occurrence of such an element. If the range does not contain any matching elements, the function should return```last```.

It is guaranteed that:

* ```pred``` takes an argument of the type that the range elements have
* ```operators ++, ==, !=, *``` (dereferencing) are defined for ```ForwardIterator```
* ```operator <``` ("less than") is defined for the type the iterator points to

## [Programming Assignment: Macro LOG](1_macro_log)

You are given the class ```Logger``` and the macro ```LOG```:

```cpp
class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file = value; }

  void Log(const string& message);

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

# define LOG(logger, message) ...
```

The parameters of the macro ```LOG``` are an object of the class ```Logger``` and a string message to be passed to the ```Log``` method. Depending on the settings of the object of class ```Logger```, the message to be logged should be preceded by a file name or a line number. See the unit tests in the solution preset for a more detailed description of the behavior.

Implement the macro ```LOG``` so that it adds file name and line number to the logged message depending on the logger object settings. Submit a cpp file that contains:

* macro ```LOG``` implementation
* A declaration of the ```Logger``` class, allowing you to add additional fields and methods to it if necessary
* Definitions for all of the methods of the ```Logger``` class

### Note

If you are using Visual Studio, you may not be able to run unit tests from the workpiece, because in that environment the ``__FILE__`` macro is expanded to an absolute path to the file. Keep this in mind when debugging your solution.

## [Programming Assignment: Comparator Generator](2_comparator_generator)

Let's imagine that you are developing an innovative flight search service AviaScanner. In your service a ticket is represented as a structure

```cpp
struct Date {
  int year, month, day;
};

struct Time {
  int hours, minutes;
};

structlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  uint64_t price;
};
```

You are currently working on a function to sort the search results. The user enters his query and gets a list of matching tickets. From there he can set the sorting parameters for that list. For example, first by price, then by departure time, and finally by arrival airport.

To implement the sorting as in the example, you can use the numeric sorting algorithm:

```cpp
void SortTickets(vector<AirlineTicket>& tixs) {
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.to < rhs.to;
  });
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.departure_time < rhs.departure_time;
  });
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.price < rhs.price;
  });
}
```

As you can see, there is some code duplication in the example above - we had to write three lambda functions that differ only in the field by which the sorting is performed. You can get rid of this duplication by writing the macro ```SORT_BY``` and applying it as follows:

```cpp
void SortTickets(vector<AirlineTicket>& tixs) {
  stable_sort(begin(tixs), end(tixs), SORT_BY(to));
  stable_sort(begin(tixs), end(tixs), SORT_BY(departure_time));
  stable_sort(begin(tixs), end(tixs), SORT_BY(price));
}
```

Write the ```SORT_BY``` macro which takes as its parameter the field name of the ```AirlineTicket``` structure. A call of ```sort(begin(tixs), end(tixs), SORT_BY(some_field))``` should sort the ```tixs``` vector by some_field.

You are given the file ```airline_ticket.h```, which contains the declarations of the structures ```Time```, ```Date``` and ```AirlineTicket```, as well as a solution template in the form of the cpp-file ```sort_by.cpp```. Send a cpp file that

* includes the ```airline_ticket.h``` header file.
* contains the ```SORT_BY``` macro
* contains definitions of operators needed to use ```Date``` and ```Time``` classes in the sorting algorithm and ```ASSERT_EQUAL``` macro (you can choose any output format)

## [Programming task: macro UPDATE_FIELD](3_macro_update_field)

Let's continue working on the AviaScanner airline ticket search service. Our service stores a database of tickets as a ```vector<AirlineTicket>```, where ```AirlineTicket``` is the same structure as in the previous problem. Periodically our service traverses airline sites, collects the latest information about the available tickets and updates the entries in its database. This is done using the ```void UpdateTicket(AirlineTicket& ticket, const map<string, string>& updates)``` function. The parameter ```updates``` contains the pairs (field name; new value). At the same time it contains only those fields that changed. An example of the function UpdateTicket:

```cpp
void UpdateTicketExample() {
  AirlineTicket t;
  t.price = 5000;
  t.from = "DME";
  t.to = "AER";

  const map<string, string> updates = {
    {"price", "3500"},
    {"from", "VKO"}
  };
  UpdateTicket(t, updates);
  ASSERT_EQUAL(t.from, "VKO");
  ASSERT_EQUAL(t.to, "AER");
  ASSERT_EQUAL(t.price, 3500);
}
```

The ```UpdateTicket``` function could be implemented like this:

```cpp
void UpdateTicket(AirlineTicket& ticket, const map<string, string>& updates) {
  map<string, string>::const_iterator it;

  it = updates.find("to");
  if (it != updates.end()) {
    ticket.to = it->second;
  }

  it = updates.find("from");
  if (it != updates.end()) {
    ticket.from = it->second;
  }

  it = updates.find("price");
  if (it != updates.end()) {
    istringstream is(it->second);
    is >> ticket.price;
  }
  ...
}
```

There is a code duplication here - code blocks inside ```UpdateTicket``` function differ only by field name (of course, the first two blocks are not the same as the third one, but it's easy to reduce them to it). In this case, the name of the field is used not only to refer to the ```AirlineTicket``` structure, but also as a string literal. So you can write a macro that will greatly simplify the ```UpdateTicket``` function:

```cpp
# define UPDATE_FIELD(ticket, field, values) ...

void UpdateTicket(AirlineTicket& ticket, const map<string, string>& updates) {
  UPDATE_FIELD(ticket, to, updates);
  UPDATE_FIELD(ticket, from, updates);
  UPDATE_FIELD(ticket, price, updates);
  UPDATE_FIELD(ticket, airline, updates);
  ...
}
```

Write ```UPDATE_FIELD``` macro. You are given the file ```airline_ticket.h```, which contains the declarations of the structures ```Time```, ```Date``` and ```AirlineTicket```, as well as a solution template as a cpp-file ```update_field.cpp```. Send a cpp-file that

* includes in the ```airline_ticket.h``` header file
* contains the ```UPDATE_FIELD``` macro
* contains definitions of operators needed to read ```Date``` and ```Time``` classes from ```istream``` stream and use them in ```ASSERT_EQUAL``` macro (see ```update_field.cpp``` in unit-tests for input format)

## [Programming task: Table](4_table)

You need to write a template class ```Table``` for a spreadsheet. For simplicity, we will assume that all table cells have the same data type ```T```. The table should be able to change its size on user's demand. Newly created cells must be filled with default values of type ```T```.

The requirements for the class are:

1. The class must be named ```Table```.
2. The class must have a template parameter ```T``` - the type of element in the cell.
3. The class must have a ```constructor``` that receives two numbers of ```size_t``` type - the number of rows and columns, respectively.
4. The class must have constant and non-constant versions of ```[]``` operator which returns something to which you can apply the ```[]``` operator again. That is, constructs of the form ```cout << table[i][j];``` and ```table[i][j] = value;``` must work. There is no need to check indexes correctness.
5. The class must have ```Resize``` function that receives two parameters of ```size_t``` type and changes the table size. The old data that fit into the new size should be preserved.
6. The class must have a constant ```Size``` method that returns ```pair<size_t, size_t>``` the size of the table (in the same order in which these arguments were passed to the constructor).

## [Programming task: Deque based on 2 vectors](5_deque_on_vectors)

### Problem Condition

Write a ```Deque``` template class containing the following set of methods:

* default constructor;
* constant method ```Empty```, returning ```true``` if deque does not contain any element;
* constant method ```Size```, which returns the number of elements in the deck;
* ```T& operator[](size_t index)``` and ```const T& operator[](size_t index) const;```

* ```const``` and ```non-const``` method ```At(size_t index)```, which generates the standard ```out_of_range``` exception if the index is greater than or equal to the number of elements in the deck;

* ```const``` and ```non-const``` versions of the ```Front``` and ```Back``` methods that return references to the first and last element of the deque, respectively;

* ```PushFront``` and ```PushBack``` methods.

The ```non-const``` versions of the methods must allow the corresponding deque element to be modified.

For implementation, create two vectors inside the ```Deque``` class: insert into one in the ```PushFront``` method, and in the other - in the ```PushBack``` method.

### Comment

The header file that you send for review must not include the ```<list>, <deque>, <set>, <map>``` files. If you have one of these files included, you will get a compilation error.

## [Programming assignment: Paginator template](6_pagination)

### Condition

In the lecture, we developed a ```Head``` function that allows us to loop through the beginning of a container. In this assignment, we take it one step further and develop a ```Paginator``` pattern that breaks up the contents of a container into multiple pages. A classic example where this might come in handy in practice is in the distribution of a list of mobile apps across phone screens. Let's say we have a vector of all apps on our phone and we can place 20 app icons on one screen. Then we can distribute the applications on the screens with this code:

```cpp
vector<vector<Application>> DistributeAmongScreens(const vector<Application>& apps) {
  vector<vector<Application>> result;
  for (const auto& page : Paginate(apps, 20)) {
    result.push_back({page.begin(), page.end()})
  }
  // result[0] - all the apps which get to the first screen,
  // result[1] - all the applications on the second screen, etc.
  return result;
}
```

Notice our code is short and elegant. We didn't have to write any special code to handle the last screen, which might contain fewer than 20 applications.

So, develop a template class ```Paginator``` with the following properties:

* it has one template parameter - the iterator type
* the constructor of the ```Paginator<Iterator>``` class takes three parameters:
  
  1. Iterator ```begin```
  2. Iterator ```end``` - the pair of begin and end iterators defines a half-interval [begin; end] which we will cut into pages
  3. ```size_t page_size``` - size of one page

* one can iterate with a range-based for loop over objects of the class ```Paginator<Iterator>```
* class ```Paginator<Iterator>``` has a method ```size_t size() const```, which returns the number of pages into which the passed container is divided
* The pages themselves must also iterate through a range-based for loop, and have a ```size_t size() const``` method which returns the number of objects in the page
* for detailed examples of use, see the unit tests in the solution template
  
Also develop a ```Paginate``` function template that takes a reference to a container and a page size, and returns an object of class ```Paginator<It>```:

```cpp
template <typename C> ??? Paginate(C& c, size_t page_size)
```