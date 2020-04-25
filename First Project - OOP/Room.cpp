#include "Room.h"

Room::Room() {
    number = 0;
    beds = 3;
    strcpy(note, "\0");
}

Room::Room(int _number, int _beds) : number(_number), beds(_beds) {
    if(beds <= 0 || beds > 5 || number <= 0)
        std::cerr << "Invalid room." << std::endl;
    strcpy(note, "\0");
}

int Room::getNumber() const {
    return number;
}

int Room::getBeds() const {
    return beds;
}

Date& Room::getIn() {
    return In;
}

Date& Room::getOut() {
    return Out;
}

void Room::setNote(const char* _note) {
    strcpy(note, _note);
}

std::ostream& operator<<(std::ostream& o, Room const &temp) {
    Date temp2;
    o << "Room: " << temp.number << '\n'
      << "Beds: " << temp.beds << '\n';
    if(!(temp2 == temp.In) && !(temp2 == temp.Out)) {
        o << temp.In;
        o << temp.Out;
    }
    else {
        o << "Dates not set." << '\n';
    }
    o << "Note: " << (strcmp(temp.note, "\0") == 0 ? "-" : temp.note) << std::endl;
    return o;
}

bool Room::Availability(Date &date) {
    return date > Out || In > date;
}