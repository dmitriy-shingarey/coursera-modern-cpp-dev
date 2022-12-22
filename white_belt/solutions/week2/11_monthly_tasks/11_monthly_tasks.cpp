#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool TaskExist(string &task, const vector<string> &day_v)
{
    if (day_v.size() != 0)
    {
        for (auto el : day_v)
        {
            if (el == task)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}

void Add(int day, string &task, vector<vector<string>> &current_month)
{
    if (!TaskExist(task, current_month[day - 1]))
    {
        current_month[day - 1].push_back(task);
    }
}

void Dump(int day, const vector<vector<string>> &current_month)
{
    cout << current_month[day - 1].size() << " ";
    for (auto task : current_month[day - 1])
    {
        cout << task << " ";
    }
    cout << endl;
}

void Next(int &i_month, vector<vector<string>> &current_month, vector<int> &days_in_months)
{
    // vector<vector<string>> current_month_copy = current_month;
    ++i_month;
    if (i_month > 11)
    {
        i_month = 0;
    }
    if (days_in_months[i_month] < current_month.size())
    {
        for (size_t day = days_in_months[i_month] - 1; day <= current_month.size() - 1; day++)
        {
            for (auto task : current_month[day])
            {
                if (!TaskExist(task, current_month[days_in_months[i_month] - 1]))
                {
                    current_month[days_in_months[i_month] - 1].push_back(task);
                }
            }
        }
    }
    current_month.resize(days_in_months[i_month]);
}

int main(int argc, char const *argv[])
{
    vector<int> days_in_months(12);
    days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i_month = 0;
    vector<vector<string>> current_month(days_in_months[i_month]);

    struct input
    {
        string command;
        int day;
        string task;
    };

    int nr_of_operations;
    cin >> nr_of_operations;

    vector<input> commands(nr_of_operations);
    string text_line;
    getline(cin, text_line);

    for (size_t i = 0; i < nr_of_operations; i++)
    {
        getline(cin, text_line);
        istringstream my_stream(text_line);
        while (my_stream >> commands[i].command)
        {
            if (commands[i].command == "ADD")
            {
                my_stream >> commands[i].day;
                my_stream >> commands[i].task;
            }
            if (commands[i].command == "DUMP")
            {
                my_stream >> commands[i].day;
            }
        }
        //        if (commands[nr_of_operations].command == "ADD"){
        //            cin >> commands[nr_of_operations].day;
        //            cin >> commands[nr_of_operations].task;
        //        }
        //        if (commands[nr_of_operations].command == "DUMP"){
        //            cin >> commands[nr_of_operations].day;
        //        }
    }

    for (auto command : commands)
    {
        if (command.command == "ADD")
        {
            Add(command.day, command.task, current_month);
        }
        if (command.command == "DUMP")
        {
            Dump(command.day, current_month);
        }
        if (command.command == "NEXT")
        {
            Next(i_month, current_month, days_in_months);
        }
    }

    return 0;
}
