#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    string FindName(map<int, string> &year_to_name, int year)
    {
        string name = "";
        for (auto el : year_to_name)
        {
            if (el.first <= year)
            {
                name = year_to_name[el.first];
            }
        }
        return name;
    }

    string FindNames(map<int, string> &year_to_name, int year)
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
        year_to_firstname[year] = first_name;
    }
    void ChangeLastName(int year, const string &last_name)
    {
        year_to_lastname[year] = last_name;
    }
    string GetFullName(int year)
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

    string GetFullNameWithHistory(int year)
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

private:
    map<int, string> year_to_firstname;
    map<int, string> year_to_lastname;
};

int main()
{
    Person person;
    person.ChangeFirstName(1, "first");
    person.ChangeFirstName(2, "first2");
    person.ChangeFirstName(3, "first3");
    person.ChangeFirstName(4, "first");
    person.ChangeFirstName(5, "first5");
    std::cout << person.GetFullName(5) << '\n';
    // std::cout << person.GetFullNameWithHistory(5) << '\n';
}
