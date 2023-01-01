#include <vector>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

// Pre-define templates
template<typename T> vector<T> Sqr(const vector<T> &);
template<typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second> & );
template<typename First, typename Second, typename Third> map<First, pair<Second, Third>> Sqr(const map<First, pair<Second, Third>> &);

// Define Templates
template<typename T> vector<T> 
Sqr(const vector<T> & vec){
    vector<T> sqr_vec; 
    for (T x : vec){
        sqr_vec.push_back(x*x);
    }
    return sqr_vec;
}

template<typename First, typename Second> pair<First, Second> 
Sqr(const pair<First, Second> & p) { 
    return make_pair(p.first*p.first, p.second*p.second);
 }

template<typename First, typename Second, typename Third> map<First, pair<Second, Third>> 
Sqr(const map<First, pair<Second, Third>> & m) {
    map<First, pair<Second, Third>> new_m;
    for (auto el : m){
        new_m[el.first]=Sqr(el.second); //make_pair(el.second.first*el.second.first,el.second.second*el.second.second);
    }
    return new_m;
}

int main () {
// Пример вызова функции
vector<int> v = {1, 2, 3};
cout << "vector:";
for (int x : Sqr(v)) {
  cout << ' ' << x;
}
cout << endl;

map<int, pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
};
cout << "map of pairs:" << endl;
for (const auto& x : Sqr(map_of_pairs)) {
  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
}
}