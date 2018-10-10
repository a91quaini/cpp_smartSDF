#include <module1/mod1c1.hpp>
#include <module1/mod1c2.hpp>
#include <module2/mod2c1.hpp>
#include <module2/mod2c2.hpp>

int main (void)
{
   mod1c1 m1c1;
   mod1c2 m1c2;
   mod2c1 m2c1;
   mod2c2 m2c2;
   
   std::cout << "Program\n";
   std::cout << "=======\n";
   m1c1.foo();
   m1c2.foo();
   m2c1.foo();
   m2c2.foo();
}
