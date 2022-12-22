#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream myfile;
    string line;
    myfile.open("input.txt");
    if (myfile.is_open())
    {
        while (getline(myfile,line) )
        {
          cout << line << '\n';
        }    }
    myfile.close();
    return 0;
}

