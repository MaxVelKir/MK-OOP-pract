#ifndef __ASHBRINGER
#define __ASHBRINGER

#include "Weapon.hpp"

class Ashbringer : public Weapon {
  int attack;
public:
  Ashbringer(int = 0);
  int getAttack();
};


#endif
