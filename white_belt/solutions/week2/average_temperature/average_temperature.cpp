/* find day temperatures above average 
Input: 
    N: number of measurements. Temperature for a day
    values: measurement values
Output: 
    K: number of days with temperature above average
    numbers: days numbers  */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int Average(const vector<int>& v){
    auto n = v.size();
    return accumulate(v.begin(), v.end(), 0)/n; 
}

void PrintDaysAboveAverage(const vector<int>& v){
    auto av = Average(v);
    vector<int> indices;
    int i = 0;
    for (auto el : v)
    {
        if (el > av)
        {
            indices.push_back(i);
        }   
        ++i;
    }
    cout << indices.size() << endl;
    for (auto ind : indices)
    {
        cout << v[ind] << " "; 
    }  
} 

int main() {
    int vector_size; 
    cout << "Enter number of vector elements: ";
    cin >> vector_size;
    vector<int> day_temperatures(vector_size);
    auto i=0;
    for (int& day : day_temperatures)
    {
        cout << "Enter temperature for day " << i+1 << ": ";
        cin >> day;
        ++i;
    }
    PrintDaysAboveAverage(day_temperatures);

    return 0;
}