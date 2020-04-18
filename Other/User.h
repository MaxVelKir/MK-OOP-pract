#ifndef HOMEWORK_2_USER_H
#define HOMEWORK_2_USER_H

#include "Challenge.h"
#include <iostream>
#include <cstring>

const int MAX_L = 100;

class User {
    char *name;
    char email[MAX_L];
    int age;
    Challenge *challenges;
    int curr;
    int size;
public:
    User(const char* = nullptr, const char* = "\0", int = 1);
    User(User const &);
    ~User();

    char* getName();

    void push(Challenge const &);
    void remove(const char*);
    void print();

    User& operator=(User const &);
};


#endif //HOMEWORK_2_USER_H
