#include <string>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    void ChangeFirstName(int year, const string &first_name)
    {
        year_to_firstname[year] = first_name;
        // if (last_year_for_firstname == 0)
        //{
        // last_year_for_firstname = year;
        // }
        // if (year < last_year_for_firstname)
        //{
        // last_year_for_firstname = year;
        // }
        // if (year_to_lastname[year].empty())
        //{
        // if (last_year_for_lastname < year)
        //{
        // year_to_lastname[year] = year_to_lastname[last_year_for_lastname];
        // }
        // }
    }
    void ChangeLastName(int year, const string &last_name)
    {
        year_to_lastname[year] = last_name;
        // if (last_year_for_lastname == 0)
        //{
        //     last_year_for_lastname = year;
        // }
        // if (year < last_year_for_lastname)
        //{
        //     last_year_for_lastname = year;
        // }
        // if (year_to_firstname[year].empty())
        //{
        //     if (last_year_for_firstname < year)
        //     {
        //         year_to_firstname[year] = year_to_firstname[last_year_for_firstname];
        //     }
        // }
    }
    string GetFullName(int year)
    {
        string firstname = "";
        string lastname = "";
        for (auto el : year_to_firstname)
        {
            if (el.first <= year)
            {
                firstname = year_to_firstname[el.first];
            }
        }
        for (auto el : year_to_lastname)
        {
            if (el.first <= year)
            {
                lastname = year_to_lastname[el.first];
            }
        }

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
    //std::cout << person.GetFullNameWithHistory(5) << '\n';

}
