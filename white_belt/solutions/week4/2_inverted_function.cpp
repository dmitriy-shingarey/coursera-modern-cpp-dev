#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class FunctionPart
{
private:
    char operation;
    double value;
public:
    FunctionPart(char new_operation, double new_value){
        operation = new_operation;
        value = new_value;
    };

    double Apply(const double & new_source){
        if (operation == '+')
        {
            value = new_source + value;
        }
        else if (operation == '-')
        {
            value = new_source - value;
        } 
        else if (operation == '*')
        {
            value = new_source*value;
        } 
        else if (operation == '/')
        {
            if (value != 0){
                value = new_source/value;
            }
        } 
        return value;
    }

    void Invert(){
        if (operation == '+')
        {
            operation == '-';
        }
        else if (operation == '-')
        {
            operation == '+';
        } 
        else if (operation == '*')
        {
            operation == '/';
        } 
        else if (operation == '/')
        {
            operation == '*';
        } 
    }
};

class Function
{
private:
    vector<FunctionPart> parts;
public:

    void AddPart(const char & operation, const double & value){
        parts.push_back({operation,value});
    }
    double Apply(double value){
        for (auto & part:parts)
        {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert(){
        for (auto & part:parts){
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    }
};

int main() {
  Function myFunction;
  myFunction.AddPart('-', 10);
  myFunction.AddPart('+', 30);
  myFunction.AddPart('*', 2);
  myFunction.AddPart('/', 4);
  //myFunction.Invert();
  cout << myFunction.Apply(100) << endl;
  return 0;
}
