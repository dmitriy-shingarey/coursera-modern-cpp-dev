#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<string, int> Command = {{"Add",1},{"Del",2},{"Find",3},{"Print",4}};

class Date {
public:
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;

    void NewDate(int & year_,int & month_,int & day_){
    year = year_;
    month = month_;
    day = day_;
  }
  private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs){
    return lhs < rhs;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event){
    //cout << date.GetDay() << endl;
    //set<string> myset;
    //myset.insert(event);
    if (Database::db.find(date) == Database::db.end())
    {
      Database::db[date] = "test";
    }
     //event;
  }
  bool DeleteEvent(const Date& date, const string& event);
  int  DeleteDate(const Date& date);

  /* ??? */ //Find(const Date& date) const;
  
  void Print() const;

  private:
    std::map<Date, std::string> db; 
};

int main() {
  Database db;
    
    string command;
  
  cout << "Enter command: " << endl;

  while (getline(cin, command)) {
    istringstream ss_command(command);
    string c;
    ss_command >> c;
    switch (Command[c])
    {
    case 1:  // add date to databse
      int year =0;
      int month=0;
      int day=0;
      ss_command >> year;
      ss_command.ignore(1);
      ss_command >> month;
      ss_command.ignore(1);
      ss_command >> day;
      Date date;
      date.NewDate(year, month, day);
      //ValidateAndCreateDate(ss_command,date);
      ss_command.ignore(1);
      string event = "";
      ss_command >> event;
      db.AddEvent(date, event);
      //break; 
      
   //   default:{
   //   cout << "Unknown command: " + c << endl;
   //   cout << "Enter command: " << endl;
   //   break;
   // }
    }
    }

  return 0;
}