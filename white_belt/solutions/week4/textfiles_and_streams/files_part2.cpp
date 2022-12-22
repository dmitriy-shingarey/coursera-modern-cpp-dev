#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream file_in;
    ofstream file_out;
    string line;
    file_in.open("input.txt");
    file_out.open("output.txt");
    if (file_in.is_open() && file_out.is_open())
    {
        while (getline(file_in,line) )
        {
          file_out << line << "\n";
        }    
      }
    file_in.close();
    file_out.close();
    return 0;
}

