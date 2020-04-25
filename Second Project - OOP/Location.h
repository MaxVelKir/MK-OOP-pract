#ifndef SKLAD_LOCATION_H
#define SKLAD_LOCATION_H

#include <iostream>

const int MAX_S_S_N = 10;
const int MAX_V = 50;

using namespace std;

class Location {
protected:
    int section;
    int shelf;
    int number;
    int volume;
public:
    Location(int = 1, int = 1, int = 1, int = 0);

    int getSection();
    int getShelf();
    int getNumber();
    int getVolume();
    void setLocation(int, int, int, int);
    void removeVolume(int);

    friend ostream& operator<<(ostream&, Location const &);
};


#endif //SKLAD_LOCATION_H
