/* create class with history of persons name changes*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

class Person
{
public:
  string getLabeledPointsString(const string delimiter, const vector<string> &x)
  {
    stringstream s;
    copy(x.begin(), x.end(), ostream_iterator<string>(s, delimiter.c_str()));
    return s.str();
  }
  void ChangeFirstName(int year, const string &first_name)
  {
    year_to_name[year].first_name = first_name;
  }
  void ChangeLastName(int year, const string &last_name)
  {
    year_to_name[year].last_name = last_name;
  }
  string GetFullNameWithHistory(int year)
  {
    string f_name, l_name;
    vector<string> last_name_history;
    vector<string> first_name_history;

    // iterate over keys and assign last name and first name until the given year
    for (const auto &y : year_to_name)
    {
      if (y.first <= year)
      {
        if (y.second.first_name.size() > 0)
        {
          f_name = y.second.first_name;
          first_name_history.push_back(f_name);
        }
        if (y.second.last_name.size() > 0)
        {
          l_name = y.second.last_name;
          last_name_history.push_back(l_name);
          // last_name_history.insert(last_name_history.begin(),l_name);
        }
      }
    }
    string lk, fk;
    if (last_name_history.size() > 0)
    {
      last_name_history.pop_back();
      reverse(last_name_history.begin(), last_name_history.end());
    }
    if (first_name_history.size() > 0)
    {
      first_name_history.pop_back();
      reverse(first_name_history.begin(), first_name_history.end());
    }

    if (last_name_history.size() > 0)
    {
      lk = getLabeledPointsString(", ", last_name_history);
      lk = lk.substr(0, lk.size() - 2);
      lk = " ( " + lk + " ) ";
    }
    if (first_name_history.size() > 0)
    {
      fk = getLabeledPointsString(", ", first_name_history);
      fk = fk.substr(0, fk.size() - 2);
      fk = " ( " + fk + " ) ";
    }

    if ((l_name.size() == 0) && (f_name.size() == 0))
    {
      return "Incognito";
    }
    else if ((l_name.size() > 0) && (f_name.size() == 0))
    {
      return l_name + lk + " with unknown first name";
    }
    else if ((l_name.size() == 0) && (f_name.size() > 0))
    {
      return f_name + " with unknown last name";
    }
    else
    {
      return ((f_name) + fk + " " + (l_name) + lk);
    }
  }

private:
  struct PersonsData
  {
    string first_name;
    string last_name;
  };
  map<int, PersonsData> year_to_name;
};

// int main() {
//   Person person;
//
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//
//   person.ChangeFirstName(1990, "Polina");
//   person.ChangeLastName(1990, "Volkova-Sergeeva");
//   cout << person.GetFullNameWithHistory(1990) << endl;
//
//   person.ChangeFirstName(1966, "Pauline");
//   cout << person.GetFullNameWithHistory(1966) << endl;
//
//   person.ChangeLastName(1960, "Sergeeva");
//   for (int year : {1960, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
//
//   person.ChangeLastName(1961, "Ivanova");
//   cout << person.GetFullNameWithHistory(1967) << endl;
//
//   return 0;
// }
//
int main()
{
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;

  return 0;
}
