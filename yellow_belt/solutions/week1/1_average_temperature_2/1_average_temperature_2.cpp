#include <vector>
#include <iostream>

using namespace std;

int64_t FindAverage(const vector<int64_t> & temperatures){
    int64_t sum = 0;
    for (size_t i = 0; i < temperatures.size(); i++)
    {
        sum = sum + temperatures[i];
    }
    return  sum / static_cast<int64_t>(temperatures.size());
}

void FindOverAverage(const vector<int64_t> & temperatures){

    int64_t average = FindAverage(temperatures);
    vector<size_t> indices;

    for (size_t i = 0; i < temperatures.size(); i++){
        if (temperatures[i] >= average)
        {
            indices.push_back(i);
        }
    }
    cout << indices.size() << endl;
    for (size_t i = 0; i < indices.size(); i++)
    {
        cout << indices[i] << " ";
    }

}

int main (){
    int number_of_days;
    vector<int64_t> temperatures;
    int64_t input;

    cin >> number_of_days;

    for (int i = 0; i < number_of_days; i++)
    {
         cin >> input;
         temperatures.push_back(input);
    }

    cout << "Average is: " << FindAverage(temperatures) << endl;

    FindOverAverage(temperatures);
}