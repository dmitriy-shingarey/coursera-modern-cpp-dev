/* find mass of sublocks with different densities 
Input:
2 14
1 2 3
30 40 50

Output:
840084
*/

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <numeric>

using namespace std;

vector<int> FindVolumes(const vector<vector<int>> & blocks){
    vector<int> volumes;
    for (auto block : blocks){
        int volume = 1;
        for (auto side : block){
            volume *= side;
        }
        volumes.push_back(volume);
    }
    return volumes;
}

void FindMass(const int & density, const vector<int> & volumes){
    int mass = 0;
    for (auto volume : volumes)
    {
        mass += (volume*density);
    }
    cout << mass << endl;
}

int main() {
    int number_of_blocks;
    int density;
    vector<vector<int>> blocks;

    for (int i = 0; i < 1; i++)
    {
         cin >> number_of_blocks;
         cin >> density;     
    }
    int side_size;
    for (int i = 0; i < number_of_blocks; i++)
    {
        vector<int> block;
        for (int i = 0; i < 3; i++){
            cin >> side_size;
            block.push_back(side_size);
        }
        blocks.push_back(block);
    }

    
    vector<int> volumes = FindVolumes(blocks);
    FindMass(density, volumes);

}