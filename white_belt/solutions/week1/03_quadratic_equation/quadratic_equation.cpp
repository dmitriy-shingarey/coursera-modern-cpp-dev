/* solve quadratic equation for real roots*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<float> find_roots(const float &A, const float &B, const float &C)
{
    // find descriminant
    auto D = (B * B - 4 * A * C);

    // if no solutions return empty vector
    if (((A == 0) && (B == 0)) || (D < 0))
    {
        return {};
    }

    if (A != 0)
    {
        if (D != 0)
        {
            if (D > 0)
            {
                auto x1 = (-B + sqrt(D)) / (2 * A);
                auto x2 = (-B - sqrt(D)) / (2 * A);
                return {x1, x2};
            }
        }
        // if D == 0
        else
        {
            return {-B / (2 * A)};
        }
    }
    // if A == 0
    else if (B != 0)
    {
        return {(-C / B)};
    }
}

int main()
{
    float A, B, C;
    cin >> A >> B >> C;
    auto roots = find_roots(A, B, C);
    for (auto root : roots)
    {
        cout << root << ' ';
    }
    cout << endl;
    return 0;
}
