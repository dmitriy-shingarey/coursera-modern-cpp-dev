/* */

#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int main() {
    vector<string> queue;
    string operation;
    int number_of_operations;
    int op_number = 0;
    cout << "Enter number of operations: ";
    cin >> number_of_operations;
    for (size_t i = 0; i < number_of_operations; i++)
    {
        cin >> operation >> op_number;
        if (operation == "WORRY_COUNT"){
            auto ii = 0;
            for (auto que : queue)
            {
                if (que == "WORRY")
                {
                    ++ii;
                }
                
            }
            cout << ii << endl;
        }
        else if (operation == "COME")
        {
            queue.resize(queue.size()+op_number,"QUIET");
        }
        else if (operation == "WORRY")
        {
            queue[op_number] = "WORRY";
        }
        else if (operation == "QUIET")
        {
            queue[op_number] = "QUIET";
        }
    }
    return 0;
}