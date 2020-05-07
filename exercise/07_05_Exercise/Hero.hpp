#ifndef __HERO
#define __HERO

#include <iostream>

#include "Armor.hpp"
#include "Weapon.hpp"

using namespace std;

class Hero {
  int health;
  int level;
  Armor* armor;
  Weapon* weapon;
public:
  Hero(Weapon*, Armor*);
  void equipWeapon(Weapon*);
  void equipArmor(Armor*);
  void takeDamage(int);
  void dealDamage();
  void print();
};



#endif
