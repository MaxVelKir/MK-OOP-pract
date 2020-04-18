#include "Users.h"

Users::Users() {
    id = 100;
    curr = 0;
    size = 1;
    users = new User[size];
    ids = new int[size];
}

Users::~Users() {
    delete [] users;
    delete [] ids;
}

Users::Users(Users const &temp) : curr(temp.curr), size(temp.size) {
    users = new User[size];
    ids = new int[size];

    for (int i = 0; i < curr; ++i) {
        users[i] = temp.users[i];
        ids[i] = temp.ids[i];
    }
}

User& Users::getUser(const char* _name) {
    for (int i = 0; i < curr; ++i) {
        if(strcmp(users[i].getName(), _name) == 0)
            return users[i];
    }
    std::cerr << "User not found!";
}

User& Users::getUser(int _id) {
    for (int i = 0; i < curr; ++i) {
        if(ids[i] == _id)
            return users[i];
    }
    std::cerr << "User not found!";
}

int Users::getId(const char * _name) {
    for (int i = 0; i < curr; ++i) {
        if(strcmp(users[i].getName(), _name) == 0)
            return ids[i];
    }
    std::cerr << "Id not found!";
}

void Users::push(User const &temp) {
    if(curr == size) {
        User *arr = new User[size + 1];
        int *arr2 = new int[size + 1];

        for (int i = 0; i < curr; ++i) {
            arr[i] = users[i];
            arr2[i] = ids[i];
        }

        delete [] users;
        delete [] ids;

        size++;

        users = arr;
        ids = arr2;
    }

    users[curr] = temp;
    ids[curr++] = id++;
}

bool Users::check(const char* _name) {
    for (int i = 0; i < curr; ++i) {
        if(strcmp(users[i].getName(), _name) == 0)
            return true;
    }
    return false;
}

Users& Users::operator=(const Users &temp) {
    if(this != &temp) {
        delete[] users;
        delete[] ids;

        curr = temp.curr;
        size = temp.size;
        users = new User[size];
        ids = new int[size];

        for (int i = 0; i < curr; ++i) {
            users[i] = temp.users[i];
            ids[i] = temp.ids[i];
        }
    }
    return *this;
}