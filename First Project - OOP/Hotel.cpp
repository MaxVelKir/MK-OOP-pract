#include "Hotel.h"

Hotel::Hotel() {
    curr = 0;
    size = 5;
    rooms = new Room[size];
}

Hotel::Hotel(const Hotel &temp) {
    size = temp.size;
    curr = temp.curr;

    rooms = new Room[size];

    for (int i = 0; i < curr; ++i) {
        rooms[i] = temp.rooms[i];
    }
}

Hotel::~Hotel() {
    delete [] rooms;
}

Room& Hotel::getExactRoom(int _number) {
    for (int i = 0; i < curr; ++i) {
        if(_number == rooms[i].getNumber())
            return rooms[i];
    }
    std::cerr << "Missing room." << std::endl;
}

int Hotel::getCurr() const {
    return curr;
}

void Hotel::addRoom(Room const &temp) {
    if (curr == size) {
        Room *arr = new Room[size + 5];
        for (int i = 0; i < size; ++i) {
            arr[i] = rooms[i];
        }
        delete []rooms;

        size += 5;
        rooms = arr;
    }

    rooms[curr++] = temp;
}

void Hotel::checkInRoom(int number, Date const &In, Date const &Out, const char* note) {

    for (int i = 0; i < curr; ++i) {
        if(number == rooms[i].getNumber()) {
            rooms[i].getIn() = In;
            rooms[i].getOut() = Out;
            rooms[i].setNote(note);
        }
    }
}

void Hotel::checkOutRoom(int number) {
    bool isCheckedIn = false;
    for (int i = 0; i < curr; ++i) {
        if(number == rooms[i].getNumber()) {
            isCheckedIn = true;
            rooms[i].getIn().setDateCheckOut();
            rooms[i].getOut().setDateCheckOut();
            rooms[i].setNote("\0");
        }
    }
    if(!isCheckedIn)
        std::cerr << "Room isn't checked in." << std::endl;
}

Room& Hotel::operator[](int i) {
    return rooms[i];
}

std::ostream& operator<<(std::ostream& o, Hotel const &temp) {
    for (int i = 0; i < temp.curr; ++i) {
       o << temp.rooms[i] << std::endl;
    }
    return o;
}

Hotel& Hotel::operator=(Hotel const &temp) {
    if(this != &temp) {
        delete [] rooms;

        size = temp.size;
        curr = temp.curr;

        rooms = new Room[size];

        for (int i = 0; i < curr; ++i) {
            rooms[i] = temp.rooms[i];
        }
    }
    return *this;
}

void Hotel::save() {
    std::ofstream file_out ("Hotel_Database.txt", std::ios::out);

    file_out << *this;

    file_out.close();
}
