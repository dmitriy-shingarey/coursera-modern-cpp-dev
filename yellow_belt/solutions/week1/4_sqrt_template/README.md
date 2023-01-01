# Programming Assignment: Everything is squared

Implement a template function _Sqr_ that works not only for numbers, but also for containers. The function should return a copy of the original container by modifying it as follows:

* for _vector_ the elements must be squared;
* for _map_ only values need to be squared, not keys;
* for _pair_ each element of the pair must be squared.

```objectivec
// Example function call
vector<int> v = {1, 2, 3};
cout << "vector:";
for (int x : Sqr(v)) {
  cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
cout << "map of pairs:" << endl;
for (const auto& x : Sqr(map_of_pairs)) {
  cout << x.first << ' << x.second.first << ' << x.second.second << endl;
}

```

The code above should output

```commandline
vector: 1 4 9
map of pairs:
4 4 4
7 16 9
```

The function must work correctly not only for containers consisting of numbers, but also for composite objects, such as vectors of dictionaries of pairs of numbers.

To pass the solution successfully, it is necessary to make a preliminary declaration of template functions before all template functions.

An example of a preliminary declaration of a template function

```objectivec
// Preliminary declaration of template functions
template<typename T> T FuncA(T x);
template<typename T> void FuncB(T x);

//Declare the template functions
template<typename T>
T FuncA(T x) { /_..._/ }

template <typename T>
void FuncB(T x) { /_..._/ }

```

You will learn why this is needed and how it works from our courses below.
