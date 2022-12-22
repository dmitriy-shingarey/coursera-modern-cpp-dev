/* create class with history of persons name changes*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person
{
public:
  void ChangeFirstName(int year, const string &first_name)
  {
    year_to_name[year].first_name = first_name;
  }
  void ChangeLastName(int year, const string &last_name)
  {
    year_to_name[year].last_name = last_name;
  }
  string GetFullName(int year)
  {
    string f_name, l_name;

    // iterate over keys and assign last name and first name until the given year
    for (const auto &y : year_to_name)
    {
      if (y.first <= year)
      {
        if (y.second.first_name.size() > 0)
        {
          f_name = y.second.first_name;
        }
        if (y.second.last_name.size() > 0)
        {
          l_name = y.second.last_name;
        }
      }
    }
    if ((l_name.size() == 0) && (f_name.size() == 0))
    {
      return "Incognito";
    }
    else if ((l_name.size() > 0) && (f_name.size() == 0))
    {
      return l_name + " with unknown first name";
    }
    else if ((l_name.size() == 0) && (f_name.size() > 0))
    {
      return f_name + " with unknown last name";
    }
    else
    {
      return ((f_name) + " " + (l_name));
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

int main()
{
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990})
  {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970})
  {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970})
  {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}