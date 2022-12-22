/* create class with history of persons name changes and default constructor*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

class Person
{

private:
  struct PersonsData
  {
    string first_name;
    string last_name;
  };
  map<int, PersonsData> year_to_name;

public:
  Person(const string &new_first_name, const string &new_last_name, const int &birth_date)
  {
    year_to_name[birth_date] = {new_first_name, new_last_name};
  }

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
      return "No person";
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
};

int main()
{
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960})
  {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967})
  {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
