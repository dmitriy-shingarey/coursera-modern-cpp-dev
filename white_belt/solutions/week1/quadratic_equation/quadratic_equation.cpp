/* solve quadratic equation for real roots*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    double A, B, C;
    vector<double> roots;
    cin >> A >> B >> C;
    // scale coefficients
    if (A!=1){
        B=B/A;  
        C=C/A;
        A=1;
    }
    // check if roots are real
    if ((B/2)*(B/2)<C) {
        cout << endl;
    }
    // calculate solutions of the quadratic equation
    else {
        double add = sqrt((B/2)*(B/2)-C);
        roots= {-B/2.0+add, -B/2.0-add};
        cout << roots[0] << " " << roots[1] << endl;
    }
    return 0;
}
