#include "Location.h"
Location::Location(int _section, int _shelf, int _number, int _volume) : section(_section), shelf(_shelf), number(_number), volume(_volume) {}



int Location::getSection() {
    return section;
}

int Location::getShelf() {
    return shelf;
}

int Location::getNumber() {
    return number;
}

int Location::getVolume() {
    return volume;
}

void Location::setLocation(int _section, int _shelf, int _number, int _volume) {
    section = _section;
    shelf = _shelf;
    number = _number;
    volume = _volume;
}

void Location::removeVolume(int _volume) {
    volume -= _volume;
}

ostream &operator<<(ostream &o, const Location &temp) {
    return o << temp.section << '.' << temp.shelf << '.' << temp.number << " - " << temp.volume;
}
