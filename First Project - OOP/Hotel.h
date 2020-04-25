#ifndef HOTEL_PROJECT_HOTEL_H
#define HOTEL_PROJECT_HOTEL_H
#include <iostream>
#include <cstring>
#include <fstream>

#include "Room.h"
#include "Date.h"

class Hotel {
    int curr;
    int size;

    Room *rooms;
public:

    Hotel();
    Hotel(Hotel const &);
    ~Hotel();

    Room& getExactRoom(int);
    int getCurr() const;

    Hotel& operator=(Hotel const &);
    Room& operator[](int);

    friend std::ostream& operator<<(std::ostream& o, Hotel const &);

    void addRoom(Room const &);
    void checkInRoom(int, Date const &, Date const &, const char* = "\0");
    void checkOutRoom(int);
    void save();

};


#endif //HOTEL_PROJECT_HOTEL_H
