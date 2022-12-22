/* calculate product price after discount
Inputs: 
    N, A, B, X, Y (A < B) 
    N - initial price
    X - discount if X > A
    Y - discount if X > B
Outputs:
    price after discount */

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double initial_price, A, B, A_discount, B_discount, discount_price;
    
    cout << "Enter Initial price: ";
    cin >> initial_price;
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter B: ";
    cin >> B;
    cout << "Enter discount for A: ";
    cin >> A_discount;
    cout << "Enter discount for B: ";
    cin >> B_discount;

    discount_price=initial_price;

    if (initial_price > A)
    {
        discount_price=initial_price*(1 - A_discount / 100.0);
    }
    
    if (initial_price > B)
    {
        discount_price=initial_price*(1 - B_discount / 100.0);
    }

    cout << "Price after discount: " <<  discount_price <<endl;

    return 0;
}
