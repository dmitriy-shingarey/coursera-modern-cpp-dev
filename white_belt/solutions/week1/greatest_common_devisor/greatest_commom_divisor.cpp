/* find Greatest Common Divisor (GCD) of two numbers */

#include <iostream>

using namespace std;

int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
} 

int main()
{
    int A, B;
    cout << "Enter A and B: ";
    cin >> A >> B;

    cout << gcd(A,B) << endl;
    
    return 0; 
}
