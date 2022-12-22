#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void NewBus(map<string, vector<string>> &buses_for_stops, map<string, vector<string>> &stops_for_buses, string bus, vector<string> stops)
{
    stops_for_buses[bus] = stops;
    for (auto stop : stops)
    {
        buses_for_stops[stop].push_back(bus);
    }
    //for (size_t i = 1; i < stops.size(); i++)
    //{
    //    buses_for_stops[stops[i]].push_back(bus);
    //}
}
void PrintBusesForStop(map<string, vector<string>> &buses_for_stops, string stop)
{
    if (buses_for_stops.count(stop) == 0)
    {
        cout << "No stop" << endl;
    }
    else
    {
        for (auto s : buses_for_stops[stop])
        {
            cout << s << " ";
        }
        cout << endl;
    }
}

void PrintStopForBuses(map<string, vector<string>> &buses_for_stops, map<string, vector<string>> &stops_for_buses, string bus)
{
    if (stops_for_buses.count(bus) == 0)
    {
        cout << "No bus" << endl;
    }
    else
    {
        for (auto s : stops_for_buses[bus])
        {
            cout << "Stop " << s << ": ";
            if (buses_for_stops[s].size() == 0)
            {
                cout << "No bus" << endl;
            }
            else if ((buses_for_stops[s].size() == 1) & (buses_for_stops[s][0] == bus))
            {
                cout << "no interchange" << endl;
            }
            else
            {
                for (auto b : buses_for_stops[s])
                {
                    if (b != bus)
                    {
                        cout << b << " ";
                    }
                }
                //for (size_t i = 0; i < buses_for_stops[s].size() - 1; i++)
                //{
                //    cout << buses_for_stops[s][i] << " ";
                //}

                cout << endl;
            }
        }
    }
}

void PrintAllBuses(map<string, vector<string>> &stops_for_buses)
{
    if (stops_for_buses.size() == 0)
    {
        cout << "No buses" << endl;
    }
    else
    {
        for (auto el : stops_for_buses)
        {
            cout << "Bus " << el.first << ": ";
            for (auto s : el.second)
            {
                cout << s << " ";
            }
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int nr_of_operations;
    cin >> nr_of_operations;
    string input;
    string command;
    string bus;
    int nr_of_stops;
    string stop;
    map<string, vector<string>> buses_for_stops;
    map<string, vector<string>> stops_for_buses;
    vector<string> stops;
    getline(cin, input);

    for (size_t i = 0; i < nr_of_operations; i++)
    {
        getline(cin, input);
        std::istringstream iss(input);
        iss >> command;

        if (command == "NEW_BUS")
        {
            iss >> bus;
            iss >> nr_of_stops;
            stops.clear();
            for (size_t i = 0; i < nr_of_stops; i++)
            {
                iss >> stop;
                stops.push_back(stop);
            }
            NewBus(buses_for_stops, stops_for_buses, bus, stops);
        }
        if (command == "BUSES_FOR_STOP")
        {
            iss >> stop;
            PrintBusesForStop(buses_for_stops, stop);
        }
        if (command == "STOPS_FOR_BUS")
        {
            iss >> bus;
            PrintStopForBuses(buses_for_stops, stops_for_buses, bus);
        }
        if (command == "ALL_BUSES")
        {
            PrintAllBuses(stops_for_buses);
        }
    }
}
