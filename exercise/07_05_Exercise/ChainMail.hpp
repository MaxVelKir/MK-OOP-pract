#ifndef __CHAINMAIL
#define __CHAINMAIL

#include "Armor.hpp"

class ChainMail : public Armor {
  int defence;
public:
  ChainMail(int = 0);
  int getDefence();
};


#endif
