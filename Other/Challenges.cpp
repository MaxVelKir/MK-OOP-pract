#include "Challenges.h"

Challenges::Challenges() {
    size = 1;
    challenges = new Challenge[size];
}

Challenges::Challenges(Challenges const &temp) : size(temp.size), curr(temp.curr) {
    challenges = new Challenge[size];
    for (int i = 0; i < curr; ++i) {
        challenges[i] = temp.challenges[i];
    }
}

Challenges::~Challenges() {
    delete [] challenges;
}

int Challenges::getCurr() {
    return curr;
}

Challenge& Challenges::getChallenge(int i) {
    return challenges[i];
}

Challenge& Challenges::getCurrChallenge() {
    return challenges[curr - 1];
}

Challenge& Challenges::getChallenge(const char* _name) {
    for (int i = 0; i < curr; ++i) {
        if(strcmp(challenges[i].getName(), _name) == 0) {
            return challenges[i];
        }
    }
}

void Challenges::push(Challenge &temp) {
    if(curr == size) {
        Challenge *arr = new Challenge[size + 1];

        for (int i = 0; i < curr; ++i) {
            arr[i] = challenges[i];
        }

        delete [] challenges;

        size++;
        challenges = arr;
    }

    if(curr > 0) {
        bool check = false;
        for (int j = 0; j < curr; ++j) {
            if (strcmp(temp.getName(), challenges[j].getName()) == 0) {
                challenges[j].oneUpTimesUsed();
                check = true;
                break;
            }
        }
        if(!check)
            challenges[curr++] = temp;
    }
    else
        challenges[curr++] = temp;
}

Challenges& Challenges::operator=(Challenges const &temp) {
    if(this != &temp) {
        delete [] challenges;

        size = temp.size;
        curr = temp.curr;

        challenges = new Challenge[size];

        for (int i = 0; i < curr; ++i) {
            challenges[i] = temp.challenges[i];
        }
    }
    return *this;
}

void Challenges::print() {
    for (int i = 0; i < curr; ++i) {
        challenges[i].print();
    }
}