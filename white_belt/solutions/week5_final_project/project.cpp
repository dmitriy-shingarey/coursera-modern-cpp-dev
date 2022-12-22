#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<string, int> Command = {{"Add",1},{"Del",2},{"Find",3},{"Print",4}};

class Date {
public:
  int GetYear() const{
      return year;
  }
  int GetMonth() const{
     return month;
  }
  int GetDay() const{
     return day;
  }

  void NewDate(int year_, int month_, int day_) {
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
  vector<int> lhs_key{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
  vector<int> rhs_key{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
  return (lhs_key < rhs_key);
}

class Database {
public:
  void AddEvent(const Date& dato, const string& event){
    db[dato].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event){
    auto N =  db.at(date).size();
    cout << "Size is: " << N << endl;
    if (N > 0 )
    {
      if (event.size() != 0)
        {
          db.at(date).erase(event);
          cout << "Deleted successfully." << endl;
          return true;
        }
      else
      {
        db.erase(date);
        cout << "Deleted " + to_string(N)+ " events." << endl;
        return true;
      } 
    }
    else {
        cout << "Event not found" << endl;
        return false;
    }    
  }

  void Find(const Date& date) const{
    for (auto event : db.at(date))
    {
      cout << event << endl;
    }
    
  }
  
  void Print() const{
    for (auto i : db)
    {
      for (auto event : i.second)
      {
        cout  << i.first.GetYear() << "-"
              << i.first.GetMonth() << "-"
              << i.first.GetDay() << " "
              << event <<endl;
      }  
    }
  }

private:
   std::map<Date, set<string>> db; 
};

void ValidateAndCreateDate(istream & ss_command, Date & date){
    int year;
    int month = 0;
    int day = 0;
    if (ss_command >> year){
      ss_command.ignore(1);
      if (ss_command >> month){
        if (month < 1 || month > 12){
            cout << "Month value is invalid: " + to_string(month) << endl;
            exit(3);
        }
        ss_command.ignore(1);
        if (ss_command >> day){
               if (day<1 || day > 31)
                {
                  cout << "Day value is invalid: " + to_string(day) << endl;
                  exit(3);
                }
            date.NewDate(year, month, day);
        } 
      }
      else {
        cout << "Wrong date format." << endl;
      }
    }
}

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
    case 1: { // add date to databse
      Date date;
      ValidateAndCreateDate(ss_command,date);
      ss_command.ignore(1);
      string event = "";
      ss_command >> event;
      if (event.size() != 0){
        db.AddEvent(date, event);
      }
      break; 
      }
    case 2: { // add date to databse
      Date date;
      ValidateAndCreateDate(ss_command, date);
      ss_command.ignore(1);
      string event = "";
      ss_command >> event;
      cout << "Deleting event(s): " << endl;
      db.DeleteEvent(date, event);
      break; 
      }
    case 3: { // find events for a date
      Date date;
      ValidateAndCreateDate(ss_command, date);
      cout << "Searching for event(s): " << endl;
      db.Find(date);
      break; 
      }
    case 4: { // print all dates and events
      db.Print();
      break; 
      }
    default:{
      cout << "Unknown command: " + c << endl;
      cout << "Enter command: " << endl;
      break;
    }
    }
  }

  return 0;
}
