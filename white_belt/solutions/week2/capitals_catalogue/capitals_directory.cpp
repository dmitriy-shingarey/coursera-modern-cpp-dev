/* realize catalogue of countries and capitals*/

#include <iostream>
#include <map>
#include <numeric>
#include <string>

using namespace std;

int main() {
    int number_of_operations;
    map<string, string> country_and_capital;
    string operation;
    cout << "Enter number of pairs: ";
    cin >> number_of_operations;
    for (size_t i = 0; i < number_of_operations; i++) {
        cin >> operation;
        if (operation == "CHANGE_CAPITAL")
        {
            string country, capital;
            cin >> country >> capital;
            if (country_and_capital.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << capital << endl;
                country_and_capital[country] = capital;
            }
            else {
                if (country_and_capital[country]==capital){
                    cout << "Country country hasn't changed its capital." << endl;
                }
                else {
                    cout << "Country " << country << " has changed its capital from " << country_and_capital[country] << " to " << capital << endl;
                    country_and_capital[country] = capital;
                }
            }
        }
        if (operation=="RENAME")
        {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || country_and_capital.count(old_country_name) == 0 || country_and_capital.count(new_country_name) == 1)
            {
                cout << "Incorrect rename, skip" << endl;
            }
            else
            {
                cout << "Country " << old_country_name << " with capital " << country_and_capital[old_country_name] << " has been renamed to " << new_country_name << endl;
                country_and_capital[new_country_name]=country_and_capital[old_country_name];
                country_and_capital.erase(old_country_name);
            }    
        }
        if (operation == "ABOUT")
        {
            string country;
            cin >> country;
            if (country_and_capital.count(country) == 0)
            {
                cout << "Country " << country << " doesn't exist";
            }
            else
            {
                cout << "Country " << country << " has capital " << country_and_capital[country] << endl;
            }
        }
        if (operation == "DUMP")
        {
            if (country_and_capital.empty()) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (auto item : country_and_capital)
                {
                    cout << item.first << "/" << item.second << endl;
                }
                
            }
        }
        
        
    }
}