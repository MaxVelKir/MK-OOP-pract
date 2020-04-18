#ifndef HOMEWORK_2_CHALLENGES_H
#define HOMEWORK_2_CHALLENGES_H

#include "Challenge.h"
#include <iostream>
#include <cstring>

class Challenges {
    Challenge *challenges;
    int curr = 0;
    int size;
public:
    Challenges();
    Challenges(Challenges const &);
    ~Challenges();

    int getCurr();
    Challenge& getChallenge(int);
    Challenge& getCurrChallenge();
    Challenge& getChallenge(const char*);

    void push(Challenge &);
    void print();

    Challenges& operator=(Challenges const &);
};


#endif //HOMEWORK_2_CHALLENGES_H
