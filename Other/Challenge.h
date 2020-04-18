#ifndef HOMEWORK_2_CHALLENGE_H
#define HOMEWORK_2_CHALLENGE_H

#include <iostream>
#include <cstring>

const int MAX_L_C = 31;

class Challenge {
    char name[MAX_L_C];
    char status[15];
    int timesUsed;
    float* rating;
    int size;
    int curr;
public:
    Challenge(const char* = "\0", const char* = "new", int = 1, float = 0);
    Challenge(Challenge const &);
    ~Challenge();

    char* getName();
    int getTimesUsed();
    void setRating(float);

    void oneUpTimesUsed();
    void print();

    Challenge& operator=(Challenge const &);
};


#endif //HOMEWORK_2_CHALLENGE_H
