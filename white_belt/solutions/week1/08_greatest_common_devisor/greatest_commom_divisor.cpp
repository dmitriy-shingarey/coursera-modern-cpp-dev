/* find Greatest Common Divisor (GCD) of two numbers */

#include <iostream>

int euclid(int A, int B)
{
   while ((A > 0) && (B > 0))
   {
      if (A > B)
      {
         A = A % B;
      }
      else
      {
         B = B % A;
      }
   }
   return A + B;
}

int main()
{

   int A, B;
   std::cin >> A >> B;

   std::cout << euclid(A, B) << std::endl;

   return 0;
}
