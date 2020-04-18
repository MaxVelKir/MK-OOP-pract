#include <iostream>
#include <fstream>

using namespace std;

#include "User.h"
#include "Users.h"
#include "Challenges.h"
#include "Challenge.h"

void registration(Users &users) {
    char name[MAX_L];
    char email[MAX_L];
    int age;
    cin >> name >> age >> email;

    User a(name, email, age);
    users.push(a);
}

void challenge(Users &users, Challenges &challenges) {
    char enter[1000];
    cin.ignore();
    cin.getline(enter, 1000);

    char word[MAX_L_C];
    for (char & k : word) {
        k = '\0';
    }

    int counter = 0;
    int wordCounter = 0;

    for (int i = 0; i <= strlen(enter); i++) {
        if(enter[i] == ' ' && wordCounter == 0) {
            if (!users.check(word)) {
                cerr << "User missing!" << endl;
                break;
            }
            else {
                for (int j = 0; j < counter; ++j) {
                    word[j] = '\0';
                }
                counter = 0;
                wordCounter++;
                i++;
            }
        }
        else if (enter[i] == ' ' && wordCounter == 1) {
            if(word[0] != '#' || counter > 31) {
                cerr << "Invalid challenge!" << endl;
                break;
            }
            else {
                Challenge a(word);
                challenges.push(a);

                for (int j = 0; j < counter; ++j) {
                    word[j] = '\0';
                }

                counter = 0;
                wordCounter++;
                i++;
            }
        }
        else if ((i == strlen(enter) || enter[i] == ' ') && wordCounter > 1) {
            if (!users.check(word)) {
                cerr << "User missing!" << endl;
                break;
            }
            else {
                users.getUser(word).push(challenges.getCurrChallenge());

                for (int j = 0; j < counter; ++j) {
                    word[j] = '\0';
                }

                counter = 0;
                wordCounter++;
                i++;
            }
        }
        word[counter++] = enter[i];
    }
}

void finish(Users &users, Challenges &challenges) {
    char challenge[MAX_L_C];
    int id;
    float rating;
    cin >> challenge >> id >> rating;
    users.getUser(id).remove(challenge);
    challenges.getChallenge(challenge).setRating(rating);
}

void profile_info(Users &users) {
    char name[MAX_L];
    cin.ignore();
    cin.getline(name, MAX_L);
    users.getUser(name).print();
    cout << "Id: " << users.getId(name) << endl;
}

void list_by(Challenges &challenges) {
    char how[12];
    cin >> how;

    if (strcmp(how, "newest") == 0) {
        bool isSorted = false;
        do {
            isSorted = true;

            for (int i = challenges.getCurr() - 1; i > 0; --i) {
                if(challenges.getChallenge(i) < challenges.getChallenge(i - 1)) {
                    Challenge temp(challenges.getChallenge(i - 1));
                    challenges.getChallenge(i - 1) = challenges.getChallenge(i);
                    challenges.getChallenge(i) = temp;
                    isSorted = false;
                }
            }
        }
        while (!isSorted);
        challenges.print();
    }

    else if (strcmp(how, "oldest") == 0) {
        bool isSorted = false;
        do {
            isSorted = true;

            for (int i = challenges.getCurr() - 1; i > 0; --i) {
                if(challenges.getChallenge(i) > challenges.getChallenge(i - 1)) {
                    Challenge temp(challenges.getChallenge(i - 1));
                    challenges.getChallenge(i - 1) = challenges.getChallenge(i);
                    challenges.getChallenge(i) = temp;
                    isSorted = false;
                }
            }
        }
        while (!isSorted);
        challenges.print();
    }

    else if (strcmp(how, "most_popular") == 0) {
        cerr << "This is literally just printing oldest?" << endl;
    }
}

void load(Users &users) {
    char load[10];
    cin >> load;
    ifstream file_in(load);
    int n;
    char name[MAX_L];
    char email[MAX_L];
    int age;
    file_in >> n;
    for (int i = 0; i < n; ++i) {
        file_in >> name;
        file_in >> age;
        file_in >> email;
        User a(name, email, age);
        users.push(a);
    }
    file_in.close();
}

void input(Users &users, Challenges &challenges) {
    char fInput[MAX_L];

    cin >> fInput;

    if(strcmp(fInput, "registration") == 0) {
        registration(users);
    }

    else if (strcmp(fInput, "challenge") == 0) {
        challenge(users, challenges);
    }

    else if (strcmp(fInput, "finish") == 0) {
        finish(users, challenges);
    }

    else if (strcmp(fInput, "profile_info") == 0) {
        profile_info(users);
    }

    else if (strcmp(fInput, "list_by") == 0) {
        list_by(challenges);
    }

    else if (strcmp(fInput, "load") == 0) {
        load(users);
    }

    else
        cerr << "Command not found." << endl;
}

int main() {
    Users users;
    Challenges challenges;

    while(true) {
        input(users, challenges);
    }

    return 0;
}
