#include "Hero.hpp"

Hero::Hero(Weapon* tempW, Armor* tempA) {
  health = 10;
  level = 1;
  equipWeapon(tempW);
  equipArmor(tempA);
}

void Hero::equipWeapon(Weapon* temp) {
  weapon = temp;
}

void Hero::equipArmor(Armor* temp) {
  armor = temp;
}

void Hero::takeDamage(int _dealtDamage) {
  cout << "You took " << (_dealtDamage - armor->getDefence() < 0 ? 0 : _dealtDamage - armor->getDefence())<< " damage!" << endl;
}

void Hero::dealDamage() {
  cout << "You dealt " << weapon->getAttack() << " damage!!!" << endl;
}

void Hero::print() {
  cout << health << ' ' << level << endl;
  cout << armor->getDefence() << ' ';
  cout << weapon->getAttack();
  cout << endl;
}
