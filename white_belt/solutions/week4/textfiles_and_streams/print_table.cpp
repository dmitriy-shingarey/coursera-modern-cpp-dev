#include<fstream>
#include <iostream>
#include <sstream>  
#include <iomanip>  

using namespace std;


int main(int argc, char const *argv[])
{
    ifstream input("input.txt");
    string line;
    int rows, columns;

    if (input) {
        getline(input, line);
        stringstream ss(line);
        ss >> rows >> columns;
        int k = 0;
        while (getline(input, line)){
                stringstream ss(line);
                string str;
                cout << setfill(' ');
               for (size_t i = 0; i < columns; i++)
                {
                    getline(ss, str, ',');
                    cout << setw(10) << str;
                    if ((i>=0) && (i<(columns-1))){
                        cout << " ";
                    }

                } 
                k = k + 1;
                if (k < rows) {
                    cout << endl;
                }    
        }
    }
    return 0;
}
