/* given a string.
   find second appearance of the letter "f" in that strinf and print an index.

Inputs: 
    string 
Outputs:
    - print index of the second appearance
    - if no second appearance print:
         -1 if "f" appears only once
         -2 if "f" does not appear
     */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
       
    string input_string;
    cout << "Enter word: ";
    cin >> input_string;

    int counter=0;
    int index=-2;


    for (int i=0; i<input_string.size(); ++i)
    {
        if (input_string[i] == 'f')
        {
            counter=counter+1;
            index=i;
        }   
    }

    if (counter==2) 
    {
        cout << "Index of the second appearance is: " << index << endl;
    }
    if (counter==1) 
    {
       cout << "-1" << endl;
    }
    if (counter==0) 
    {
       cout << "-2" << endl;
    }    
}