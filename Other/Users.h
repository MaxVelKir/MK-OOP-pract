#ifndef HOMEWORK_2_USERS_H
#define HOMEWORK_2_USERS_H

#include "User.h"
#include <cstring>

class Users {
    User *users;
    int curr;
    int size;
    int *ids;
    int id;
public:
    Users();
    Users(Users const &);
    ~Users();

    int getId(const char*);
    User& getUser(const char*);
    User& getUser(int);

    void push(User const &);
    bool check(const char*);

    Users& operator=(Users const &);
};


#endif //HOMEWORK_2_USERS_H
