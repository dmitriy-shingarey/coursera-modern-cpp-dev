#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(string birth_fname, string birth_lname, int birthyear)
    {
        year_to_firstname[birthyear] = birth_fname;
        year_to_lastname[birthyear] = birth_lname;
        year_of_birth = birthyear;
        birth_firstname = birth_fname;
        birth_lastname = birth_lname;
    }

    string FindName(const map<int, string> &year_to_name, int year) const
    {
        string name = "";
        for (auto el : year_to_name)
        {
            if (el.first <= year)
            {
                name = year_to_name.at(el.first);
            }
        }
        return name;
    }

    string FindNames(const map<int, string> &year_to_name, int year) const
    {
        vector<string> names{};
        string names_to_return = "";
        string current_name = "";
        string last;
        for (auto el : year_to_name)
        {
            if (el.first <= year)
            {
                if (find(names.begin(), names.end(), el.second) == names.end())
                {
                    names.push_back(el.second);
                    last = el.second;
                }
                else
                {
                    if (el.second != last)
                    {
                        current_name = el.second;
                    }
                }
            }
        }
        if (!current_name.empty())
        {
            names.push_back(current_name);
        }

        reverse(names.begin(), names.end());
        for (size_t i = 0; i < names.size(); i++)
        {
            if (i == 0)
            {

                names_to_return += (names[i]);
            }
            else
            {
                if (i == 1)
                {
                    names_to_return += (" (" + names[i]);
                }
                else if (i < names.size())
                {
                    names_to_return += (", " + names[i]);
                }
                if (i == (names.size() - 1))
                {
                    names_to_return += ")";
                }
            }
        }

        return names_to_return;
    }
    void ChangeFirstName(int year, const string &first_name)
    {
        if (year >= year_of_birth)
        {
            year_to_firstname[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string &last_name)
    {
        if (year >= year_of_birth)
        {
            year_to_lastname[year] = last_name;
        }
    }
    string GetFullName(int year) const
    {
        if (year < year_of_birth)
        {
            return "No person";
        }
        else
        {
            string firstname = FindName(year_to_firstname, year);

            string lastname = FindName(year_to_lastname, year);

            if (firstname == "" & lastname == "")
            {
                return "Incognito";
            }
            if (firstname != "" & lastname == "")
            {
                return {firstname + " with unknown last name"};
            }
            if (firstname == "" & lastname != "")
            {
                return {lastname + " with unknown first name"};
            }
            if ((firstname != "") && (lastname != ""))
            {
                return {firstname + " " + lastname};
            }
        }
    }

    string GetFullNameWithHistory(int year) const
    {
        if (year < year_of_birth)
        {
            return "No person";
        }
        else
        {
            string firstnames = FindNames(year_to_firstname, year);

            string lastnames = FindNames(year_to_lastname, year);

            if (firstnames == "" & lastnames == "")
            {
                return "Incognito";
            }
            if (firstnames != "" & lastnames == "")
            {
                return {firstnames + " with unknown last name"};
            }
            if (firstnames == "" & lastnames != "")
            {
                return {lastnames + " with unknown first name"};
            }
            if ((firstnames != "") && (lastnames != ""))
            {
                return {firstnames + " " + lastnames};
            }
        }
    }

private:
    map<int, string> year_to_firstname;
    map<int, string> year_to_lastname;
    int year_of_birth;
    string birth_lastname;
    string birth_firstname;
};

int main()
{
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960})
    {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1960, "Appolinaria");
    person.ChangeLastName(1960, "Ivanova");
    for (int year : {1965, 1967})
    {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
