#include <iostream>

#include "Hero.hpp"
#include "Ashbringer.hpp"
#include "ChainMail.hpp"

using namespace std;

int main() {

  Ashbringer a(20);
  ChainMail c(30);

  Hero hero(&a, &c);
  hero.takeDamage(5);
  hero.dealDamage();
  hero.print();
  return 0;
}
