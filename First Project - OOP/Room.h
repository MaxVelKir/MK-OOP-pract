#ifndef HOTEL_PROJECT_ROOM_H
#define HOTEL_PROJECT_ROOM_H
#include <cstring>
#include <iostream>

#include "Date.h"

const int MAX_L = 32;

class Room {
    int number;
    int beds;
    char note[MAX_L];

    Date In;
    Date Out;
public:
    Room();
    Room(int, int);

    int getNumber() const;
    int getBeds() const;
    Date &getIn();
    Date &getOut();

    void setNote(const char*);

    friend std::ostream& operator<<(std::ostream&, Room const &);

    bool Availability(Date  &);
};




#endif //HOTEL_PROJECT_ROOM_H
