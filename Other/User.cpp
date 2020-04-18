#include "User.h"

User::User(const char * _name, const char * _email, int _age) : age(_age), name(nullptr){
    if(_name) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    strcpy(email, _email);

    if(age > 90 || age < 1)
        std::cerr << "Invalid age";

    curr = 0;
    size = 1;
    challenges = new Challenge[size];
}

User::User(User const &temp) : age(temp.age), size(temp.size), curr(temp.curr) {
    if(temp.name) {
        name = new char[strlen(temp.name) + 1];
        strcpy(name, temp.name);
    }

    strcpy(email, temp.email);

    challenges = new Challenge[size];
    for (int i = 0; i < curr; ++i) {
        challenges[i] = temp.challenges[i];
    }
}

User::~User() {
    delete [] name;
    delete [] challenges;
}

char* User::getName() {
    return name;
}

void User::push(const Challenge &temp) {
    if(curr == size) {
        Challenge *arr = new Challenge[size++];

        for (int i = 0; i < curr; ++i) {
            arr[i] = challenges[i];
        }

        delete [] challenges;

        size++;
        challenges = arr;
    }

    challenges[curr++] = temp;
}

void User::remove(const char *_name) {
    for (int i = 0; i < curr; ++i) {
        if(strcmp(challenges[i].getName(), _name) == 0) {
            Challenge *arr = new Challenge[size];
            for (int j = 0; j < curr; ++j) {
                if(i != j)
                    arr[j] = challenges[j];
            }
            delete [] challenges;
            challenges = arr;
        }
    }
}

User& User::operator=(User const &temp) {
    if(this != &temp) {
        delete[] name;
        delete[] challenges;

        curr = temp.curr;
        size = temp.size;
        strcpy(email, temp.email);
        age = temp.age;

        if (temp.name) {
            name = new char[strlen(temp.name) + 1];
            strcpy(name, temp.name);
        }

        challenges = new Challenge[size];
        for (int i = 0; i < curr; ++i) {
            challenges[i] = temp.challenges[i];
        }
    }
     return *this;
}

void User::print() {
    std::cout << "Name: " << name << '\n'
              << "Email: " << email << '\n'
              << "Age: " << age << '\n';
}
